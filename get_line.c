#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

/**
 * get_line - Read a line of input from the standard input
 *
 * Return: A pointer to the input line or NULL on failure or EOF
 */

char *get_line(void)
{
	static char buffer[BUFFER_SIZE];
	static int buffer_position;
	static int buffer_size;
	char *line = NULL;
	int line_length = 0;
	int char_read;

	while (1)
	{
		if (buffer_position >= buffer_size)
		{
			buffer_size = read(STDIN_FILENO, buffer, BUFFER_SIZE);
			if (buffer_size <= 0)
			{
				break;
			}
			buffer_position = 0;
		}
		char_read = buffer[buffer_position++];
		if (char_read == '\n' || char_read == EOF)
		{
			break;
		}
		line = realloc(line, line_length + 1);
		if (line == NULL)
		{
			perror("realloc");
			return (NULL);
		}
		line[line_length++] = char_read;
	}
	line = realloc(line, line_length + 1);
	if (line == NULL)
	{
		perror("realloc");
		return (NULL);
	}
	line[line_length] = '\0';
	return (line);
}
