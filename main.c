#include "shell.h"

/**
 * main - start of program
 * @argsc: args count
 * @argsv: args vector
 * Return: 0
 */

int main(int argsc, char **argsv)
{
	info_t file_info[] = { INIT_INFO };
	int fd = 2;

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (fd)
		: "r" (fd));

	if (argsc == 2)
	{
		fd = open(argsv[1], O_RDONLY);
		if (fd == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(argsv[0]);
				_eputs(": 0: Can't open ");
				_eputs(argsv[1]);
				_eputchar('\n');
				_eputchar(-1);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		file_info->readfd = fd;
	}
	create_env_list(file_info);
	read_history(file_info);
	hsh(file_info, argsv);
	return (EXIT_SUCCESS);
}

