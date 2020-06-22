#include <stdio.h>

#define N 100

int main(void)
{
  double a[N][N], b[N][N], c[N][N], tmp;
  int i, j, k, m, n;

  scanf("%d", &m);

  for (i = 0; i < m; i++)
  {
    for (j = 0; j < m; j++)
    {
      a[i][j] = 0.0;
      b[i][j] = 0.0;
    }
  }

  for (i = 0; i < m; i++)
  {
    for (j = 0; j < m; j++)
    {
      scanf("%lf", &a[i][j]);
    }
  }

  scanf("%d", &n);

  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
    {
      c[i][j] = 0.0;
    }
  }

  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
    {
      scanf("%lf", &c[i][j]);
    }
  }

  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
    {
      b[i][j] = a[i][j] * c[i][j];
    }
  }

  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
    {
      tmp = 0;
      for (k = 0; k < n; k++)
        tmp = tmp + a[i][k] * c[k][j];
      b[i][j] = tmp;
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