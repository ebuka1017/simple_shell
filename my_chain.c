#include "shell.h"

/**
 * rep_str - replaces string
 * @old_str: address of old str
 * @new_str: new string
 * Return: 1, 0
 */
int rep_str(char **old_str, char *new_str)
{
	free(*old_str);
	*old_str = new_str;
	return (1);
}

/**
 * rep_var - replaces variables
 * @f_info: struct address
 * Return: 1 on success, 0 otherwise
 */
int rep_var(info_t *f_info)
{
	int j = 0;
	list_t *current;

	for (j = 0; f_info->argv[j]; j++)
	{
		if (f_info->argv[j][0] != '$' || !f_info->argv[j][1])
			continue;
		if (!_strcmp(f_info->argv[j], "$?"))
		{
			rep_str(&(f_info->argv[j]),
				_strdup(_itoa(f_info->status, 10, 0)));
			continue;
		}
		if (!_strcmp(f_info->argv[j], "$$"))
		{
			rep_str(&(f_info->argv[j]),
				_strdup(_itoa(getpid(), 10, 0)));
			continue;
		}
		current = node_str_starts(f_info->env, &f_info->argv[j][1], '=');
		if (current)
		{
			rep_str(&(f_info->argv[j]),
				_strdup(_strchr(current->str, '=') + 1));
			continue;
		}
		rep_str(&f_info->argv[j], _strdup(""));
	}
	return (0);
}

/**
 * rep_alias - replaces an alias
 * @f_info: struct address
 * Return: 1 success, 0 ohterwise
 */
int rep_alias(info_t *f_info)
{
	int j;
	list_t *current;
	char *ptr;

	for (j = 0; j < 10; j++)
	{
		current = node_str_starts(f_info->alias, f_info->argv[0], '=');
		if (!current)
			return (0);
		free(f_info->argv[0]);
		ptr = _strchr(current->str, '=');
		if (!ptr)
			return (0);
		ptr = _strdup(ptr + 1);
		if (!ptr)
			return (0);
		f_info->argv[0] = ptr;
	}
	return (1);
}

/**
 * check_chain - checks if a chain is delimeter
 * @f_info: struct address
 * @buffer: buffer
 * @ptr: address of current position
 * Return: 1 true, 0 false
 */
int check_chain(info_t *f_info, char *buffer, size_t *ptr)
{
	size_t i = *ptr;

	if (buffer[i] == '|' && buffer[i + 1] == '|')
	{
		buffer[i] = 0;
		i++;
		f_info->cmd_buffer_type = 1;
	}
	else if (buffer[i] == '&' && buffer[i + 1] == '&')
	{
		buffer[i] = 0;
		i++;
		f_info->cmd_buffer_type = 2;
	}
	else if (buffer[i] == ';')
	{
		buffer[i] = 0;
		f_info->cmd_buffer_type = 3;
	}
	else
	{
		return (0);
	}
	*ptr = i;
	return (1);
}

/**
 * continue_chain - checks if we should continue chaining
 * @f_info: struct address
 * @buffer: buffer
 * @ptr: address of curr pos
 * @i: starting position
 * @size: size of buffer
 * Return: void
 */
void continue_chain(info_t *f_info, char *buffer, size_t *ptr, size_t i,
	size_t size)
{
	size_t idx = *ptr;

	if (f_info->cmd_buffer_type == 2)
	{
		if (f_info->status)
		{
			buffer[i] = 0;
			idx = size;
		}
	}
	if (f_info->cmd_buffer_type == 1)
	{
		if (!f_info->status)
		{
			buffer[i] = 0;
			idx = size;
		}
	}
	*ptr = idx;
}
