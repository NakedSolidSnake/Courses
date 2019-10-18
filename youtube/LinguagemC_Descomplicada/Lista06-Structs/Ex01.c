#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Horario{
  unsigned char hora;
  unsigned char min;
  unsigned char seg;
};

struct Data{
  unsigned char dia;
  unsigned char mes;
  unsigned int ano;
};

struct Compromisso{
  struct Horario h;
  struct Data d;
  char desc[100];
};

static int getCompromisso(struct Compromisso *comp);
static int getData(struct Data *data);
static int getHorario(struct Horario *hor);
static int validaData(struct Data *data);
static int validaHora(struct Horario *hora);
static int printCompromisso(struct Compromisso comp);


int main()
{
  struct Compromisso c;

  getCompromisso(&c);
  printCompromisso(c);


  return 0;
}

static int getCompromisso(struct Compromisso *comp)
{
  int ret = -1;
  if(!comp)
    return -1;

  if(getData(&comp->d))
    return -1;

  if(getHorario(&comp->h))
    return -1;

  getchar();

  printf("Digite o compromisso.: ");
  fgets(comp->desc, sizeof(comp->desc), stdin);
  return 0;

}

static int getData(struct Data *data)
{
  if(!data)
    return -1;
  do{
    printf("Entre com o dia: ");
    scanf("%d", &data->dia);

    printf("Entre com o mes: ");
    scanf("%d", &data->mes);

    printf("Entre com o ano: ");
    scanf("%d", &data->ano);
  }while(validaData(data));
  return 0;
}

static int getHorario(struct Horario *hor)
{
  if(!hor)
    return -1;
  do{
    printf("Entre com a hora: ");
    scanf("%d", &hor->hora);

    printf("Entre com os minutos: ");
    scanf("%d", &hor->min);

    printf("Entre com os segundos: ");
    scanf("%d", &hor->seg);
  }while(validaHora(hor));
  return 0;
}

static int validaData(struct Data *data)
{
  int ret = 0;
  
  if(data->dia > 31)
    return 1;
  else if(data->mes > 12)
    return 1;
  else if(data->ano < 2019)
    return 1;

  return ret;
}

static int validaHora(struct Horario *hora)
{
  int ret = 0;
  if(hora->hora > 23)
    return 1;
  else if(hora->min > 59)
    return 1;
  else if(hora->seg > 59)
    return 1;

  return ret;
}

static int printCompromisso(struct Compromisso comp)
{

  printf("Compromisso registrado.\n");
  printf("Data: %d/%d/%d\n", comp.d.dia, comp.d.mes, comp.d.ano);
  printf("Hora: %d/%d/%d\n", comp.h.hora, comp.h.min, comp.h.seg);
  printf("Descricao: %s\n", comp.desc);
}

