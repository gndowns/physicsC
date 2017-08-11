#include<stdio.h>

typedef struct Quadratic {
  int a;
  int b;
  int c;
} Quadratic;

int get_roots(Quadratic, float *);
void print(Quadratic);

int main() {

  Quadratic quad = {1, 1, 1};

  print(quad);
  printf("\n");

  float roots[2];
  // example with imaginary roots
  Quadratic imaginary_roots = {1, 4, 5};
  int res = get_roots(quad, roots);
  printf("%d\n", res);

  return 0;
}

int get_roots(Quadratic q, float *roots) {
  // quadratic formula
  // check if part under the radical is real
  float radicand = q.b * q.b - (4 * q.a * q.c);
  if (radicand < 0) {
    return -1;
  }
  /* r1 = -q.b + square_root(q.b * q.b - 4 * q.a * q.c) / (2 * q.a); */
  /* r2 = -q.b - square_root(q.b * q.b - 4 * q.a * q.c) / (2 * q.a); */
  return 0;
}

void print(Quadratic q) {
  printf("%dx^2 + %dx + %d",
    q.a, q.b, q.c);
}
