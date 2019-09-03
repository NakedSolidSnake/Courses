#include <iostream>
#include <algorithm>
#include <array>

template<typename T, int size>
void Print(T(&ref)[size]){
  for(int i = 0; i < size; ++i){
    std::cout << ref[i] << ' ';
  }
  std::cout << std::endl;
}

template<typename T, int size>
T* Begin(T(&ref)[size]){
  return ref;
}

template<typename T, int size>
T* End(T(&ref)[size]){
  return (ref + size);
}

void PrintArr(std::array<int, 5> &arr){
  std::sort(arr.begin(), arr.end());

  for(const auto &x: arr){
    std::cout << x << " ";
  }
  std::cout << std::endl;
}

int main(){
  std::array<int, 5> arr{1,2,3,4,5};
  arr.size();
  arr.at(8); //it will launch an exception
  int arr1[5];
  int arr2[5]{};
  int arr3[5]{3,1,6,8,0};

  arr3[0] = 100;
  int (&ref)[5] = arr3;

  int *p = std::begin(arr3);
  int *end = std::end(arr3);
  *(p + 7) = 800;

  p[2] = 700;

  std::sort(std::begin(arr3), std::end(arr3));
  Print(arr3);

  return 0;

}
