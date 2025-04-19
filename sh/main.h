#ifndef MAIN_H
#define MAIN_H

/* includes */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

/* fonctions */
void prompt(void);
char *read_line(void);
char **parse_line(char *line);
void execute(char **args);
void free_args(char **args);

/* builtins */
int is_builtin(char *cmd);
void exec_builtin(char **args);

#endif
