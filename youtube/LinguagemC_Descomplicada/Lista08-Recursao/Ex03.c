#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static double cube(double val);


int main(int argc, char *argv[])
{
  double val = 3.0;
  printf("%lf : %lf\n", val, cube(val));

  return EXIT_SUCCESS;
}

static double cube(double val)
{
  if(val == 0)
    return 0;
  else{
    return pow(val, 3.0) + cube(val - 1);
  }
}
