#include "shell.h"

/**
 * _puts - prints a string
 * @s: string to print
 * Return: void
 */

void _puts(char *s)
{
	int i = 0;

	if (!s)
		return;
	while (s[i] != '\0')
	{
		_putchar(s[i]);
		i++;
	}
}

/**
 * _putchar - writes a charact to stdout
 * @ch: char to print
 * Return: 1 on success, -1 on error
 */

int _putchar (char ch)
{
	static int i;
	static char buffer[1024];

	if (ch == -1 || i >= 1024)
	{
		write(1, buffer, i);
		i = 0;
	}
	if (ch != -1)
		buffer[i++] = ch;
	return (1);
}

/**
 * _strdup - duplicates a string
 * @str: string to duplicate
 * Return: pointer to new string
 */

char *_strdup(const char *str)
{
	int len = 0;
	char *result;

	if (str == NULL)
		return (NULL);

	while (*str++)
		len++;
	result = malloc(sizeof(char) * (len + 1));

	if (!result)
		return (NULL);
	for (len++; len--;)
		result[len] = *--str;
	return (result);
}

/**
 * _strcpy - copies a string
 * @dest: destination
 * @src: source
 * Return: pointer to dest
 */

char *_strcpy(char *dest, char *src)
{
	int pos = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[pos])
	{
		dest[pos] = src[pos];
		pos++;
	}
	dest[pos] = 0;
	return (dest);
}
