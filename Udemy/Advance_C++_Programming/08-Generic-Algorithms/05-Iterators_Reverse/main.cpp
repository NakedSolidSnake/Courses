#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void display(vector<T> v){
  for(int i = 0; i < v.size(); i++){
    cout << v[i] << " ";
  }
  cout << endl;
}

int main(){
  vector<int> numbers;
  for(int i = 1; i <= 10; ++i){
    numbers.push_back(i);
  }

  for(vector<int>::iterator iter = numbers.begin(); iter != numbers.end(); ++iter){
    cout << *iter << " ";
  }
  cout << endl;

  for(vector<int>::reverse_iterator riter = numbers.rbegin(); riter != numbers.rend(); ++riter){
    cout << *riter << " ";
  }

  cout << endl;
  return 0;
}
