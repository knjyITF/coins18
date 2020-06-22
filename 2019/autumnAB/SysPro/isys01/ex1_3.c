#include <stdio.h>

int main(void)
{
  char str1[100], str2[100];
  char out[100];

  scanf("%s", str1);
  scanf("%s", str2);

  int n = 0;

  for (int i = 0; str1[i] != '\0'; i++)
  {
    for (int j = 0; str2[j] != '\0'; j++)
    {
      if (str1[i] == str2[j])
      {
        out[n] = str1[i];
        n++;
      }
    }
  }

  out[n+1] = '\0';

  printf("%s\n",out);

  return 0;
}