#include <stdio.h>

int main(int argc, char *argv[])
{
  int ch, count, N;
  FILE *fp;

  /* コマンドライン引数が1つ指定されているかどうか確認する */
  if (argc != 3)
  {
    fprintf(stderr, "Missing file argument\n");
    return 1;
  }
  N = atoi(argv[1]);
  if ((fp = fopen(argv[2], "r")) == NULL)
  { /* ファイルのオープン */
    fprintf(stderr, "Can't open %s\n", argv[1]);
    return 1;
  }
  count = 1;
  while ((ch = fgetc(fp)) != EOF)
  { /* 1文字ずつ読み込む */
    if (ch == '\n')
    { /* 読んだ文字は改行か？ */
      count++;
    }
    else
    {
      if (count == N)
      {
        printf("%c", ch);
      }
    }
  }

  //printf("%d lines\n", count);
  fclose(fp); /* ファイルのクローズ */

  return 0;
}