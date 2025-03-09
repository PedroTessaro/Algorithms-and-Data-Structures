#include <stdio.h>
#include <stdlib.h>

int compare(int a, int b) {
  if (a > b)
    return 1;
  else
    return -1;
}

int absolute_compare(int a, int b) {
  if (abs(a) > abs(b))
    return 1;
  return -1;
}

void sort(int *A, int n, int (*compare)(int, int)) {
  int temp;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - 1; j++) {
      if (compare(A[j], A[j + 1]) > 0) {
        temp = A[j];
        A[j] = A[j + 1];
        A[j + 1] = temp;
      }
    }
  }
}

int main() {
  int A[] = {3, 2, 1, 5, 6, 4};
  sort(A, 6, compare);
  for (int i = 0; i < 6; i++) {
    printf("%d ", A[i]);
  }

  return 0;
}
