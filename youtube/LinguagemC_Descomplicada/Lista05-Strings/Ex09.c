#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

  if(argc != 2){
    return -1;
  }

  char *p = argv[1];

  while(*p){
  
    if(*p == '0'){
      *p = '1';
    }
    p++;
  }

  printf("Out string: %s\n", argv[1]);

  return EXIT_SUCCESS;
}

