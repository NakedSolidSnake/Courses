#include <stdio.h>
#include <stdlib.h>

static int fatorial(int n);

int main(int argc, char *argv[])
{
  int i = 5;
  printf("fatorial : %d = %d\n", i, fatorial(i));

  return EXIT_SUCCESS;
}

static int fatorial(int n)
{
  if(n == 1)
    return 1;
  else
    return n * fatorial(n - 1);
}
