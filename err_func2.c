#include "shell.h"

/**
 * _eputs - prints an input string
 * @s: string to print
 * Return: void
 */

void _eputs(char *s)
{
	int idx = 0;

	if (!s)
		return;
	while (s[idx] != '\0')
	{
		_eputchar(s[idx]);
		idx++;
	}
}

/**
 * _eputchar - write to stderr
 * @c: char to write
 * Return: 1 on success, -1 on failure
 */

int _eputchar(char c)
{
	static int idx;
	static char buffer[1024];

	if (c == -1 || idx >= 1024)
	{
		write(2, buffer, idx);
		idx = 0;
	}
	if (c != -1)
		buffer[idx++] = c;
	return (1);
}

/**
 * _putfd - writes char to fd
 * @c: the char
 * @fd: the file d
 * Return: 1 on success, -1 on failure
 */

int _putfd(char c, int fd)
{
	static int idx;
	static char buffer[1024];

	if (c == -1 || idx >= 1024)
	{
		write(fd, buffer, idx);
		idx = 0;
	}
	if (c != -1)
		buffer[idx++] = c;
	return (1);
}

/**
 * _putsfd - prints input string
 * @s: string
 * @fd: file desc
 * Return: number of chars put
 */

int _putsfd(char *s, int fd)
{
	int idx = 0;

	if (!s)
		return (0);
	while (*s)
	{
		idx += _putfd(*s++, fd);
	}
	return (idx);
}
