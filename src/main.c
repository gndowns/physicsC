#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#include "main.h"
#include "engine.h"
#include "term_1d_animate.h"
#include "cJSON.h"

// DEFAULTS
int SIZE = 0;
int FPS = 1;
Cell *PARTICLES;

const int TIME = 1;

int main(int argc, char **argv) {
  // -c flag for load from config file
  char *configFilePath = NULL;
  int c;

  cJSON *config = NULL;
  if ( (c = getopt(argc, argv, "c:")) != -1) {
    configFilePath = optarg;
  }
  if (configFilePath) {
    FILE *f = fopen(configFilePath, "r");
    fseek(f, 0, SEEK_END);
    long length = ftell(f);
    fseek(f, 0, SEEK_SET);
    char *json_string = malloc(length);
    fread(json_string, length, 1, f);
    fclose(f);
    config = cJSON_Parse(json_string);
  }
  cJSON *size = cJSON_GetObjectItemCaseSensitive(config, "size");
  if (size) {
    SIZE = size->valueint;
  }
  cJSON *fps = cJSON_GetObjectItemCaseSensitive(config, "fps");
  if (fps) {
    FPS = fps->valueint;
  }

  Cell *space = malloc( sizeof(Cell) * SIZE );
  for(int i=0; i < SIZE; i++) {
    nullify(space, i);
  }

  cJSON *particles = cJSON_GetObjectItemCaseSensitive(config, "particles");
  if (particles) {
    int array_size = cJSON_GetArraySize(particles);
    cJSON *particle = cJSON_GetArrayItem(particles, 0);
    cJSON *position = cJSON_GetObjectItem(particle, "position");
    cJSON *v = cJSON_GetObjectItem(particle, "velocity");
    cJSON *a = cJSON_GetObjectItem(particle, "acceleration");
    int i = position->valueint;
    space[i].on = 1;
    space[i].v = v->valueint;
    space[i].a = a->valueint;
  }

  char orientation = 'u';
  animate(space, orientation);

  free(space);

  return 0;
}
