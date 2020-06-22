#include <stdio.h>

int main(int argc, char *argv[])
{
  int ch;
  FILE *sfp, *dfp;

  /* コマンドライン引数が2つ指定されているかどうか確認する */
  if (argc != 3)
  {
    fprintf(stderr, "Missing file argument\n");
    return 1;
  }

  if ((sfp = fopen(argv[1], "r")) == NULL)
  { /* コピー元ファイルのオープン */
    fprintf(stderr, "Can't open %s\n", argv[1]);
    return 1;
  }

  if ((dfp = fopen(argv[2], "w")) == NULL)
  { /* コピー先ファイルのオープン */
    fprintf(stderr, "Can't open %s\n", argv[2]);
    fclose(sfp); /* コピー元ファイルのクローズ */
    return 1;
  }

  while ((ch = fgetc(sfp)) != EOF)
  {
    if ('a' <= ch && ch <= 'z')
    {
      fputc(ch - 32, dfp); /* 大文字への変換(32 = (int) A - (int) a) */
    }
    else
    {
      fputc(ch, dfp);
    }
  }

  fclose(dfp); /* コピー先ファイルのクローズ */
  fclose(sfp); /* コピー元ファイルのクローズ */

  return 0;
}