#include<stdio.h>

typedef struct Quadratic {
  int a;
  int b;
  int c;
} Quadratic;

void print(Quadratic);

int main() {

  Quadratic quad = {1, 1, 1};

  print(quad);
  printf("\n");

  return 0;
}

void print(Quadratic q) {
  printf("%dx^2 + %dx + %d",
    q.a, q.b, q.c);
}
