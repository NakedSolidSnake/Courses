#include <iostream>

using namespace std;

template <typename T>
bool equals(T arg1, T arg2){
  if(arg1 == arg2)
    return true;
  else
    return false; 
}

int main()
{
  int a = 10;
  int b = 10;

  string worda, wordb;
  worda = "hello";
  wordb = "hEllo";
  cout << "Equals(worda, wordb) " << equals(worda, wordb) << endl;
  cout << "Equals(a, b): " << equals(a, b) << endl;
  return 0;
}
