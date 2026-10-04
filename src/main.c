#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

// TO DO: FIX THIS TRASHY NONSENSE
int main() {
  char *line = NULL;
  size_t len = 0;
  ssize_t read;
  printf("enter your statement: \n");
  read = getline(&line, &len, stdin);
  pid_t pid = fork();

  if (read != -1) {
    if (pid == 0) {
      execvp(line);

    } else {
      int status;
      waitpid(pid, &status, 0);
      printf("done");
      // parent process
    }
  }

  printf("\n there, i executed your dumb command, hmpf!\n");
  printf("\n(⸝⸝¬`‸´¬⸝⸝)~ ");

  free(line);
  return 0;
}
