#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

/**
 * shell_loop - main loop of the shell program
 */

void shell_loop(void)
{
	char *line;
	char **args;
	int status;

	do {
		display_prompt();
		line = read_input();
		args = parse_input(line);
		status = execute(args);

		free(line);
		free(args);
	} while (status);
}
