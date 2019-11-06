#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  FILE *fd_in, *fd_out;
  char *b = NULL;

  fd_in = fopen("arq28.txt", "r");
  if(!fd_in){
    perror("file doesn't exist.");
    return 1;
  }

  fseek(fd_in, 0 , SEEK_END);
  long file_size = ftell(fd_in);
  rewind(fd_in);

  printf("File size : %ld\n", file_size);

  b = (char *)malloc(sizeof(char) * file_size + 1);

  if(!b){
    perror("It wasn't possible allocate memory.");
    
  }else{
    fread(b, sizeof(char), file_size, fd_in );

    fd_out = fopen("out.txt", "w");
    if(!fd_out){
      perror("Cannot open the file.");
    }else{
      for(int i = file_size; i > 0; i--){
        fputc(b[i - 1], fd_out);
      }

      fclose(fd_out);
    }
    
  }


  free(b);
  fclose(fd_in);

  return EXIT_SUCCESS;
}
