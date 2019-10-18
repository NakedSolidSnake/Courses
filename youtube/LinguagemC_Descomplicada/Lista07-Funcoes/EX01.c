#include <stdio.h>
#include <stdlib.h>

static int dobro(int num);

int main(int argc, char *argv[])
{
  int val = 2;
  printf("dobro de %d = %d\n", val, dobro(val));

  return EXIT_SUCCESS;
}

static int dobro(int num)
{
  return num * 2;
}
