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
  // quadratic formula
  // check if part under the radical is real
  float radicand = q.b * q.b - (4 * q.a * q.c);
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
  printf("%dx^2 + %dx + %d",
    q.a, q.b, q.c);
}
