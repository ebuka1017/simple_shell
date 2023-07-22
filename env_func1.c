#include "shell.h"

/**
 * _mysetenv - initiate an env
 * @f_info: struct address
 * Return: 0
 */
int _mysetenv(info_t *f_info)
{
	if (f_info->argc != 3)
	{
		_eputs("Incorrect arguments count\n");
		return (1);
	}
	if (_setenv(f_info, f_info->argv[1], f_info->argv[2]))
		return (0);
	return (1);
}

/**
 * _free_env - frees an env
 * @f_info: struct address
 * Return: 0
 */
int _free_env(info_t *f_info)
{
	int i;

	if (f_info->argc == 1)
	{
		_eputs("few arguments.\n");
		return (1);
	}
	for (i = 1; i <= f_info->argc; i++)
		_unsetenv(f_info, f_info->argv[i]);
	return (0);
}

/**
 * create_env_list - creates an env linked list
 * @f_info: struct address
 * Return: 0
 */
int create_env_list(info_t *f_info)
{
	list_t *node =NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_to_end(&node, environ[i], 0);
	f_info->env = node;
	return (0);
}

/**
 * _myenv - prints the current environ
 * @f_info: struct address
 * Return: 0
 */
int _currenv(info_t *f_info)
{
	print_str_list(f_info->env);
	return (0);
}

/**
 * _getenv - gets the env variable
 * @f_info: struct address
 * @env_name: env name
 * Return: value
 */
char *_getenv(info_t *f_info, const char *env_name)
{
	list_t *current = f_info->env;
	char *ptr;

	while (current)
	{
		ptr = _starts_with(current->str, env_name);
		if (ptr && *ptr)
			return (ptr);
		current = current->next;
	}
	return (NULL);
}
