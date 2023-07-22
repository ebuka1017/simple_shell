#include "shell.h"

/**
 * strtow2 - splits a string to words
 * @str: string to be splitted
 * @delim: delimeters string
 * Return: pointer to a pointer to an array of strings
 */

char **strtow2(char *str, char delim)
{
	int i, j, k, m, words_count = 0;
	char **res;

	if (str[0] == 0 || str == NULL)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
		if ((str[i] != delim && str[i + 1] == delim) ||
				(str[i] != delim && !str[i + 1])
				|| str[i + 1] == delim)
			words_count++;
	if (words_count == 0)
		return (NULL);
	res = malloc((1 + words_count) * sizeof(char *));
	if (!res)
		return (NULL);
	for (i = 0, j = 0; j < words_count; j++)
	{
		while (str[i] == delim && str[i] != delim)
			i++;
		k = 0;
		while (str[i + k] != delim && str[i + k])
			k++;
		res[j] = malloc((k + 1) * sizeof(char));
		if (!res[j])
		{
			for (k = 0; k < j; k++)
				free(res[k]);
			free(res);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			res[j][m] = str[i++];
		res[j][m] = 0;
	}
	res[j] = NULL;
	return (res);
}

#define CONDITION (!is_delimeter(str[i], delim) && (is_delimeter(str[i + 1],\
delim) || !str[i + 1]))

/**
 * strtow - splits a string
 * @str: string to be splitted
 * @delim: delimeters
 * Return: pointer to an array of strings
 */

char **strtow(char *str, char *delim)
{
	int i, j, k, m, words_count = 0;
	char **res;

	if (str[0] == 0 || str == NULL)
		return (NULL);
	if (!delim)
		delim = " ";
	for (i = 0; str[i] != '\0'; i++)
	{
		if CONDITION
			words_count++;
	}
	if (words_count == 0)
		return (NULL);
	res = malloc((1 + words_count) * sizeof(char *));
	if (!res)
		return (NULL);
	for (i = 0, j = 0; j < words_count; j++)
	{
		while (is_delimeter(str[i], delim))
			i++;
		k = 0;
		while (!is_delimeter(str[i + k], delim) && str[i + k])
			k++;
		res[j] = malloc((k + 1) * sizeof(char));
		if (!res[j])
		{
			for (k = 0; k < j; k++)
				free(res[k]);
			free(res);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			res[j][m] = str[i++];
		res[j][m] = 0;
	}
	res[j] = NULL;
	return (res);
}

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
	} while (*str++ != '\0');
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
