#include <stdio.h>

#define N 100

int main(void)
{
  double a[N][N], b[N][N], tmp;
  int i, j, k, n;

  scanf("%d", &n);

  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
    {
      a[i][j] = 0.0;
      b[i][j] = 0.0;
    }
  }

  for (i = 0; i < n; i++)
  {
    b[i][i] = 1.0;
  }

  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
    {
      scanf("%lf", &a[i][j]);
    }
  }

  for (k = 0; k < n; k++)
  {
    tmp = a[k][k];
    for (i = 0; i < n; i++)
    {
      a[k][i] /= tmp;
      b[k][i] /= tmp;
    }
    for (i = 0; i < n; i++)
    {
      if (i != k)
      {
        tmp = a[i][k];
        for (j = 0; j < n; j++)
        {
          a[i][j] -= a[k][j] * tmp;
          b[i][j] -= b[k][j] * tmp;
        }
      }
    }
  }

  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
    {
      printf("%f ", b[i][j]);
    }
    printf("\n");
  }

  return 0;
}