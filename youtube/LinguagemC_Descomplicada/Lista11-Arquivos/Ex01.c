#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  char c = 'A';
  FILE *fd = fopen("arq.txt", "w");
  if(!fd)
    return 1;

  while(c != '0'){
    c = getchar();
    fprintf(fd, "%c", c); 
  }

  fclose(fd);

  fd = fopen("arq.txt", "r");
  if(!fd)
    return 1;

  do{
    c = getc(fd); 
    printf("%c", c);
  }while(c != EOF);

  
  return EXIT_SUCCESS;
}
