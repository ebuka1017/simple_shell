#include "shell.h"

/**
 * set_env - set or modify an environment variable
 * @f_info: struct address
 * Return: 1 on success, 0 on failure
 */
int set_env(info_t *f_info)
{
	if (f_info->argv[1] == NULL || f_info->argv[2] == NULL)
	{
		fprintf(stderr, "Usage: setenv VARIABLE VALUE\n");
		return (0);
	}

	if (setenv(f_info->argv[1], f_info->argv[2], 1) == -1)
	{
		fprintf(stderr, "Failed to set environment variable\n");
		return (0);
	}

	return (1);
}

/**
 * unset_env - unset an environment variable
 * @f_info: struct address
 * Return: 1 on success, 0 on failure
 */
int unset_env(info_t *f_info)
{
	if (f_info->argv[1] == NULL)
	{
		fprintf(stderr, "Usage: unsetenv VARIABLE\n");
		return (0);
	}

	if (unsetenv(f_info->argv[1]) == -1)
	{
		fprintf(stderr, "Failed to unset environment variable\n");
		return (0);
	}

	return (1);
}

