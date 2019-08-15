#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
void display(vector<T> v){
  for(int i = 0; i < v.size(); ++i){
    cout << v[i] << endl;
  }
  cout << endl;
}

int main(){

  vector<int> numbers;
  for(int i = 0; i <= 10; ++i){
    numbers.push_back(i);
  }

  display(numbers);
  fill(numbers.begin(), numbers.end(), 0);
  display(numbers);
  vector<string> names;
  names.push_back("Name 1");
  names.push_back("Name 2");
  names.push_back("Name 3");
  display(names);
  fill(names.begin(), names.end(), "");
  display(names);
  
  replace(numbers.begin(), numbers.end(), 5,10);
  display(numbers);

  vector<string> words;
  words.push_back("gift");
  words.push_back("to");
  words.push_back("recieve");
  display(words);
  replace(words.begin(), words.end(), "recieve", "receive");
  display(words);



  return 0;
}
