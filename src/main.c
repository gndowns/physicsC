#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#include "main.h"
#include "engine.h"
#include "term_1d_animate.h"

// DEFAULTS
int SIZE = 0;
int FPS = 1;
Cell *PARTICLES;

const int TIME = 1;

int main(int argc, char **argv) {
  // -c flag for load from config file
  char *configFilePath = NULL;
  int c;

  if ( (c = getopt(argc, argv, "c:")) != -1) {
    configFilePath = optarg;
  }

  if (configFilePath) {
    FILE *f = fopen(configFilePath, "r");
    fseek(f, 0, SEEK_END);
    long length = ftell(f);
    fseek(f, 0, SEEK_SET);
    char *buffer = malloc(length);
    fread(buffer, length, 1, f);
    fclose(f);
    printf("%s", buffer);
  }

  // init
  Cell *space = malloc( sizeof(Cell) * SIZE );
  for(int i=0; i < SIZE; i++) {
    nullify(space, i);
  }

  char orientation = 'u';
  animate(space, orientation);

  free(space);

  return 0;
}
