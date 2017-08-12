#include<stdlib.h>
#include "engine.h"
#include "math_utils.h"

Cell* time_step(Cell *space)
{
  // this represents the soonest collision within one TIME unit
  // init as "impossible" collision
  Collision first_collision = {
    TIME,
    -1,
    -1
  };

  calculate_destinations(space, &first_collision);

  // move particles (copy to out array w/ new positions)
  // init
  Cell *out = malloc( sizeof(Cell) * SIZE);
  for (int i=0; i < SIZE; i++) {
    nullify(out, i);
  }
  // move
  for (int i=0; i < SIZE; i++) {
    Cell p = space[i];
    if (p.dest != -1) {
      out[p.dest] = p;
      out[p.dest].dest = -1;
    }
    // this will be deleted
    else if (p.on) {
      out[i] = p;
    }
  }

  return out;
}

void calculate_destinations(Cell *space, Collision *collision)
{
  for (int i=0; i < SIZE; i++) {
    if (space[i].on) {
      // grab particle
      Cell *p = &(space[i]);

      // check if collides with positive neighbour
      if (p->posNeighbour != -1) {
        Cell *nbhr = &(space[p->posNeighbour]);
        int res = does_collide(p, i, nbhr, p->posNeighbour);
      }

      // kinematics
      int x = i + p->v * TIME + 0.5 * p->a * TIME * TIME;
      p->v += p->a * TIME;

      // keep in bounds
      x = x > (SIZE - 1) ? (SIZE - 1) : x;
      x = x < 0 ? 0 : x;

      p->dest = x;
    }
  }
}

int does_collide(Cell *p1, int i, Cell *p2, int j) {
  Quadratic q1 = {0.5 * p1->a, p1->v, -i};
  return 0;
}

// should be done once for each board at init;
// stores the index of each active particle's
// closest neighbour in the positive direction
void calculate_neighbours(Cell *space)
{
  int j = 0;
  for (int i=0; i < SIZE; i++) {
    if (space[i].on) {
      Cell *p = &(space[i]);

      // find next active particle
      j = i + 1;
      Cell c = space[j];
      while ( !c.on && j < SIZE) {
        j++;
        c = space[j];
      }

      // leave as -1 if no particle found
      if (j < SIZE) {
        p->posNeighbour = j;
      }

      // increment to next active particle
      i = j - 1;
    }
  }
}

// the default setup for an empty cell
void nullify(Cell *space, int i)
{
  Cell *c = &(space[i]);
  c->on = 0;
  c->v = 0;
  c->a = 0;
  c->dest = -1;
  c->posNeighbour = -1;
}
