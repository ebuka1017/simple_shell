#include "shell.h"

/**
 * _set_file_env - initiates new env
 * @f_info: struct address
 * @var: string var env
 * @value: value of string env
 * Return: 0
 */
int _set_file_env(info_t *f_info, char *var, char value)
{
	char *buffer = NULL;
	list_t *node;
	char *ptr;

	if (!var || !value)
		return (0);

	buffer = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buffer)
		return (1);
	_strcpy(buffer, var);
	_strcat(buffer, "=");
	_strcat(buffer, value);
	node = f_info->env;

	while (node)
	{
		ptr = _starts_with(node->str, var);
		if (ptr && *ptr == '=')
		{
			free(node->str);
			node->str = buffer;
			f_info->changed_env = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_to_end(&(f_info->env), buffer, 0);
	free(buffer);
	f_info->changed_env = 1;
	return (0);
}

/**
 * get_file_environ - returns string array of env
 * @f_info: struct address
 * Return: 0
 */
char **get_file_environ(info_t *f_info)
{
	if (!f_info->environ || f_info->changed_env)
	{
		f_info->environ = list_strings(f_info->env);
		f_info->changed_env = 0;
	}
	return (f_info->environ);
}

/**
 * _unset_file_env - unsets an environ
 * @f_info: struct address
 * @var: env var prop
 * Return: on delete 1, otherwise 0
 */
int _unset_file_env(info_t *f_info, char *var)
{
	list_t *node = f_info->env;
	size_t i = 0;
	char *ptr;

	if (!node || !var)
		return (0);

	while (node)
	{
		ptr = _starts_with(node->str, var);
		if (ptr && *ptr == '=')
		{
			f_info->changed_env = delete_node(&(f_info->env), i);
			i = 0;
			node = f_info->env;
			continue;
		}
		node = node->next;
		i++;
	}
	return (f_info->changed_env);
}
