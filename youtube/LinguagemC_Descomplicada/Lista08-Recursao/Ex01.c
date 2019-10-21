#include <stdio.h>
#include <stdlib.h>

int sum(int val);

int main(int argc, char *argv[])
{
  int i = 3;
  printf("sum : %d\n", sum(i));

  return EXIT_SUCCESS;
}

int sum(int val)
{
  if(val == 0)
    return 0;
  else
    return val + (sum(val - 1));
}
