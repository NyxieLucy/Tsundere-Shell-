#include "../include/shell.h"
#include <stdbool.h>
#include <stdio.h>

#include <stdlib.h>
#include <unistd.h>
int main(int argc, char *argv[]) {
  (void)argc;
  (void)argv;
  char *line;

  char **args;
  int status;
  int interractivity = isatty(STDIN_FILENO);
  do {
    if (interractivity) {
      printf("( ˶ˆ꒳ˆ˵ )>");
      fflush(stdout);
    }
    line = readline();
    if (line == NULL) {
      break;
    }
    args = parse_line(line);
    if (args != NULL) {
      status = execute_command(args);
    }
    free(line);
    free(args);
  } while (status);
  return EXIT_SUCCESS;
}
