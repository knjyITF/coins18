#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int boarder = RAND_MAX/2;
  int count_big = 0;
  int count_small = 0;
  srand(atoi(argv[1]));

  for (int i=0; i < 100000; i++) {
    if (rand() > boarder) {
      count_big++;
    } else {
      count_small++;
    }
  }
  printf("%d%s%d\n", count_big, " ", count_small);
}