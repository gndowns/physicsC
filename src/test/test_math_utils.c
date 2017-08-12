#include<stdio.h>
#include<string.h>
#include "../math_utils.h"

int compare_quads(Quadratic, Quadratic);

int main() {

  // test for linear equations
  Quadratic linear = {0, 3, 9};
  printf("calculating roots for: ");
  print_quadratic(linear);
  printf("\n\n");
  printf("expected: ");
  printf("root 1: -3, root 2: -3");
  printf("\n");

  double roots[2];
  int res = calculate_roots(linear, roots);
  printf("result: ");
  printf("root 1: %f, root 2: %f", roots[0], roots[1]);
  printf("\n");
  if (roots[0] == -3 && roots[1] == -3) {
    printf("SUCCESS\n");
  }
  else {
    printf("FAILURE\n");
  }

  if (0) {
    Quadratic q1 = {1, 8, 16};
    Quadratic q2 = {1, 5, 6};

    printf("calculating distance between:\n");
    print_quadratic(q1);
    printf("\n");
    print_quadratic(q2);
    printf("\n");

    Quadratic q = distance_quadratic(q1, q2);

    Quadratic expected = {0, 3, 10};
    printf("\nexpected: ");
    print_quadratic(expected);
    printf("\n");
    printf("result: ");
    print_quadratic(q);
    printf("\n");
    int comp = compare_quads(q, expected);
    if (comp == 0) {
      printf("SUCCESS\n");
    }
    else {
      printf("FAILURE\n");
    }
  }

  return 0;
}

int compare_quads(Quadratic q1, Quadratic q2) {
  if (q1.a != q2.a) {
    return -1;
  }
  else if (q1.b != q2.b) {
    return -1;
  }
  else if (q1.c != q2.c) {
    return -1;
  }
  else {
    return 0;
  }
}
