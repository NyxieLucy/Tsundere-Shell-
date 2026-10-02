#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  bool state = true;
  while (state) {

    if (state) {
      for (int i = 1; i < argc; i++) {

        system(argv[i]);
        printf("\n there, i executed your dumb command, hmpf!\n");
        printf("\n(⸝⸝¬`‸´¬⸝⸝)~ ");
        char newStatement[10]; // for now we giving it 2
        scanf("%s", newStatement);
        system(newStatement);
        if (newStatement != NULL) {

          state = true;

        } else {
          state = false;
          break;
        }
      }
    }
  }
  return 0;
}
