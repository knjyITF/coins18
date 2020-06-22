#include <stdio.h>

int main(void)
{
  int n, tmp;
  int digit, ans;

  scanf("%d", &n);

  ans = 0;
  tmp = n;
  digit = 0;

  do
  {
    tmp /= 10;
    digit++;
  } while (tmp > 0);

  for (int i = 1; i <= digit; i++)
  {
    tmp = n / (10 ^ (digit - i));
    ans = ans + (tmp * (10 ^ (i - 1)));
  }

  printf("%d\n", &ans);

  return 0;
}
