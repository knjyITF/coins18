#include <stdio.h>

extern int determinant(int, int, int, int);

int main(void)
{
  int d = determinant(1, 2, 3, 4);
  printf("%d\n", d); // (1 * 4) - (2 * 3) = -2
  return 0;
}
