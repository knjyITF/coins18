#include <stdio.h>
#include <stdlib.h>

int main (void) 
{
  int k = 0;
  int p = 10000; //乱数の数
  double dot = 0;
  double ans = 0, ave = 0, dif = 0;

  srand(149);

  //ヒットミス法
  for (int i = 0; i < 10; i++) {
    k = 0;
    dot = 0;
		while (k <= p) {
			double X = 2 *((double)rand() / RAND_MAX) - 1;
			double Y = 2 *((double)rand() / RAND_MAX) - 1;
			if ((X * X + Y * Y) < 1) {
				dot++;
			}
			k++;
		}
		ans = ans + (2 * 2 * (dot / p));
	}

  ave = ans / 10; //面積の平均値(10試行)
  dif = (3.14159 - ave)/3.14159;

  printf("%f,%f\n", ave,dif);

	return 0;
}