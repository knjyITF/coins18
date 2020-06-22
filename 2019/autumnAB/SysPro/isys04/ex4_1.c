#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct record
{
  int number;
  char name[256 + 1];
  int point;
  struct record *next;
};

struct record *head = NULL;

void insert_list(int no, char *nam, int pnt)
{
  struct record *p, *q, *t;

  t = (struct record *)malloc(sizeof(struct record));
  if (t == NULL)
  {
    fprintf(stderr, "Out of memory\n");
    exit(1); /* Terminate the program with the exit status */
  }
  t->number = no;
  strcpy(t->name, nam);
  t->point = pnt;

  q = NULL;
  for (p = head; p != NULL; p = p->next)
  {
    if (strcmp(p->name, nam) >= 0)  //ここで名前順に変える
    {
      break;
    }
    q = p;
  }

  if (q != NULL)
  {
    q->next = t;
  }
  else
  {
    head = t;
  }
  t->next = p;
}

int main(int argc, char *argv[])
{
  FILE *fp;
  int nlines, i;
  int no, pnt;
  char nam[256 + 1], buf[1024 + 1];
  struct record *p;

  if (argc != 2)
  {
    fprintf(stderr, "Missing file argument\n");
    return 1;
  }

  if ((fp = fopen(argv[1], "r")) == NULL)
  {
    fprintf(stderr, "Can't open %s\n", argv[1]);
    return 1;
  }

  if (fgets(buf, sizeof(buf), fp) == NULL)
  {
    fprintf(stderr, "Can't read input data\n");
    return 1;
  }
  if (sscanf(buf, "%d", &nlines) != 1)
  {
    fprintf(stderr, "Invalid input data\n");
    return 1;
  }

  for (i = 0; i < nlines; i++)
  {
    if (fgets(buf, sizeof(buf), fp) == NULL)
    {
      fprintf(stderr, "Can't read input data\n");
      return 1;
    }
    if (sscanf(buf, "%d %s %d", &no, nam, &pnt) != 3)
    {
      fprintf(stderr, "Invalid input data\n");
      return 1;
    }
    insert_list(no, nam, pnt);
  }

  fclose(fp);

  for (p = head; p != NULL; p = p->next)
  {
    printf("%d %s %d\n", p->number, p->name, p->point);
  }

  return 0;
}