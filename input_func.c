#include "shell.h"

/**
 * _read_buffer - reads buffer
 * @f_info: struct address
 * @buffer: the buffer
 * @size: size of buffer
 * Return: bytes read
 */
ssize_t _read_buffer(info_t *f_info, char *buffer, size_t *size)
{
	ssize_t bytes_read = 0;

	if (*size)
		return (0);
	bytes_read = read(f_info->readfd, buffer, 1024);
	if (bytes_read >= 0)
		*size = bytes_read;
	return (bytes_read);
}

/**
 * _getline - gets the line of input
 * @f_info: struct address
 * @ptr: address of buffer
 * @size: size
 * Return: size
 */
int my_getline(info_t *f_info, char **ptr, size_t *size)
{
	static char buffer[1024];
	static size_t i, length;
	size_t k;
	ssize_t bytes_read = 0;
	ssize_t scan = 0;
	char *p = NULL, *new_ptr = NULL;
	char *c;

	p = *ptr;
	if (p && size)
		scan = *size;
	if (i == length)
		i = length = 0;

	bytes_read = _read_buffer(f_info, buffer, &length);
	if (bytes_read == -1 || (bytes_read == 0 && length == 0))
		return (-1);

	c = _strchr(buffer + i, '\n');
	k = c ? 1 + (unsigned int)(c - buffer) : length;
	new_ptr = _realloc(p, scan, scan ? scan + k : k + 1);
	if (!new_ptr)
		return (p ? free(p), -1 : -1);
	if (scan)
		_strncat(new_ptr, buffer + i, k - i);
	else
		_strncpy(new_ptr, buffer + i, k - i + 1);
	scan += k - i;
	i = k;
	p = new_ptr;

	if (size)
		*size = scan;
	*ptr = p;
	return (scan);
}

/**
 * _Input - gets a line of input
 * @f_info: struct address
 * Return: bytes read
 */
ssize_t _Input(info_t *f_info)
{
	static char *buffer;
	static size_t i, j, size;
	ssize_t bytes_read;
	char **buffer_pos = &(f_info->arg), *pos;

	_putchar(-1);
	bytes_read = inp_buffer(f_info, &buffer, &size);
	if (bytes_read == -1)
		return (-1);
	if (size)
	{
		j = i;
		pos = buffer + i;
		continue_chain(f_info, buffer, &j, i, size);
		while (j < size)
		{
			if (check_chain(f_info, buffer, &j))
				break;
			j++;
		}
		i = j + 1;
		if (i >= size)
		{
			i = size = 0;
			f_info->cmd_buffer_type = 0;
		}
		*buffer_pos = pos;
		return (_strlen(pos));
	}
	*buffer_pos = buffer;
	return (bytes_read);
}

/**
 * inp_buffer - put commnads in buffer
 * @f_info: struct address
 * @buffer: buffer
 * @size: size of var
 * Return: bytes read
 */
ssize_t inp_buffer(info_t *f_info, char **buffer, size_t *size)
{
	ssize_t temp = 0;
	size_t len = 0;

	if (!*size)
	{
		free(*buffer);
		*buffer = NULL;
		signal(SIGINT, signal_handler);
#if GET_LINE
		temp = getline(buffer, &len, stdin);
#else
		temp = my_getline(f_info, buffer, &len);
#endif
		if (temp > 0)
		{
			if ((*buffer)[temp - 1] == '\n')
			{
				(*buffer)[temp - 1] = '\0';
				temp--;
			}
			f_info->line_count_flag = 1;
			remove_comments(*buffer);
			build_hist(f_info, *buffer, f_info->hist_count++);
			{
				*size = temp;
				f_info->cmd_buffer = buffer;
			}
		}
	}
	return (temp);
}

/**
 * signal_handler - ctrl-C
 * @num: signal number
 * Return: nothing
 */
void signal_handler(__attribute__((unused))int num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(-1);
}
