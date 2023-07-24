#include "shell.h"

/**
 * fork_my_cmd - forks a thred to run
 * @f_info: struct address
 * Return: nothing
 */
void fork_my_cmd(info_t *f_info)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(f_info->path, f_info->argv, 
				get_file_environ(f_info)) == -1)
		{
			free_info(f_info, 1);
			free_info(f_info, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
	}
	else
	{
		wait(&(f_info->status));
		if (WIFEXITED(f_info->status))
		{
			f_info->status = WEXITSTATUS(f_info->status);
			if (f_info->status == 126)
				print_err(f_info, "Permission denied\n");
		}
	}
}

/**
 * search_cmd - finds command
 * @f_info: struct address
 * Return: nothing
 */
void search_cmd(info_t *f_info)
{
	char *the_path = NULL;
	int i, k;

	f_info->path = f_info->argv[0];
	if (f_info->line_count_flag == 1)
	{
		f_info->line_count++;
		f_info->line_count_flag = 0;
	}
	for (i = 0, k = 0; f_info->arg[i]; i++)
		if (!is_delimeter(f_info->arg[i], " \t\n"))
			k++;
	if (!k)
		return;
	the_path = get_path(f_info, _getenv(f_info, "PATH="), 
			f_info->argv[0]);
	if (the_path)
	{
		f_info->path = the_path;
		fork_my_cmd(f_info);
	}
	else
	{
		if ((is_interactive(f_info) || _getenv(f_info, "PATH=")
			|| f_info->argv[0][0] == '/') && is_command(f_info, 
			f_info->argv[0]))
			fork_my_cmd(f_info);
		else if (*(f_info->arg) != '\n')
		{
			f_info->status = 127;
			print_err(f_info, "not found\n");
		}
	}
}

/**
 * hsh - shell loop
 * @f_info: struct address
 * @argv: argum vector
 * Return: 0 on success, 1 error
 */
int hsh(info_t *f_info, char **argv)
{
	ssize_t bytes_read = 0;
	int ret = 0;

	while (bytes_read != -1 && ret != -2)
	{
		clear_info(f_info);
		if (is_interactive(f_info))
			_puts("$ ");
		_eputchar(-1);
		bytes_read = _Input(f_info);
		if (bytes_read != -1)
		{
			set_info(f_info, argv);
			ret = search_builtin(f_info);
			if (ret == -1)
				search_cmd(f_info);
		}
		else if (is_interactive(f_info))
			_putchar('\n');
		free_info(f_info, 0);
	}
	write_hist(f_info);
	free_info(f_info, 1);
	if (!is_interactive(f_info) && f_info->status)
		exit(f_info->status);
	if (ret == -2)
	{
		if (f_info->err_no == -1)
			exit(f_info->status);
		exit(f_info->err_no);
	}
	return (ret);
}

/**
 * search_builtin - finds builtin commands
 * @f_info: struct address
 * Return: int
 */
int search_builtin(info_t *f_info)
{
	int i, ret = -1;
	builtin_table tbl[] = {
		{"exit", _eexit},
		{"env", _currenv},
		{"help", _help},
		{"history", _history},
		{"setenv", _mysetenv},
		{"unsetenv", _free_env},
		{"cd", _cd},
		{"alias", _alias},
		{NULL, NULL}
	};
	for (i = 0; tbl[i].type; i++)
		if (_strcmp(f_info->argv[0], tbl[i].type) == 0)
		{
			f_info->line_count++;
			ret = tbl[i].func(f_info);
			break;
		}
	return (ret);
}
