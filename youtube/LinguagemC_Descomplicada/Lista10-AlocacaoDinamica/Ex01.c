#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
  int *nums = (int *)malloc(sizeof(int) * 5);
   for(int i = 0; i < 5; i++){
     printf("Digite o %dº numero", i+1);
     scanf("%d", &nums[i]);
   } 

   for(int i = 0; i < 5; i++){
     printf("Valor digitado %d\n", nums[i]);
   } 

   free(nums);

  return EXIT_SUCCESS;
}
