#ifndef ENGINE_H
#define ENGINE_H

typedef struct Cell {
  int on;
  int v;
  int a;
  int dest;
  int posNeighbour;
} Cell;

typedef struct Collision {
  int time;
  int c1;
  int c2;
} Collision;

Cell* time_step(Cell *);
void calculate_destinations(Cell *, Collision *);
void nullify(Cell *, int);

extern int SIZE;
extern const int TIME;

#endif
