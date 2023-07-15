#include "shell.h"

/**
 * is_interactive - checks is shell is in interactive mode
 * @info: struct address
 * Return: 1 if true, 0 otherwise
 */

int is_interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_alpha - checks is char is alphabetic
 * @c: char to be checked
 * Return: 1 if true, 0 if false
 */

int is_alpha(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - converts string to int
 * @str: string to convert
 * Return: converted string
 */

int _atoi(char *str)
{
	int i, final;
	int sign = 1, flag = 0;
	unsigned int res = 0;

	for (i = 0; str[i] != '\0' && flag != 2; i++)
	{
		if (str[i] == '-')
			sign = sign * -1;
		if (str[i] >= '0' && str[i] <= '9')
		{
			res = res * 10;
			res = res + (str[i] - '0');
			flag = 1;
		}
		else if (flag == 1)
			flag = 2;
	}
	if (sign == -1)
		final = -res;
	else
		final = res;
	return (final);
}

/**
 * is_delim - checks for delimeters
 * @c: char to be checked
 * @delim: delimeter string
 * Return: 1 for true, 0 if false
 */

int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}
