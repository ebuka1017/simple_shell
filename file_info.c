#include "shell.h"

/**
 * free_info - frees struct
 * @f_info: struct
 * @free_all: true if freeign all fields
 * Return: void
 */

void free_info(info_t *f_info, int free_all)
{
	ffree(f_info->argv);
	f_info->argv = NULL;
	f_info->path = NULL;

	if (free_all)
	{
		if (!f_info->cmd_buffer)
			free(f_info->arg);

		if (f_info->env)
			free_list(&(f_info->env));

		if (f_info->alias)
			free_list(&(f_info->alias));

		if (f_info->hist)
			free_list(&(f_info->hist));

		ffree(f_info->environ);
		f_info->environ = NULL;
		bfree((void **)f_info->cmd_buffer);

		if (f_info->readfd > 2)
			close(f_info->readfd);
		_putchar(-1);
	}
}

/**
 * clear_info - clears info_t struct
 * @f_info: address of struct
 * Return: void
 */
void clear_info(info_t *f_info)
{
	f_info->arg = NULL;
	f_info->argv = NULL;
	f_info->path = NULL;
	f_info->argc = 0;
}

/**
 * set_info - sets info_t struct
 * @f_info: struct address
 * @argsv: argument vector
 * Return: void
 */
void set_info(info_t *f_info, char **argsv)
{
	int count = 0;

	f_info->filename = argsv[0];

	if (f_info->arg)
	{
		f_info->argv = strtow(f_info->arg, " \t");
		if (!f_info->argv)
		{
			f_info->argv = malloc(sizeof(char *) * 2);
			if (f_info->argv)
			{
				f_info->argv[0] = _strdup(f_info->arg);
				f_info->argv[1] = NULL;
			}
		}
		for (count = 0; f_info->argv && f_info->argv[count]; count++)
			;
		f_info->argc = count;
		rep_alias(f_info);
		rep_var(f_info);
	}
}
