#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int x[20][21];
  int i, t, f;
  double d;

  d = 0.7; //初期密度

  srand(149);

//初期状態の作成
  for (i = 0; i < 20; i++)
  {
    double r = (double)rand() / RAND_MAX;
    if (r < d)
    {
      x[i][0] = 1;
    }
    else
    {
      x[i][0] = 0;
    }
  }

  for (t = 1; t <= 20; t++)
  {
    for (i = 0; i < 20; i++)
    {
      f = 0;
      if (i == 0)
      {
        f = 4 * (x[19][t - 1]) + 2 * (x[0][t - 1]) + (x[1][t - 1]);
      }
      else if (i == 19)
      {
        f = 4 * (x[18][t - 1]) + 2 * (x[19][t - 1]) + (x[0][t - 1]);
      }
      else
      {
        f = 4 * (x[i - 1][t - 1]) + 2 * (x[i][t - 1]) + (x[i + 1][t - 1]);
      }

      if (f == 0 || f == 1 || f == 2 || f == 6)
      {
        x[i][t] = 0;
      }
      else
      {
        x[i][t] = 1;
      }
    }
  }

  for (t = 0; t <= 20; t++)
  {
    printf("t=%d ", t);
    for (i = 0; i < 20; i++)
    {
      printf("%d ", x[i][t]);
    }
    printf("\n");
  }
}