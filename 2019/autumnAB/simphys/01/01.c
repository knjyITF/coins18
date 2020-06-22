#include <stdio.h>
#include <stdlib.h>

int main (void) 
{
  FILE *fo;
  char *fname;
  int i = 0;
  double x[500];
  double y[500];

  srand(149);

  //data.csvの作成
  fname = "data.csv";
  fo = fopen(fname,"w");
  if (fo == NULL)
  {
    printf("File[%s] dose not open!!\n", fname);
		exit(0);
  }

  //x^2+y^2<=1を満たすxとyの組500個の作成
  while (i < 500)
  {
    double X = 2*((double)rand()/RAND_MAX) - 1;
    double Y = 2*((double)rand()/RAND_MAX) - 1;
    if ((X*X + Y*Y) <= 1)
    {
      x[i] = X;
      y[i] = Y;
      i++;
    }
  }

  //作成した乱数の組をcsv出力
  for (int i = 0; i <= 500;i++)
  {
		fprintf(fo, "%f,%f\n", x[i], y[i]);
	}

  fclose(fo);
  printf("finish");
  return 0;
}