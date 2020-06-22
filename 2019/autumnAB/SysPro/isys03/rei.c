#include <stdio.h>

int my_strcmp(char *s1, char *s2)
{
  char c1, c2;
  while (1) {
    c1 = *s1;
    c2 = *s2;
    if (c1 < c2) {
      return -1;
    } else if (c1 > c2) {
      return 1;
    } else {
      if (c1 == '\0') {
        return 0;
      }
    }
    s1++;
    s2++;
  }
}

int main(int argc, char *argv[])
{
  printf("\"%s\" \"%s\": %d\n", "abc", "def",         my_strcmp("abc", "def"));
  printf("\"%s\" \"%s\": %d\n", "def", "abc",         my_strcmp("def", "abc"));
  printf("\"%s\" \"%s\": %d\n", "Ibaragi", "Ibaraki", my_strcmp("Ibaragi", "Ibaraki"));
  printf("\"%s\" \"%s\": %d\n", "Ibaraki", "Ibaragi", my_strcmp("Ibaraki", "Ibaragi"));
  printf("\"%s\" \"%s\": %d\n", "Tsukuba", "Tsukuba", my_strcmp("Tsukuba", "Tsukuba"));
  printf("\"%s\" \"%s\": %d\n", "$$$", "$$$",         my_strcmp("$$$", "$$$"));
  printf("\"%s\" \"%s\": %d\n", "pqr", "pqrstu",      my_strcmp("pqr", "pqrstu"));
  printf("\"%s\" \"%s\": %d\n", "vwxyz", "vw",        my_strcmp("vwxyz", "vw"));
  printf("\"%s\" \"%s\": %d\n", "", "",               my_strcmp("", ""));
  printf("\"%s\" \"%s\": %d\n", "abc", "",            my_strcmp("abc", ""));
  printf("\"%s\" \"%s\": %d\n", "", "def",            my_strcmp("", "def"));
  return 0;
}