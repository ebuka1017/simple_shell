#include "shell.h"

/**
 * ffree - frees an array of strings
 * @ss: array of strings
 * Return: void
 */

void ffree(char **ss)
{
	char **target = ss;

	if (!ss)
		return;
	while (*ss)
		free(*ss++);
	free(target);
}

/**
 * bfree - frees memory and fills address with NULLS
 * @p: pointer to the memory
 * Return: 1 on success, 0 on failure
 */

int bfree(void **p)
{
	if (p && *p)
	{
		free(*p);
		*p = NULL;
		return (1);
	}
	return (0);
}

/**
 * _realloc - reallocates memory
 * @mem: pointer to memory block
 * @prev_size: size of previous block
 * @new_size: size of new block
 * Return: pointer to new block
 */

void *_realloc(void *mem, unsigned int prev_size, unsigned int new_size)
{
	char *new_block;

	if (!mem)
		return (malloc(new_size));
	if (!new_size)
		return (free(mem), NULL);
	if (new_size == prev_size)
		return (mem);

	new_block = malloc(new_size);
	if (!new_block)
		return (NULL);

	prev_size = prev_size < new_size ? prev_size : new_size;
	while (prev_size--)
	{
		new_block[prev_size] = ((char *)mem)[prev_size];
	}
	free(mem);
	return (new_block);
}

/**
 * _memset - fills memory with a byte
 * @mem: pointer to memory
 * @byte: byte to fill memory with
 * @n: number of bytes to fill
 * Return: pointer to the memory
 */

char *_memset(char *mem, char byte, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		mem[i] = byte;
	return (mem);
}
