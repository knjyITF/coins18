#include <stdio.h>

int main(void)
{
  char str1[100], str2[100];
  int i, j;

  scanf("%s", str1);

  i = 0;
  j = 0;

  do {
    i++;
  } while (str1[i] != '\0');

  do {
    str2[i - j] = str1[j - 1];
    j++;
  } while (j <= i);
  
  str2[i+1] = '\0';

  printf("%s\n", str2);

  return 0;
}