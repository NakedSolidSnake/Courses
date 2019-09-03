#include <iostream>
#include <algorithm>

void Print(int *p, int size){

  for(int i = 0; i < size; i++){
    std::cout << p[i] << ' ';
  }
}

int main()
{
  int *p = new int[5]{5,1,7,2,8};

  int *pTemp = new int[5 + 5];

  std::copy(p, p + 5, pTemp);

  delete[]p;

  p = pTemp;
  p[5] = 100;
  Print(p, 6);

  delete[]p;
}
