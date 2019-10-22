#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  if(argc != 2){
    return 1;
  }

  char *string = argv[1];
  int no_1 = 0;

  while(*string){
    if(*string == '1'){
      no_1++;
    }
    string++;
  }

  printf("Numbers of 1 : %d\n", no_1);
  
  return EXIT_SUCCESS;
}
