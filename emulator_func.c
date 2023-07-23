#include "shell.h"

/**
 * _help - help function
 * @f_info: struct address
 * Return: 0
 */
int _help(info_t *f_info)
{
	char **argsv;

	argsv = f_info->argv;
	_puts("Help: function not implemented \n");
	if (0)
		_puts(*argsv);
	return (0);
}

/**
 * _history - gets the history the list
 * @f_info: struct address
 * Return: 0
 */
int _history(info_t *f_info)
{
	print_list(f_info->hist);
	return (0);
}

/**
 * _cd - changes direct
 * @f_info: struct address
 * Return: 0
 */
int _cd(info_t *f_info)
{
	char *str, *direct, buff[1024];
	int dir_ret;

	str = getcwd(buff, 1024);
	if (!str)
		_puts(": >> getcwd failure msg << \n");
	if (!f_info->argv[1])
	{
		direct = _getenv(f_info, "HOME=");
		if (!direct)
			dir_ret = chdir((direct = _getenv(f_info, "PWD=")) ? direct : "/");
		else
			dir_ret = chdir(direct);
	}
	else if (_strcmp(f_info->argv[1], "-") == 0)
	{
		if (!_getenv(f_info, "OLDPWD="))
		{
			_puts(str);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(f_info, "OLDPWD=")), _putchar('\n');
		dir_ret = chdir((direct = _getenv(f_info, "OLDPWD=")) ? direct : "/");
	}
	else
		dir_ret = chdir(f_info->argv[1]);
	if (dir_ret == -1)
	{
		print_err(f_info, "can't cd to ");
		_eputs(f_info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(f_info, "OLDPWD", _getenv(f_info, "PWD="));
		_setenv(f_info, "PWD", getcwd(buff, 1024));
	}
	return (0);
}

/**
 * _eexit - exits shell
 * @f_info: struct address
 * Return: exit with a status
 */
int _eexit(info_t *f_info)
{
	int exit_status;

	if (f_info->argv[1])
	{
		exit_status = error_atoi(f_info->argv[1]);
		if (exit_status == -1)
		{
			f_info->status = 2;
			print_err(f_info, "Invalid number: ");
			_eputs(f_info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		f_info->err_no = error_atoi(f_info->argv[1]);
		return (-2);
	}
	f_info->err_no = -1;
	return (-2);
}
