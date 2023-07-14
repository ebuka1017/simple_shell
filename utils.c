#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

/**
 * parse_input - parse input line into tokens
 * @line: input line to parse
 *
 * Return: Array of tokens
 */

char **parse_input(char *line)
{
	const char *delimiters = "\t\r\n\a";
	char **tokens = malloc(sizeof(char *) * BUFFER_SIZE);
	char *token;
	int position = 0;

	if (!tokens)
	{
		fprintf(stderr, "Allocation Error\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, delimiters);

	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		token = strtok(NULL, delimiters);
	}
	tokens[position] = NULL;
	return (tokens);
}

