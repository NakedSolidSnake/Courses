#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Endereco{
  char rua[80];
  char estado[9];
  char bairro[80];
  char cidade[40];
  char cep[20];
};

struct Cadastro{
  char nome[80];
  struct Endereco end;
  double salario;
  char identidade[20];
  char cpf[20];
  unsigned char estado_civil;
  char telefone[30];
  int idade;
  char sexo;
};

//b)
struct Cadastro **preencheCadastro(int size);
//c)
struct Cadastro *getMaiorIdade(struct Cadastro **cadastro, int size);
//d)
int getMasculino(struct Cadastro **cadastro, int size);
//e)
int getSalario(struct Cadastro **cadastro, int size);
//f)
int imprimeCadastro(struct Cadastro **cadastro, int size, const char *rg);
int imprimeTodosCadastros(struct Cadastro **cadastro, int size);

static int imprime(struct Cadastro *cadastro);

int main(int argc, char *argv[])
{
  struct Cadastro **cads;
  int amount = 0;
  char *p = NULL;
  char rg[15];

  if(argc != 2){
    printf("Usage: ./Ex22 register_number\n");
    printf("E.g: ./Ex22 5\n");
    return 1;
  }

  p = argv[1];

  while(*p != '\0'){
    if(!isdigit(*p)){
      printf("Is not a number.\n");
      return 1;
    }
    p++;
  }
  amount = atoi(argv[1]);

  cads = preencheCadastro(amount);
  if(cads == NULL){
    printf("It wasn't possible to allocate memory.\n");
    return 1;
  }

  struct Cadastro *cadMaior = getMaiorIdade(cads, amount);
  printf("Maior idade: %d\n", cadMaior->idade);

  printf("Entre com o rg: ");
  fgets(rg, sizeof(rg), stdin);

  imprimeCadastro(cads, amount, rg);

  getMasculino(cads, amount);

  getSalario(cads, amount);

  imprimeTodosCadastros(cads, amount);




  for(int i = 0; i < amount; i++){
    free(cads[i]);
  }
  free(cads);

  return EXIT_SUCCESS;
}

struct Cadastro **preencheCadastro(int size)
{

  struct Cadastro **cad = (struct Cadastro **)malloc(sizeof(struct Cadastro *) * size);
  if(cad == NULL){
    return NULL;
  }

  for(int i = 0; i < size; i++)
  {
    cad[i] = (struct Cadastro *)malloc(sizeof(struct Cadastro));
    if(cad[i] == NULL){
      return NULL;
    }
  }

  for(int i = 0; i < size; i++)
  {
    
    printf("Entre com o nome: ");
    fgets(cad[i]->nome, sizeof(cad[i]->nome),stdin); 

    printf("Entre com a rua: ");
    fgets(cad[i]->end.rua, sizeof(cad[i]->end.rua), stdin);

    printf("Entre com o estado: ");
    fgets(cad[i]->end.estado, sizeof(cad[i]->end.estado), stdin);

    printf("Entre com o bairro: ");
    fgets(cad[i]->end.bairro, sizeof(cad[i]->end.bairro), stdin);

    printf("Entre com o cidade: ");
    fgets(cad[i]->end.cidade, sizeof(cad[i]->end.cidade), stdin);

    printf("Entre com o CEP: ");
    fgets(cad[i]->end.cep, sizeof(cad[i]->end.cep), stdin);

    printf("Entre com o salario: ");
    scanf("%lf", &cad[i]->salario);

    getchar();
    printf("Entre com a identidade:");
    fgets(cad[i]->identidade, sizeof(cad[i]->identidade), stdin);
    
    printf("Entre com a cpf:");
    fgets(cad[i]->cpf, sizeof(cad[i]->cpf), stdin);

    printf("Entre com o estado civil: [1]->Solteiro, [2]->casado :");
    scanf("%d", &cad[i]->estado_civil);
    getchar();

    printf("Entre com o telefone:");
    fgets(cad[i]->telefone, sizeof(cad[i]->telefone), stdin);

    printf("Entre com a idade: ");
    scanf("%d", &cad[i]->idade);
    getchar();

    printf("Entre com o sexo: ");
    scanf("%c", &cad[i]->sexo);
    getchar();

  }
  
  return cad;
}

struct Cadastro *getMaiorIdade(struct Cadastro **cadastro, int size)
{
  int idx_maior = 0;
  int idade_temp = 0;
  for(int i = 0; i < size; i++){
    if(idade_temp < cadastro[i]->idade){
      idade_temp = cadastro[i]->idade;
      idx_maior = i;
    }
  }

  return cadastro[idx_maior];
}

int getMasculino(struct Cadastro **cadastro, int size)
{
  for(int i = 0; i < size; i++){
    if(toupper(cadastro[i]->sexo) == 'M'){
      imprime(cadastro[i]);
    }
  }
  
  return 0;
}

int getSalario(struct Cadastro **cadastro, int size)
{
 for(int i = 0; i < size; i++){
  if(cadastro[i]->salario > 1000)
    imprime(cadastro[i]);
 } 
  return 0;
}

int imprimeCadastro(struct Cadastro **cadastro, int size, const char *rg)
{
  for(int i = 0; i < size; i++)
  {
    if(!strcmp(cadastro[i]->identidade, rg)){
      imprime(cadastro[i]);
      break;
    }
  }
}

int imprimeTodosCadastros(struct Cadastro **cadastro, int size)
{
  for(int i = 0; i < size; i++){
    imprime(cadastro[i]);
  }
}


static int imprime(struct Cadastro *cadastro){
  printf("Nome: %s",cadastro->nome);
  printf("Rua: %s",cadastro->end.rua);
  printf("Estado: %s",cadastro->end.estado);
  printf("Bairro: %s",cadastro->end.bairro);
  printf("Cidade: %s",cadastro->end.cidade);
  printf("CEP: %s",cadastro->end.cep);
  printf("Salario: %lf\n",cadastro->salario);
  printf("RG: %s",cadastro->identidade);
  printf("CPF: %s",cadastro->cpf);
  printf("Estado civil : %s\n",cadastro->estado_civil == 1? "Solteiro" : "Casado" );
  printf("Telefone: %s",cadastro->telefone);
  printf("Idade: %d\n",cadastro->idade);
  printf("Sexo: %c\n",cadastro->sexo);
  return 0;
}
