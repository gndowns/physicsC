#include<stdio.h>

typedef struct Quadratic {
  int a;
  int b;
  int c;
} Quadratic;

void get_roots(Quadratic, float *);
void print(Quadratic);

int main() {

  Quadratic quad = {1, 1, 1};

  print(quad);
  printf("\n");

  float roots[2];
  get_roots(quad, roots);

  return 0;
}

void get_roots(Quadratic q, float *roots) {
}

void print(Quadratic q) {
  printf("%dx^2 + %dx + %d",
    q.a, q.b, q.c);
}
