#include <util/util.h>
#include <stdio.h>
#include <stdlib.h>

void dieWithError(char *errorMessage)
{
  perror(errorMessage);
  exit(1);
}
