#include<stdio.h>
#include<math.h>

typedef struct Quadratic {
  int a;
  int b;
  int c;
} Quadratic;

Quadratic distance_quadratic(Quadratic, Quadratic);
int calculate_roots(Quadratic, double *);
void print(Quadratic);

int main() {
  Quadratic q1 = {1, 8, 16};
  Quadratic q2 = {1, 5, 6};
  printf("calculating distance between:\n");
  print(q1);
  printf("\n");
  print(q2);
  printf("\n");

  Quadratic q = distance_quadratic(q1, q2);
  printf("\n");
  print(q);
  printf(" = d\n");
  return 0;
}

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

void print(Quadratic q) {
  printf("%dx^2 + %dx + %d",
    q.a, q.b, q.c);
}
