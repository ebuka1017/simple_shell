#include "shell.h"

/**
 * _strchr - locates a char in string
 * @str: string
 * @c: char to look for
 * Return: pointer to char c
 */

char *_strchr(char *str, char c)
{
	do {
		if (*str == c)
			return (str);
	} while (*s++ != '\0');
	return (NULL);
}

/**
 * _strncpy - copies n characters of a string
 * @dest: destination string
 * @src: string to copy from
 * @n: num of chars to copy
 * Return: the new string
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i = 0;
	char *result = dest;

	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		while (i < n)
		{
			dest[i] = '\0';
			i++;
		}
	}
	return (result);
}

/**
 * _strncat - concat 2 strings
 * @dest: destination string
 * @src: source string
 * @n: num of chars to concat
 * Return: concated string
 */

char *_strncat(char *dest, char *src, int n)
{
	int i = 0;
	int j = 0;
	char *result = dest;

	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (result);
}
