#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct record {
  int number;
  struct record *next;
};

struct record *head = NULL;

void insert_list(int num)
{
  struct record *cell;
  cell = (struct record *)malloc(sizeof(struct record));
  if (cell == NULL) {
    perror("malloc");
    exit(1);
  }
  cell->number = num;
  cell->next = head;
  head = cell;
}

void print_list(void)
{
  struct record *p;
  printf("[");
  for (p = head; p != NULL; p = p->next) {
    if (p != head) {
      printf(", ");
    }
    printf("%d", p->number);
  }
  printf("]\n");
}

int add1(int n)
{
  return n + 1;
}

int neg(int n)
{
  return -n;
}

int mul3(int n)
{
  return n * 3;
}

int is_odd(int n)
{
  if (n % 2 == 0) {
    return 0;
  } else {
    return 1;
  }
}

int num_of_divisors(int x)
{
  int i;
  int count = 0;
  for (i = 2; i <= x / 2; i++) {
    if (x % i == 0) {
      count++;
    }
  }
  return count + 1;
}

int id(int x)
{
  return x;
}
  
int sum_of_digits(int x)
{
  int sum = 0;
  while (x > 0) {
    sum += x % 10;
    x = x / 10;
  }
  return sum;
}

void map_func(int (*f)(int))
{
  struct record *p;
  for (p = head; p != NULL; p = p->next)
  {
    p->number = (*f)(p->number);
  }
  return;	  
}
	  
int choose_best(int (*f)(int))
{
  struct record *p;
  int best = 0;
  int now = 0;

  for (p = head; p != NULL; p = p->next)
  {
    now = (*f)(p->number);
    if (now > best)
    {
      best = now;
    }
  }
  return best;
}

int main(int argc, char *argv[])
{
  FILE *fp;
  int nlines, i, num;
  char buf[256];

  if (argc != 2) {
    fprintf(stderr, "Missing file argument\n");
    exit(1);
  }

  if ((fp = fopen(argv[1], "r")) == NULL) {
    perror("fopen");					
    fprintf(stderr, "File: %s\n", argv[1]);
    exit(1);
  }

  if (fgets(buf, sizeof(buf), fp) == NULL) {
    fprintf(stderr, "Can't read input data\n");
    exit(1);
  }
  if (sscanf(buf, "%d", &nlines) != 1) {
    fprintf(stderr, "Can't read number of items\n");
    exit(1);
  }

  for (i = 0; i < nlines; i++) {
    if (fgets(buf, sizeof(buf), fp) == NULL) {
      fprintf(stderr, "Can't read input data\n");
      exit(1);
    }
    if (sscanf(buf, "%d", &num) != 1) {
      fprintf(stderr, "Can't read data item\n");
      exit(1);
    }
    insert_list(num);
  }

  fclose(fp);

  print_list();

  printf("Best value under standard 1: %d\n", choose_best(id));
  printf("best value under standard 2: %d\n", choose_best(num_of_divisors));
  printf("best value under standard 3: %d\n", choose_best(sum_of_digits));

  map_func(add1);
  print_list();

  map_func(neg);
  print_list();

  map_func(mul3);
  print_list();

  map_func(neg);
  print_list();

  map_func(is_odd);
  print_list();

  return 0;
}