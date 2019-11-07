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
static int Register_remove(const char *name);
static int Register_find(const char *name, struct Register *reg);
static int Register_listAll(void);
static int Register_listFirstLetter(char letter);
static int Register_printBirthday();
static int verifyRegister(struct Register *reg);

static int menu(void);
static int selectMenu(char sel);
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
    return 0;
  }

  return -1;
}

static int Register_remove(const char *name)
{
  for(int i = 0; i < rgs.nreg; i++){
    struct Register *r = &rgs.reg[i];
    if(!strcmp(name, r->name)){
      memset(r->name, '\0', MAX_NAME);
      memset(r->phone, '\0', MAX_PHONE);
      r->day = 0;
      r->month = 0;
      return 0;
    }
  }  

  return -1;
}

static int Register_find(const char *name, struct Register *reg)
{
  char n[MAX_NAME] = {0};
  memcpy(n, name, strlen(name));
  n[strlen(n) - 1] = '\0';
  for(int i = 0; i < rgs.nreg; i++){
    struct Register *r = &rgs.reg[i];
    if(!strcmp(n, r->name)){
      memcpy(reg, r, sizeof(struct Register));
      return 0;
    }
  }  

  return -1;
}

static int Register_listAll(void)
{
  for(int i = 0; i < rgs.nreg; i++){
    struct Register *r = &rgs.reg[i];
    printf("NAME: %s PHONE: %s DAY: %d MONTH: %d\n", r->name, r->phone, r->day, r->month);
  }  
  return 0;
}

static int Register_listFirstLetter(char letter)
{
  for(int i = 0; i < rgs.nreg; i++){
    struct Register *r = &rgs.reg[i];
    if(r->name[0] == letter){
      printf("NAME: %s PHONE: %s DAY: %d MONTH: %d\n", r->name, r->phone, r->day, r->month);
    }
  }  

  return 0;

}

static int Register_printBirthday()
{
  return 0;
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

    scanf("%c", &choose);
    getchar();

    system("clear");

  }while(!selectMenu(choose));

  saveAll();
  return 0;
}

static int selectMenu(char sel)
{
  char name[MAX_NAME];
  struct Register reg;
  int ret;
  int fret;
  switch(sel){
    case 'q':
      printf("Quitting...\n");
      ret = 1;
      break;

    case '1':
      printf("Insert Data.\n");
      ret = 0;
      break;

    case '2':
      printf("Remove Data.\n");
      ret = 0;
      break;

    case '3':
      printf("Find Contact by name: \n");
      printf("Enter a name: ");
      fgets(name, MAX_NAME, stdin);
      fret = Register_find(name, &reg);
      if(fret != -1){
        printf("NAME: %s PHONE: %s DAY: %d MONTH: %d\n", reg.name, reg.phone, reg.day, reg.month );
      }else{
        printf("Not found.\n");
      }

      printf("\n");

      ret = 0;
      break;

    case '4':
      printf("List all Contacts.\n");
      Register_listAll();
      printf("\n");
      ret = 0;
      break;

    case '5':
      printf("List Contacts by first letter.\n");
      ret = 0;
      break;
      
    case '6':
      printf("Print all by Birthday.\n");
      ret = 0;
      break;

    default:
      printf("Select an existing option.\n");
      ret = 0;
  }

  return ret;
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
      struct Register *reg = &rgs.reg[i];
      if(strlen(reg->name) == 0)
        continue;
      fprintf(fd,"NAME: %s PHONE: %s DAY: %d MONTH: %d\n", reg->name, reg->phone, reg->day, reg->month );
    }
  }

  fclose(fd);
  return 0;
}

static int verifyRegister(struct Register *reg)
{
  if(strlen(reg->name) == 0){
    return 1;
  }

  if(strlen(reg->phone) == 0){
    return 1;
  }

  if(reg->day <= 0){
    return 1;
  }

  if(reg->month <= 0){
    return 1;
  }

  return 0;
}
