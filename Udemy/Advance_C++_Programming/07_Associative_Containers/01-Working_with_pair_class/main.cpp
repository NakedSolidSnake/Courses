#include <iostream>
#include <utility>

using namespace std;

int main()
{
  pair<string, string> number1("Jones", "123");
  cout << number1.first << endl;
  cout << number1.second << endl;

  pair<string, int> student("Brown", 80);
  cout << student.first << endl;
  cout << student.second << endl;
  return 0;
}
