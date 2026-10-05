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

  if (read != -1) {
    line[strcspn(line, "\n")] = '\0';
    pid_t pid = fork();
    if (pid == 0) {
      char *args[] = {line, NULL};
      if (execvp(args[0], args) == -1) {
        perror("exec error!");
        exit(1);
      }
    } else if (pid > 0) {
      int status;
      waitpid(pid, &status, 0);
      printf("done");
    }
  }

  printf("\n there, i executed your dumb command, hmpf!\n");
  printf("\n(⸝⸝¬`‸´¬⸝⸝)~ ");
  free(line);

  return 0;
}
