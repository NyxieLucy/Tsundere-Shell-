#include "../include/shell.h"

/* Reads a line from stdin using getline */
char *readline(void) {
  char *line = NULL;
  size_t bufsize = 0;
  ssize_t characters = getline(&line, &bufsize, stdin);

  if (characters == -1) {
    // Handle EOF (Ctrl+D) or read error
    free(line);
    return NULL;
  }

  // Strip trailing newline character
  line[strcspn(line, "\n")] = '\0';
  return line;
}

/* Splits a string into an array of argument tokens */
char **parse_line(char *line) {
  char **tokens = malloc(MAX_ARGS * sizeof(char *));
  if (!tokens) {
    perror("malloc error");
    exit(EXIT_FAILURE);
  }

  char *token = strtok(line, DELIM);
  int position = 0;

  while (token != NULL && position < MAX_ARGS - 1) {
    tokens[position++] = token;
    token = strtok(NULL, DELIM);
  }
  tokens[position] = NULL; // execvp expects a NULL-terminated array

  return tokens;
}

/* Executes built-in commands or forks an external program */
int execute_command(char **args) {
  if (args[0] == NULL) {
    // Empty command (user just hit enter)
    return 1;
  }

  // Built-in: exit
  if (strcmp(args[0], "exit") == 0) {
    return 0; // Signals main() loop to terminate
  }

  // Built-in: cd
  if (strcmp(args[0], "cd") == 0) {
    if (args[1] == NULL) {
      fprintf(stderr, "cd: expected argument\n");
    } else if (chdir(args[1]) != 0) {
      perror("cd");
    }
    return 1;
  }

  // External command execution
  pid_t pid = fork();
  if (pid == 0) {
    // Child process
    if (execvp(args[0], args) == -1) {
      perror("exec error");
    }
    exit(EXIT_FAILURE);
  } else if (pid < 0) {
    perror("fork error");
  } else {
    // Parent process waits for child to finish
    int status;
    waitpid(pid, &status, 0);
  }

  return 1;
}
