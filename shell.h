#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/**
 * struct linked_list - single linked list
 * @num: number field
 * @str: string field
 * @next: pointer to the next node
 */
typedef struct linked_list
{
	int num;
	char *str;
	struct linked_list *next;
} list_t;

/**
 * struct info - arguments to pass to functions
 * @arg: string containing arguments
 * @argv: array of arguments
 * @path: path of current command
 * @argc: arguments count
 * @line_count: lines count
 * @err_no: code of error
 * @line_count_flag: line of input
 * @filename: program file name
 * @env: local copy of environ
 * @hist: history node
 * @alias: alias node
 * @environment: modified copy of environ from ll env
 * @changed_env: true if env changed
 * @status: return status of exec command
 * @cmd_buffer: address of pointer to cmd_buf
 * @cmd_buffer_type: ||, &&, ;
 * @readfd: the file descriptor to read input from
 * @hist_count: history line number count
 */

typedef struct info
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_no;
	int line_count_flag;
	char *filename;
	list_t *env;
	list_t *hist;
	list_t *alias;
	char **environment;
	int changed_env;
	int status;
	char **cmd_buffer;
	int cmd_buffer_type;
	int readfd;
	int hist_count;
} info_t;


void shell_loop(void);
void display_prompt(void);
char *read_input(void);
int execute(char **args);
char **parse_input(char *line);

/* str_func1.c */
int _strlen(char *);
int _strcmp(char *, char *);
char *_starts_with(const char *, const char *);
char *_strcat(char *, char *);

/* str_func2.c */
char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);

/* str_func3.c */
char *_strchr(char *, char);
char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);

/* mem_func.c */
int bfree(void **);
char *_memset(char *, char, unsigned int);
void *_realloc(void *, unsigned int, unsigned int);
void ffree(char **);

/* utils2.c */
int is_interactive(info_t *);
int is_delimeter(char, char *);
int is_alphapetic(char);
int _atoi(char *);

#endif

