#include <stdio.h>

extern int *make_allone_array(int);

int main(void)
{
  int *v;
  int n = 10;
  int i;

  v = make_allone_array(n);

  for (i = 0; i < n; i++) {
    printf("%d ", v[i]);
  }
  printf("\n");

  /* Set the environment variable MALLOC_CHECK_ to 0 if you want to free it.
 *      free(v); */

  return 0;
}
