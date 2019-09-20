#include <iostream>

int main()
{
  int **pp = new int *[2];
  pp[0] = new int[3];
  pp[1] = new int[3];

  for(int i = 0 ; i < 2; i++){

    for(int j = 0; j < 3; j++){
      pp[i][j] = rand() % 10;
    }
  }

  for(int i = 0 ; i < 2; i++){

    for(int j = 0; j < 3; j++){
      std::cout << pp[i][j] << ' ';
    }
    std::cout << std::endl;
  }

  delete[] pp[0];
  delete[] pp[1];

  delete[] pp;
}
