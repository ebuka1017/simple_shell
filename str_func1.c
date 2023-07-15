#include "shell.h"

/**
 * _strcat - conat 2 strings
 * @str1: first string
 * @str2: second string
 * Return: pointer to new string
 */

char *_strcat(char *str1, char *str2)
{
	char *result = str1;

	while (*str1)
		str1++;
	while (*str2)
		*str1++ = *str2++;
	*str1 = *str2;
	return (result);
}

/**
 * _strlen - returns string length
 * @str: string
 * Return: length
 */

int _strlen(char *str)
{
	int count = 0;

	if (!str)
		return (0);

	while (*s++)
		count++;
	return (count);
}

/**
 * _starts_with - check is string starts with another
 * @str1: string to be searched
 * @str2: substring to find
 * Return: address of str2
 */

char *_starts_with(const char *str1, const char *str2)
{
	while (*str2)
		if (*str2++ != *str1++)
			return (NULL);

	return ((char *) str1);
}

/**
 * _strcmp - compare two strings
 * @str1: first
 * @str2: second
 * Return: negative if s1 < s2, 1 if s1 > s2, 0 if s1 = s2
 */

int _strcmp(char *str1, char *str2)
{
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}

	if (*str1 == *str2)
		return (0);
	else
		return (*str1 < *str2 ? -1 : 1);
}
