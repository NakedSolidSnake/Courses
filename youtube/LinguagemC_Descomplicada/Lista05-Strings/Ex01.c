#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  char string[100];

  printf("Entre com uma string:");
  fgets(string, sizeof(string), stdin);

  printf("%s\n", string);

  return EXIT_SUCCESS;
}
