#include <stdio.h>

extern int sum(int, int *);

int main(void)
{
  int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  printf("%d\n", sum(10, a));
  return 0;
}
