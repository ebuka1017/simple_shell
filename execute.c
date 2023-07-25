#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

/**
 * execute - execute a command in the child process
 * @args: array of command arguments
 *
 * Return: Status code indicating the execution result
 */

int execute(char **args)
{
	pid_t pid;
	int status;
	int exit_status = _atoi(args[1]);

	pid = fork();

	if (args[0] && _strcmp(args[0], "exit") == 0)
	{
		if (args[1] == NULL)
			exit(0);

		exit(exit_status);
	}


	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror(args[0]);
			exit(EXIT_SUCCESS);
		}
	}
	else if (pid < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(pid, &status, WUNTRACED);
	}

	return (1);
}

