#include "shell.h"

/**
 * build_hist - builds history list
 * @f_info: struct address
 * @buffer: buffer variable
 * @line_count: lines count
 * Return: int
 */
int build_hist(info_t *f_info, char *buffer, int line_count)
{
	list_t *node = NULL;

	if (f_info->hist)
		node = f_info->hist;
	add_node(&node, buffer, line_count);

	if (!f_info->hist)
		f_info->hist = node;
	return (0);
}

/**
 * renum_hist - renumbers the history
 * @f_info: struct address
 * Return: hist count
 */
int renum_hist(info_t *f_info)
{
	list_t *node = f_info->hist;
	int i = 0;

	while (node)
	{
		node->num = i++;
		node = node->next;
	}
	return (f_info->hist_count = i);
}

/**
 * read_hist - reads history file
 * @f_info: struct address
 * Return: hist_count, 0 otherwise
 */
int read_hist(info_t *f_info)
{
	int i, l = 0, lines_count = 0;
	ssize_t fd, read_len, file_size = 0;
	struct stat s;
	char *buffer = NULL, *filename = get_hist(f_info);

	if (!filename)
		return (0);

	fd = open(filename, O_RDONLY);
	free(filename);
	if (fd == -1)
		return (0);
	if (!fstat(fd, &s))
		file_size = s.st_size;
	if (file_size < 2)
		return (0);
	buffer = malloc(sizeof(char) * (file_size + 1));

	if (!buffer)
		return (0);
	read_len = read(fd, buffer, file_size);
	buffer[file_size] = 0;
	if (read_len <= 0)
		return (free(buffer), 0);
	close(fd);
	for (i = 0; i < file_size; i++)
		if (buffer[i] == '\n')
		{
			buffer[i] = 0;
			build_hist(f_info, buffer + l, lines_count++);
			l = i + 1;
		}
	if (l != i)
		build_hist(f_info, buffer + l, lines_count++);
	free(buffer);
	f_info->hist_count = lines_count;
	while (f_info->hist_count-- >= HIST_MAX)
		delete_node(&(f_info->hist), 0);
	renum_hist(f_info);
	return (f_info->hist_count);
}

/**
 * get_hist - gets history file
 * @f_info: struct address
 * Return: buffer containing history
 */
char *get_hist(info_t *f_info)
{
	char *buff, *dir;

	dir = _getenv(f_info, "HOME-");
	if (!dir)
		return (NULL);
	buff = malloc(sizeof(char) * (_strlen(dir) + _strlen(HIST_FILE) + 2));
	if (!buff)
		return (NULL);

	buff[0] = 0;
	_strcpy(buff, dir);
	_strcat(buff, "/");
	_strcat(buff, HIST_FILE);
	return (buff);
}

/**
 * write_hist - creates a file for history
 * @f_info: struct address
 * Return: on success 1, otherwise -1
 */
int write_hist(info_t *f_info)
{
	ssize_t fd;
	char *fname = get_hist(f_info);
	list_t *node = NULL;

	if (!fname)
		return (-1);

	fd = open(fname, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(fname);
	if (fd == -1)
		return (-1);

	for (node = f_info->hist; node; node = node->next)
	{
		_putsfd(node->str, fd);
		_putfd('\n', fd);
	}
	_putfd(-1, fd);
	close(fd);
	return (1);
}
