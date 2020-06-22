#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  FILE *fo;
  char *fname;
  int i = 0;
  double x0[500];
  double y0[500];
  double vx[500];
  double vy[500];
  double x[500];
  double y[500];
  double H = 3.5;
  double org = 50;
  double dt = 0.1;
  double nk = 20;

  srand(149);

  //data.csvの作成
  fname = "data.csv";
  fo = fopen(fname, "w");
  if (fo == NULL)
  {
    printf("File[%s] dose not open!!\n", fname);
    exit(0);
  }

  //x^2+y^2<=5を満たすxとyの組500個の作成
  while (i < 500)
  {
    double X = 6 * ((double)rand() / RAND_MAX) - 3;
    double Y = 6 * ((double)rand() / RAND_MAX) - 3;
    if ((X * X + Y * Y) <= 5)
    { //初速度の設定
      x0[i] = X;
      y0[i] = Y;
      i++;
    }
  }

  //天体の位置の平行移動
  for (int i = 0; i < 500; i++)
  {
    //天体の初速度を設定
    vx[i] = H * x0[i];
    vy[i] = H * y0[i];

    x[i] = x0[i] + org;
    y[i] = y0[i] + org;
  }

  //天体の新しい位置を計算
  for (int i = 0; i < nk; i++)
  {
    for (int ip = 0; ip < 500; ip++)
    {
      x[ip] = x[ip] + vx[ip] * dt;
      y[ip] = y[ip] + vy[ip] * dt;
    }
  }

  //作成したxyをcsv出力
  for (int i = 0; i <= 500; i++)
  {
    fprintf(fo, "%f,%f,%f,%f\n", x0[i], y0[i], x[i], y[i]);
  }

  fclose(fo);
  printf("finish");
  return 0;
}