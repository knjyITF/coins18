#include <stdio.h>
#include <stdlib.h>

int euclid(int a, int b)
{
  int c = a % b;
  if (c != 0)
  {
    euclid(b, c);
  }
  else
  {
    return b;
  }
}

int main(int argc, char *argv[])
{
  int a = atoi(argv[1]);
  int b = atoi(argv[2]);

  if (argc != 3 || a <= 0 || b <= 0)
  {
    fprintf(stderr, "Invalid input.");
  }

  int c = euclid(a, b);
  printf("%d\n", c);

  return 0;
}