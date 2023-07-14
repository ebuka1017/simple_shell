#include <stdio.h>

/**
 * main - Entry point of the program
 * @argc: The argument count
 * @argv: An array of pointers to the arguments
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		printf("Argument provided: %s\n", argv[1]);
	}

	else if (argc > 2)
	{
		printf("Too many arguments provided.\n");
	}
	else
	{
		printf("No argument provided.\n");
	}

	return (0);
}
