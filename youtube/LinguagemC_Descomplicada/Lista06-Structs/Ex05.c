#include <stdio.h>
#include <stdlib.h>

struct Vetor{
  float x;
  float y;
  float z;
};

static struct Vetor soma(struct Vetor a, struct Vetor b);

int main(int argc, char *argv[])
{
  struct Vetor a = {
    .x = 1,
    .y = 2,
    .z = 3
  };

  struct Vetor b = {
    .x = 6,
    .y = 10,
    .z = 12
  };

  struct Vetor r = soma(a, b);

  printf("Vetor(%f,%f,%f)\n", r.x, r.y, r.z);

  return EXIT_SUCCESS;
}

static struct Vetor soma(struct Vetor a, struct Vetor b)
{
  struct Vetor r;

  r.x = a.x + b.x;
  r.y = a.y + b.y;
  r.z = a.z + b.z;

  return r;
}
