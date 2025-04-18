#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

char *display_prompt(void);
void execute_command(char *input);
void free_and_null(char **ptr);

#endif /* SHELL_H */
