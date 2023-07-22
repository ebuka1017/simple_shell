#include "shell.h"

/**
 * read_hist - reads history file
 * @f_info: struct address
 * Return: hist_count, 0 otherwise
 */
int read_hist(info_t *f_info)
{
	int i, last = 0, linecount = 0;
	ssize_t fd, rdlen, fsize = 0;
	struct stat st;
	char *buffer = NULL, *fname = get_hist(f_info);

	if (!fname)
		return (0);

	fd = open(fname, O_RDONLY);
	free(fname);
	if (fd == -1)
		return (0);
	if (!fstat(fd, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	buffer = malloc(sizeof(char) * (fsize + 1));

	if (!buffer)
		return (0);
	rdlen = read(fd, buffer, fsize);
	buffer[fsize] = 0;
	if (rdlen <= 0)
		return (free(buffer), 0);
	close(fd);
	for (i = 0; i < fsize; i++)
		if (buffer[i] == '\n')
		{
			buffer[i] = 0;
			build_hist(f_info, buffer + last, linecount++);
			last = i + 1;
		}
	if (last != i)
		build_hist(f_info, buffer + last, linecount++);
	free(buffer);
	f_info->hist_count = linecount;
	while (f_info->hist_count-- >= HIST_MAX)
		delete_node(&(f_info->hist), 0);
	renumber_hist(f_info);
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
