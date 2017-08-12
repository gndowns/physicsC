#include<stdio.h>
#include<math.h>
#include "math_utils.h"

Quadratic distance_quadratic(Quadratic q1, Quadratic q2) {
  Quadratic q;

  q.a = q1.a - q2.a;
  q.b = q1.b - q2.b;
  q.c = q1.c - q2.c;

  return q;
}

int calculate_roots(Quadratic q, double *roots) {
  // check if any solution
  if (q.a == 0 && q.b == 0) {
    return -1;
  }
  // check if linear equation
  else if (q.a == 0) {
    int res = -q.c / q.b;
    roots[0] = res;
    roots[1] = res;

    return 0;
  }

  // else, quadratic formula
  // check if part under the radical is real
  double radicand = q.b * q.b - (4 * q.a * q.c);
  if (radicand < 0) {
    return -1;
  }

  double r1 = ( -q.b + sqrt( radicand ) ) / (2 * q.a);
  roots[0] = r1;

  double r2 = ( -q.b - sqrt( radicand ) ) / (2 * q.a);
  roots[1] = r2;

  return 0;
}

void print_quadratic(Quadratic q) {
  printf("%fx^2 + %fx + %f",
    q.a, q.b, q.c);
}
