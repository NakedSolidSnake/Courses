#include <stdio.h>
#include <stdlib.h>

int m_strlen(const char *string);

int main(int argc, char *argv[])
{
  if(argc != 2){
    printf("./EX02 <string>\n");
  }
  printf("%s size = %d\n", argv[1], m_strlen(argv[1]));

  return EXIT_SUCCESS;
}

int m_strlen(const char *string)
{
  int count = 0;
  while(*string++ != '\0'){
    count++;
  }

  return count;
}
