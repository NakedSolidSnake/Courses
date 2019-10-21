#include <stdio.h>
#include <stdlib.h>

static int potencia(int k, int n);

int main(int argc, char *argv[])
{
  int base = 2, pot = 8;

  printf("Resul: %d\n", potencia(base, pot));
  
  return EXIT_SUCCESS;
}

static int potencia(int k, int n)
{
  if(n == 0)
    return 1;
  else
    return k * potencia(k, n - 1);
}


