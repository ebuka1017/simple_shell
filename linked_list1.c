#include "shell.h"

/**
 * add_node - adds a node to list
 * @head: address of head node
 * @str: str field of node
 * @idx: node index
 * Return: pointer to the head
 */
list_t *add_node(list_t **head, const char *str, int idx)
{
	list_t *new_node;

	if (!head)
		return (NULL);
	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);
	_memset((void *)new_node, 0, sizeof(list_t));
	new_node->num = idx;
	if (str)
	{
		new_node->str = _strdup(str);
		if (!new_node->str)
		{
			free(new_node);
			return (NULL);
		}
	}
	new_node->next = *head;
	*head = new_node;
	return (new_node);
}

/**
 * add_node_to_end - adds a node to end of list
 * @head: head of list
 * @str: str field of node
 * @idx: index used by history
 * Return: pointer to the head
 */

list_t *add_node_to_end(list_t **head, const char *str, int idx)
{
	list_t *new, *temp;

	if (!head)
		return (NULL);
	temp = *head;
	new = malloc(sizeof(list_t));
	if (!new)
		return (NULL);
	_memset((void *)new, 0, sizeof(list_t));
	new->num = idx;
	if (str)
	{
		new->str = _strdup(str);
		if (!new->str)
		{
			free(new);
			return (NULL);
		}
	}
	if (temp)
	{
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
	else
		*head = new;
	return (new);
}

/**
 * print_str_list - prints str field of nodes
 * @head: pointer to head
 * Return: size of linked list
 */

size_t print_str_list(const list_t *head)
{
	size_t size = 0;

	while (head)
	{
		_puts(head->str ? head->str : "(nil)");
		_puts("\n");
		head = head->next;
		size++;
	}
	return (size);
}

/**
 * delete_node - deletes node at index
 * @head: head of list
 * @idx: index of node to be deleted
 * Return: 0 faild, 1 success
 */

int delete_node(list_t **head, unsigned int idx)
{
	list_t *current, *before_current;
	unsigned int i = 0;

	if (!head || !*head)
		return (0);

	if (!idx)
	{
		current = *head;
		*head = (*head)->next;
		free(current->str);
		free(current);
		return (1);
	}
	current = *head;
	while (current)
	{
		if (i == idx)
		{
			before_current->next = current->next;
			free(current->str);
			free(current);
			return (1);
		}
		i++;
		before_current = current;
		current = current->next;
	}
	return (0);
}

/**
 * free_list - frees nodes from linked list
 * @head: pointer to head
 * Return: nothing (void)
 */

void free_list(list_t **head)
{
	list_t *current, *after_current;
	list_t *hptr;

	if (!head || !*head)
		return;
	hptr = *head;
	current = hptr;
	while (current)
	{
		after_current = current->next;
		free(current->str);
		free(current);
		current = after_current;
	}
	*head = NULL;
}
