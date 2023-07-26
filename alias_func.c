#include "shell.h"

/**
 * remove_alias - removes the alias
 * @f_info: struct address
 * @s: string
 * Return: 0, 1
 */
int remove_alias(info_t *f_info, char *s)
{
	char *ptr, c;
	int to_return;

	ptr = _strchr(s, '=');
	if (!ptr)
		return (1);

	c = *ptr;
	*ptr = 0;
	to_return = delete_node(&(f_info->alias), get_node(f_info->alias,
			node_str_starts(f_info->alias, s, -1)));
	*ptr = c;
	return (to_return);
}

/**
 * put_alias - sets alias to string
 * @f_info: struct address
 * @s: string
 * Return: 0
 */
int put_alias(info_t *f_info, char *s)
{
	char *ptr;

	ptr = _strchr(s, '=');
	if (!ptr)
		return (1);
	if (!*++ptr)
		return (remove_alias(f_info, s));

	remove_alias(f_info, s);
	return (add_node_to_end(&(f_info->alias), s, 0) == NULL);
}

/**
 * my_print_alias - prints an alias
 * @node: alias node
 * Return: 0
 */
int my_print_alias(list_t *node)
{
	char *ptr = NULL, *temp = NULL;

	if (node)
	{
		ptr = _strchr(node->str, '=');
		for (temp = node->str; temp <= ptr; temp++)
			_putchar(*temp);
		_putchar('\'');
		_puts(ptr + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _alias - alias function
 * @f_info: struct address
 * Return: 0
 */
int _alias(info_t *f_info)
{
	int i = 0;
	char *ptr = NULL;
	list_t *node = NULL;

	if (f_info->argc == 1)
	{
		node = f_info->alias;
		while (node)
		{
			my_print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; f_info->argv[i]; i++)
	{
		ptr = _strchr(f_info->argv[i], '=');
		if (ptr)
			put_alias(f_info, f_info->argv[i]);
		else
			my_print_alias(node_str_starts(f_info->alias,
					f_info->argv[i], '='));
	}
	return (0);
}
