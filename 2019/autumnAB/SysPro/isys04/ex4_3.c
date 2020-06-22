#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct record {
  char word[64 + 1];
  int count;
  struct record *next;
};

struct record *head = NULL;

int read_word_from_file(FILE *fp, char *word);
void add_word_to_list(char *word);

int main(int argc, char *argv[])
{
  FILE *fp;
  char word[64 + 1];
  struct record *p;

  if (argc != 2) {
    fprintf(stderr, "Missing file argument\n");
    return 1;
  }
  
  if ((fp = fopen(argv[1], "r")) == NULL) {
    fprintf(stderr, "Can't open %s\n", argv[1]);
    return 1;
  }

  while (read_word_from_file(fp, word)) {
    add_word_to_list(word);
  }

  fclose(fp);

  for (p = head; p != NULL; p = p->next) {
    printf("%s %d\n", p->word, p->count);
  }

  return 0;
}