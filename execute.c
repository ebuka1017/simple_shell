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

	pid = fork();

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

