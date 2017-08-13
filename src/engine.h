#ifndef ENGINE_H
#define ENGINE_H

typedef struct Cell {
  int on;
  int v;
  int a;
  int dest;
  int negNeighbour;
  int posNeighbour;
} Cell;

typedef struct Collision {
  int time;
  int c1;
  int c2;
} Collision;

Cell* time_step(Cell *);
void calculate_destinations(Cell *, Collision *);
int does_collide(Cell , int, Cell , int, double *);
void calculate_neighbours(Cell *);
void nullify(Cell *, int);

extern int SIZE;
extern const int TIME;

#endif
