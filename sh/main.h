#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

extern char **environ;

/* fonctions */
void prompt(void);
char *read_line(void);
char *trim_newline(char *line);
int is_empty(char *line);
void execute(char *line);

#endif /* MAIN_H */
