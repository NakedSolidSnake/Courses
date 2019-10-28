#include <stdio.h>
#include <stdlib.h>

struct dma{
  int dia;
  int mes;
  int ano;
};

int getDias(struct dma data1, struct dma data2);
static long long  getSegundos(struct dma data);

int main(int argc, char *argv[])
{
  struct dma data1 = {
    .dia = 22,
    .mes = 10,
    .ano = 2019
    
  };

  printf("%lld\n", getSegundos(data1));

  return EXIT_SUCCESS;
}

int getDias(struct dma data1, struct dma data2)
{

}

static long long getSegundos(struct dma data)
{
  long long seg = data.dia * 86400;
  seg += (data.mes * 2628000);
  seg += (data.ano * 31540000);

  return seg;
}
