#include "shell.h"

/**
 * run_shell_loop - run the shell loop to process user input and commands
 */

void run_shell_loop(void)
{
	char *command;

	while (1)
	{
		display_prompt();
		command = get_line();

		if (command != NULL)
		{
			printf("%s\n", command);
			free(command);
		}
		else
		{
			printf("Error reading input. \n");
		}
	}
}

