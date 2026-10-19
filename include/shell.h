#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#define DELIM " \t\r\n\a"
#define MAX_ARGS 64

char *readline(void);
char **parse_line(char *line);
int execute_command(char **args);

#endif
