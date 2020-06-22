#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  FILE *fo;
  char *fname;

  int nm, ni, ix, iy, i;
  double p1, p2, G;
  G = 1.0;
  ni = 30;
  nm = 2;
  double phi[nm + 2][nm + 2];
  double ro[nm + 2][nm + 2];

  for (ix = 0; ix <= nm + 1; ix++)
  { /* nm：1軸当たりの格子点数*/
    for (iy = 0; iy <= nm + 1; iy++)
    {
      phi[ix][iy] = 0.0;
      ro[ix][iy] = 6.0 * ix - 3.0 * iy;
    }
  }

  phi[1][3] = 22.5;
  phi[2][3] = 36.0;
  phi[3][1] = -4.5;
  phi[3][2] = 9.0;

  for (i = 1; i <= ni; i++)
  { /* ni：反復回数*/
    for (ix = 1; ix <= nm; ix++)
    {
      for (iy = 1; iy <= nm; iy++)
      {
        p1 = phi[ix + 1][iy] + phi[ix - 1][iy] + phi[ix][iy + 1] + phi[ix][iy - 1];
        p2 = G * ro[ix][iy]; /* G：定数*/
        phi[ix][iy] = p1 / 4 - p2 / 4;
      }
    }
  }

  printf("%f ", phi[1][1]);
  printf("%f\n", phi[1][2]);
  printf("%f ", phi[2][1]);
  printf("%f\n", phi[2][2]);
  return 0;
}