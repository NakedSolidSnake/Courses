#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME  80 
#define MAX_PHONE 30
#define MAX_REGISTERS  100
#define FILE_NAME "agenda.dat"

struct Register
{
  char name[MAX_NAME];
  char phone[MAX_PHONE];
  int day;
  int month;
};

struct Registers 
{
  struct Register reg[MAX_REGISTERS];
  int nreg;
};

static int Register_insert(void);
static int Register_remove(struct Register *reg);
static int Register_find(const char *name, struct Register *reg);
static int Register_listAll(void);
static int Register_listFirstLetter(char letter);
static int Register_printBirthday();

static int menu(void);
static int loadFile(const char *file);
static int saveAll(void);

static struct Registers rgs = {
  .nreg = 0
};


int main(int argc, char *argv[])
{

  loadFile(FILE_NAME);
  menu();


  return EXIT_SUCCESS;
}

static int Register_insert(void)
{
  struct Register r;
  printf("Enter a name: ");
  fgets(r.name, sizeof(r.name), stdin);

  printf("Enter a phone: ");
  fgets(r.phone, sizeof(r.phone), stdin);

  printf("Enter a day: ");
  scanf("%d", &r.day);

  printf("Enter a month: ");
  scanf("%d", &r.month);

  int ret = verifyRegister(&r);
  if(!ret){
    rgs.reg[rgs.nreg] = r;
    rgs.nreg++;
  }

}

static int Register_remove(struct Register *reg)
{

}

static int Register_find(const char *name, struct Register *reg)
{
  for(int i = 0; i < rgs.nreg; i++){
    struct Register *r = &rgs.reg[rgs.nreg];
    if(!strcmp(name, r->name)){
      reg = r; 
      return 0;
    }
  }  

  return -1;
}

static int Register_listAll(void)
{

}

static int Register_listFirstLetter(char letter)
{

}

static int Register_printBirthday()
{

}

static int menu(void)
{
  char choose = 's';  
  do
  {
    printf("[1] - Insert Register\n");
    printf("[2] - Remove Register\n");
    printf("[3] - Find Contact by name\n");
    printf("[4] - List all Registers\n");
    printf("[5] - List Contacts starts by letter \n");
    printf("[6] - Print all month Birthday \n");
    printf("[q] - Exit program \n");

    choose = getchar();
  }while(choose != 'q');

  saveAll();
}

static int loadFile(const char *file)
{
  FILE *fd = NULL;
  long f_size = 0;
  char b[256] = {0};
  int ret = 0;

  fd = fopen(file, "r");
  if(!fd){
    fd = fopen(file, "w");
    if(!fd){
      perror("Error loadFile.");
      return 1;
    }
  }

  fseek(fd, 0, SEEK_END);
  f_size = ftell(fd);
  rewind(fd);

  while(f_size > 0)
  {
    fgets(b, sizeof(b), fd);

    struct Register *reg = &rgs.reg[rgs.nreg];
    ret = sscanf(b, "NAME: %s PHONE: %s DAY: %d MONTH: %d", reg->name, reg->phone, &reg->day, &reg->month);
    if(ret > 0)
      rgs.nreg++;

    memset(b, '\0', sizeof(b));
    if(feof(fd))
      break;
  }

  fclose(fd);
  return 0;
}

static int saveAll(void)
{
  FILE *fd = NULL; 

  fd = fopen(FILE_NAME, "w");
  if(!fd){
    perror("Error save data.");
    return 1;
  }
  else{
    for(int i = 0; i < rgs.nreg; i++){
      struct Register *reg = &rgs.reg[rgs.nreg];
      fprintf("NAME: %s PHONE: %s DAY: %d MONTH: %d\n", reg->name, reg->phone, reg->day, reg->month );
    }
  }

  fclose(fd);
  return 0;
}
