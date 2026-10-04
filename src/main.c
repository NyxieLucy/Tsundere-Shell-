#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *line = NULL;
  size_t len = 0;
  ssize_t read;
  printf("enter your statement: \n");
  read = getline(&line, &len, stdin);
  printf("\n there, i executed your dumb command, hmpf!\n");
  printf("\n(⸝⸝¬`‸´¬⸝⸝)~ ");

  free(line);
  return 0;
}
