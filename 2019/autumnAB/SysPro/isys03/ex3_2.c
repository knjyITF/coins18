#include <stdio.h>

int my_strncasecmp(char *s1, char *s2, int n)
{
  char c1, c2;
  for (int i = 0; i < n; i++)
  {
    c1 = *s1;
    c2 = *s2;

    if (c1 >= 'A' && c1 <= 'Z')
    {
      c1 = c1 - 'A' + 'a';
    }
    if (c2 >= 'A' && c2 <= 'Z')
    {
      c2 = c2 - 'A' + 'a';
    }

    if (c1 < c2)
    {
      return -1;
    }
    else if (c1 > c2)
    {
      return 1;
    }
    else
    {
      if (c1 == '\0')
      {
        return 0;
      }
    }

    s1++;
    s2++;
  }
  return 0;
}

int main(int argc, char *argv[])
{
  printf("\"%s\" \"%s\" %d: %d\n", "a", "A", 1, my_strncasecmp("a", "A", 1));
  printf("\"%s\" \"%s\" %d: %d\n", "a", "B", 1, my_strncasecmp("a", "B", 1));
  printf("\"%s\" \"%s\" %d: %d\n", "abc", "abc", 3, my_strncasecmp("abc", "abc", 3));
  printf("\"%s\" \"%s\" %d: %d\n", "abc", "abc", 10, my_strncasecmp("abc", "abc", 10));
  printf("\"%s\" \"%s\" %d: %d\n", "abc", "ABC", 10, my_strncasecmp("abc", "ABC", 10));
  printf("\"%s\" \"%s\" %d: %d\n", "abc", "ABD", 3, my_strncasecmp("abc", "ABD", 3));
  printf("\"%s\" \"%s\" %d: %d\n", "abc", "ABD", 10, my_strncasecmp("abc", "ABD", 10));
  printf("\"%s\" \"%s\" %d: %d\n", "abd", "ABC", 3, my_strncasecmp("abd", "ABC", 3));
  printf("\"%s\" \"%s\" %d: %d\n", "abd", "ABC", 10, my_strncasecmp("abd", "ABC", 10));
  printf("\"%s\" \"%s\" %d: %d\n", "TsUkUbA", "tSuKuBa", 7, my_strncasecmp("TsUkUbA", "tSuKuBa", 7));
  printf("\"%s\" \"%s\" %d: %d\n", "IbArAgI", "iBaRaKi", 10, my_strncasecmp("IbArAgI", "iBaRaKi", 10));
  printf("\"%s\" \"%s\" %d: %d\n", "IbArAkI", "iBaRaGi", 10, my_strncasecmp("IbArAkI", "iBaRaGi", 10));
  printf("\"%s\" \"%s\" %d: %d\n", "IbArAgI", "iBaRaKi", 5, my_strncasecmp("IbArAgI", "iBaRaKi", 5));
  printf("\"%s\" \"%s\" %d: %d\n", "IbArAkI", "iBaRaGi", 5, my_strncasecmp("IbArAkI", "iBaRaGi", 5));
  printf("\"%s\" \"%s\" %d: %d\n", "", "", 10, my_strncasecmp("", "", 10));
  printf("\"%s\" \"%s\" %d: %d\n", "abc", "", 10, my_strncasecmp("abc", "", 10));
  printf("\"%s\" \"%s\" %d: %d\n", "", "def", 10, my_strncasecmp("", "def", 10));
  return 0;
}