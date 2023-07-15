#ifndef SHELL_H
#define SHELL_H

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

#endif

