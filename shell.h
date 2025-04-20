#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/signal.h>
#include <string.h>

extern char **environ;

char *read_command(void);
void execute_command(char *command);
char **parse_args(char *command);
void print_error(void);

#endif /* SHELL_H */
