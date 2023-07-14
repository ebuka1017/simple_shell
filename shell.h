#ifndef SHELL_H
#define SHELL_H

void shell_loop(void);
void display_prompt(void);
char *read_input(void);
int execute(char **args);
char **parse_input(char *line);

#endif

