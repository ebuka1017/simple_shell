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

#define HISTORY_FILE ".simple_shell_history"
#define HISTORY_MAX 4096
#define GET_LINE 0
#define STR_TOK 0

extern char **environ;

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
 * @environ: modified copy of environ from ll env
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
	char **environ;
	int changed_env;
	int status;
	char **cmd_buffer;
	int cmd_buffer_type;
	int readfd;
	int hist_count;
} info_t;

#define INIT_INFO \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, \
	NULL, 0, 0, NULL, 0, 0, 0}

/**
 * struct builtin - contains a string and related function
 * @type: builtin command flag
 * @func: the function
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;


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
char **strtow2(char *, char);
char **strtow(char *, char *);


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

/* err_func.c */
void remove_comments(char *);
char *_itoa(long int, int, int);
int print_d(int num, int fd);
void print_err(info_t *, char *);
int error_atoi(char *);

/* err_func2.c */
void _eputs(char *);
int _eputchar(char);
int _putfd(char, int fd);
int _putsfd(char *, int fd);

/* linked_list1.c */
list_t *add_node(list_t **, const char *, int);
list_t *add_node_to_end(list_t **, const char *, int);
size_t print_str_list(const list_t *);
int delete_node(list_t **, unsigned int);
void free_list(list_t **);

/* linked_list2.c */
size_t len_list(const list_t *);
char **list_strings(list_t *);
size_t print_list(const list_t *);
list_t *starts_with(list_t *, char *, char);
ssize_t get_node(list_t *, list_t *);

/* file_info.c */
void clear_info(info_t *);
void set_info(info_t *, char **);
void free_info(info_t *, int);

/* env_func1.c */
char *_getenv(info_t *, const char *);
int _currenv(info_t *);
int _mysetenv(info_t *);
int _free_env(info_t *);
int create_env_list(info_t *);

/* env_func2.c */
char **get_file_environ(info_t *);
int _unset_file_env(info_t *, char *);
int _setenv(info_t *, char *, char *);

/* file_io_func.c */
char *get_hist(info_t *f_info);
int write_hist(info_t *f_info);
int read_hist(info_t *f_info);
int build_hist(info_t *f_info, char *buffer, int line_count);
int renum_hist(info_t *f_info);

/* emulator_func.c */
int _eexit(info_t *);
int _cd(info_t *);
int _help(info_t *);
int _history(info_t *);

/* alias_func.c */
int _alias(info_t *);

/* my_path.c */
int is_command(info_t *, char *);
char *duplicate_chars(char *, int, int);
char *get_path(info_t *, char *, char *);

/* my_chain.c */
int rep_str(char **, char *);
int rep_var(info_t *);
int rep_alias(info_t *);
int check_chain(info_t *, char *, size_t *);
void continue_chain(info_t *, char *, size_t *, size_t, size_t);

/* input_func.c */
ssize_t _read_buffer(info_t *, char *, size_t *);
int my_getline(info_t *, char **, size_t *);
ssize_t _Input(info_t *);
ssize_t inp_buffer(info_t *, char **, size_t *);
void signal_handler(__attribute__((unused))int num);

/* fun_hsh */
int hsh(info_t *, char **);

#endif

