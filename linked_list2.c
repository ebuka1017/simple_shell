#include "shell.h"

/**
 * len_list - return length of a linked list
 * @head: head of list
 * Return: size
 */
size_t len_list(const list_t *head)
{
	size_t size = 0;

	while (head)
	{
		head = head->next;
		size++;
	}
	return (size);
}

/**
 * list_strings - returns arr of nodes' str field
 * @head: head of the list
 * Return: array of strings
 */
char **list_strings(list_t *head)
{
	list_t *current = head;
	size_t size = len_list(head);
	size_t i;
	char **arr;
	char *str;

	if (!head || !size)
		return (NULL);
	arr = malloc(sizeof(char *) * (size + 1));
	if (!arr)
		return (NULL);
	for (size = 0; current; current = current->next, size++)
	{
		str = malloc(_strlen(current->str) + 1);
		if (!str)
		{
			for (i = 0; i < size; i++)
				free(arr[i]);
			free(arr);
			return (NULL);
		}
		str = _strcpy(str, current->str);
		arr[size] = str;
	}
	arr[size] = NULL;
	return (arr);
}

/**
 * print_list - prints all nodes of linked list
 * @head: head of list
 * Return: size of list
 */
size_t print_list(const list_t *head)
{
	size_t size = 0;

	while (head)
	{
		_puts(_itoa(head->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(head->str ? head->str : "(nil)");
		_puts("\n");
		head = head->next;
		size++;
	}
	return (size);
}

/**
 * node_str_starts - returns node whose string has str
 * @head: head of list
 * @str: string to match
 * @c: the char after prefix to match
 * Return: matched node or null otherwise
 */
list_t *node_str_starts(list_t *head, char *str, char c)
{
	char *ptr = NULL;

	while (head)
	{
		ptr = _starts_with(head->str, str);
		if (ptr && ((c == -1) || (*ptr == c)))
			return (head);
		head = head->next;
	}
	return (NULL);
}

/**
 * get_node - gets the index of node
 * @head: head of list
 * @node: pointer to node
 * Return: idx of node, -1 on failure
 */
ssize_t get_node(list_t *head, list_t *node)
{
	size_t idx = 0;

	while (head)
	{
		if (head == node)
			return (idx);
		head = head->next;
		idx++;
	}
	return (-1);
}
