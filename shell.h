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
void print_error(char *command);
char *get_path_env(void);
char *build_full_path(char *dir, char *command);
char *find_command_path(char *command);
void run_child_process(char *path, char **argv);
void clean_and_return(char *path, char **argv, char *original);
char *resolve_path(char *command);

#endif /* SHELL_H */
