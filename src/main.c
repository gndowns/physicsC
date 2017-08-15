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

void create_particles(Cell *space)
{
  int numParticles;
  printf("How many particles would you like to create? (0-2): ");
  scanf("%d", &numParticles);

  for (int i=0; i < numParticles; i++) {
    printf("\nParticle %d\n", i+1);
    int x = get_position(i+1);
    space[x].on = 1;
    space[x].v = get_attribute("velocity");
    space[x].a = get_attribute("acceleration");
    printf("\n");
  }
}

int get_position()
{
  int x;
  printf("Enter position (0-%d): ", SIZE - 1);
  scanf("%d", &x);
  return x;
}

int get_attribute(char *attr)
{
  int out;
  printf("Enter %s: ", attr);
  scanf("%d", &out);
  return out;
}
