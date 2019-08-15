#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <numeric>


using namespace std;

template <typename T>
void display(vector<T> v){
  for(int i = 0; i < v.size(); i++){
    cout << v[i] << " ";
  }
  cout << endl;
}

int genRandom(){
  return rand() % 100 + 1;
}

int main(){
  vector<int> numbers(10);
  srand(time(NULL));
  generate(numbers.begin(), numbers.end(), genRandom);
  display(numbers);

  int sum = accumulate(numbers.begin(), numbers.end(), 0);
  cout << sum << endl;

  return 0;
}
