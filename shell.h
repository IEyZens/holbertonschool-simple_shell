#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

extern char **environ;

int _strlen(char *str);
char *display_prompt(void);

#endif /* SHELL_H */
