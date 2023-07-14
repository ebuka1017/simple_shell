#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

/**
 * read_input - Read input from the user
 *
 * Return: input line read from the user
 */

char *read_input(void)
{
	char *line = NULL;
	size_t bufsize = 0;

	getline(&line, &bufsize, stdin);

	return (line);
}

