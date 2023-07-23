#include "shell.h"

/**
 * is_command - checks for a command
 * @f_info: struct address
 * @path: path to file
 * Return: 1, 0
 */
int is_command(info_t *f_info, char *path)
{
	struct stat s;

	(void)f_info;
	if (!path || stat(path, &s))
		return (0);
	if (s.st_mode & S_IFREG)
		return (1);
	return (0);
}

/**
 * duplicate_chars - duplicates set of hars
 * @path: the path
 * @begin: begin index
 * @end: end index
 * Return: return buffer
 */
char *duplicate_chars(char *path, int begin, int end)
{
	static char buffer[1024];
	int i;
	int j;

	for (j = 0, i = begin; i < end; i++)
		if (path[i] != ':')
			buffer[j++] = path[i];
	buffer[j] = 0;
	return (buffer);
}

/**
 * get_path - gets the path
 * @f_info: struct address
 * @path: the path
 * @command: the commnad to find the path for
 * Return: the path of command
 */
char *get_path(info_t *f_info, char *path, char *command)
{
	int i = 0;
	int j = 0;
	char *the_path;

	if (!path)
		return (NULL);
	if ((_strlen(command) > 2) && _starts_with(command, "./"))
	{
		if (is_command(f_info, command))
			return (command);
	}
	while (1)
	{
		if (!path[i] || path[i] == ':')
		{
			the_path = duplicate_chars(path, j, i);
			if (!*the_path)
				_strcat(the_path, command);
			else
			{
				_strcat(the_path, "/");
				_strcat(the_path, command);
			}
			if (is_command(f_info, the_path))
				return (the_path);
			if (!path[i])
				break;
			j = i;
		}
		i++;
	}
	return (NULL);
}
