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
int _strncmp(const char *s1, const char *s2, int n);
char *_strdup(const char *str);
int _strlen(const char *s);
void _strcat(char *dest, const char *src);
char *_strcpy(char *dest, const char *src);
int _strcmp(const char *s1, const char *s2);
char *get_path_env(void);
char *build_full_path(char *dir, char *command);
char *find_command_path(char *command);
void run_child_process(char *path, char **argv);
void clean_and_return(char *path, char **argv, char *original);
char *resolve_path(char *command);

#endif /* SHELL_H */
