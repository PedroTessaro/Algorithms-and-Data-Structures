#include <stdio.h>

void doubleArray(int *pA, int size) {
  for (int i = 0; i < size; i++) {
    pA[i] *= 2;
  }
}

int main() {

  int A[] = {1, 2, 3, 4, 5};
  int size = sizeof(A) / sizeof(int);
  doubleArray(A, size);

  for (int i = 0; i < size; i++) {
    printf("%d", A[i]);
  }

  printf("Hello uwu!");
  return 0;
}
