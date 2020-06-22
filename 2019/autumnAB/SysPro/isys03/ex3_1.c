#include <stdio.h>

void calc_sum_max_min(int *sump, int *maxp, int *minp, int *items, int nitems)
{
  *sump = items[0];
  *maxp = items[0];
  *minp = items[0];

  int min = *minp;
  int max = *maxp;

  for (int i = 1; i < 10; i++)
  {
    *sump = *sump + items[i];
    if (max < items[i])
    {
      max = items[i];
    }
    if (min > items[i])
    {
      min = items[i];
    }
  }
  *maxp = max;
  *minp = min;
}

int main(void)
{
  int a[10] = {80, 36, -55, 17, 22, -71, 60, 97, 34, -14};
  int n = 10;
  int sum, max, min;
  calc_sum_max_min(&sum, &max, &min, a, n);
  printf("sum = %d\n", sum);
  printf("max = %d\n", max);
  printf("min = %d\n", min);
  return 0;
}