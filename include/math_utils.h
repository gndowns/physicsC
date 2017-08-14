#ifndef MATH_UTILS_H
#define MATH_UTILS_H

typedef struct Quadratic {
  double a;
  double b;
  double c;
} Quadratic;

Quadratic distance_quadratic(Quadratic, Quadratic);
int calculate_roots(Quadratic, double *);
void print_quadratic(Quadratic);
#endif
