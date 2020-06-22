#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
  FILE *fo;
  char *fname;

  int nk = 20;

  int i = 0;
  double x0[500];
  double y0[500];
  double vx[500];
  double vy[500];
  double x[500];
  double y[500];
  double G = 1.0;
  double M = 1.0;
  double H = 3.5;
  double org = 50;
  double dt = 0.1;
  double dx = 1.0;
  double dy = 1.0;
  double Fpx,Fpy;

  int nm = 99;
  int ni = 50;

  double phi[nm + 2][nm + 2];
  double ro[nm + 2][nm + 2];
  double Fx[nm + 2][nm + 2];
  double Fy[nm + 2][nm + 2];

  double p1, p2;
  int ix, iy;

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

  //ポテンシャルφとρの初期値を設定(ゼロ)
  for (int ix = 0; ix < nm + 2; ix++)
  {
    for (int iy = 0; iy < nm + 2; iy++)
    {
      phi[ix][iy] = 0.0;
      ro[ix][iy] = 0.0;
    }
  }

  //時間ステップ数ループ
  for (int i = 0; i < nk; i++)
  {
    //質量密度ρの計算(NGP法)
    for (int j = 0; j < 500; j++)
    {
      ro[(int)round(x[j])][(int)round(y[j])] += M;
    }

    //ポテンシャルφを計算(ガウス・ザイデル法)
    for (i = 1; i <= ni; i++)
    { /* ni：反復回数*/
      for (ix = 1; ix <= nm; ix++)
      {
        for (iy = 1; iy <= nm; iy++)
        {
          p1 = phi[ix + 1][iy] + phi[ix - 1][iy] + phi[ix][iy + 1] + phi[ix][iy - 1];
          p2 = G * ro[ix][iy]*dx*dx; /* G：定数*/
          phi[ix][iy] = p1 / 4 - p2 / 4;
        }
      }
    }

    //重力場Fを計算
    for (ix = 1; ix <= nm; ix++)
    {
      for (iy = 1; iy <= nm; iy++)
      {
        Fx[ix][iy] = -(phi[ix+1][iy]-phi[ix][iy])/dx;
        Fy[ix][iy] = -(phi[ix][iy+1]- phi[ix][iy])/dy;
      }
    }
  }
  //天体の運動
  for (int ip = 1; ip <= 500; ip++)
  {
    Fpx = M * Fx[(int)round(x[ip])][(int)round(y[ip])];
    Fpy = M * Fy[(int)round(x[ip])][(int)round(y[ip])];

    vx[ip] = vx[ip] + (Fpx/M) * dt;
    vy[ip] = vy[ip] + (Fpy/M) * dt;

    x[ip] = x[ip] + vx[ip] * dt;
    y[ip] = y[ip] + vy[ip] * dt;
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