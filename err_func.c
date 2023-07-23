#include "shell.h"

/**
 * remove_comments - replace # with '\0'
 * @str: string to be modified
 * Return: 0
 */

void remove_comments(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		if (str[i] == '#' && (!i || str[i - 1] == ' '))
		{
			str[i] = '\0';
			break;
		}
}

/**
 * _itoa - convert number to string
 * @num: number to be converted
 * @base: number's base
 * @flags: argument flags
 * Return: the converted string
 */
char *_itoa(long int num, int base, int flags)
{
	static char *arr;
	static char buff[50];
	char num_sign = 0;
	char *p;
	unsigned long n = num;

	if (!(flags & 2) && num < 0)
	{
		n = -num;
		num_sign = '-';
	}
	arr = flags & 1 ? "0123456789abcdef" :
		"0123456789ABCDEF";
	p = &buff[49];
	*p = '\0';

	do {
		*--p = arr[n % base];
		n /= base;
	} while (n != 0);

	if (num_sign)
		*--p = num_sign;
	return (p);
}

/**
 * print_d - prints a decimal nubeer in base 10
 * @num: number to print
 * @fd: file descriptor to write to
 * Return: number of chars printed
 */

int print_d(int num, int fd)
{
	int (*__putchar)(char) = _putchar;
	int i, letters_count = 0;
	unsigned int absol, current;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (num < 0)
	{
		absol = -num;
		__putchar('-');
		letters_count++;
	}
	else
		absol = num;
	current = absol;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (absol / i)
		{
			__putchar('0' + current / i);
			letters_count++;
		}
		current %= i;
	}
	__putchar('0' + current);
	letters_count++;
	return (letters_count);
}

/**
 * print_err - prints an error message
 * @info: the info struct
 * @errstr: error type
 * Return: 0 if no numbers in string, converted number, -1 on error
 */
void print_err(info_t *info, char *errstr)
{
	_eputs(info->filename);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(errstr);
}

/**
 * error_atoi - converts string to int
 * @str: string to be converted
 * Return: -1 on error
 */
int error_atoi(char *str)
{
	int i = 0;
	unsigned long int result = 0;

	if (*str == '+')
		str++;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			result *= 10;
			result += (str[i] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}
