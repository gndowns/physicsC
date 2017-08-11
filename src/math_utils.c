#include<stdio.h>
#include<math.h>

typedef struct Quadratic {
  int a;
  int b;
  int c;
} Quadratic;

int calculate_roots(Quadratic, double *);
void print(Quadratic);

int main() {

  Quadratic quad = {1, 1, 1};

  double roots[2];
  // example with imaginary roots
  int res = calculate_roots(quad, roots);
  printf("calculating roots for ");
  print(quad);
  printf("\n%d\n", res);

  printf("\n");

  // example with single real root
  Quadratic single_real_root = {1, 8, 16};
  printf("calculating roots for ");
  print(single_real_root);
  res = calculate_roots(single_real_root, roots);
  printf("\n%d\n", res);
  printf("first root: %f\n", roots[0]);
  printf("second root: %f\n", roots[1]);

  printf("\n");

  // example with two real roots
  Quadratic real_roots = {1, 5, 6};
  printf("calculating roots for ");
  print(real_roots);
  res = calculate_roots(real_roots, roots);
  printf("\n%d\n", res);
  printf("first root: %f\n", roots[0]);
  printf("second root: %f\n", roots[1]);

  return 0;
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
