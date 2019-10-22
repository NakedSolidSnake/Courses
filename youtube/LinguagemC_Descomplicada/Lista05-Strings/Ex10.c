#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
  
  if(argc != 2){
    return -1;
  }

  char *p = argv[1];
  int size = strlen(p);


  char *str = (char *)malloc(sizeof(char) * size + 1);
  for(int i = 0; i < size; i++)
  {
    str[i] = p[size - i - 1];
  }

  str[size] = '\0';


  printf("Inverted: %s\n", str);

  return EXIT_SUCCESS;
}

