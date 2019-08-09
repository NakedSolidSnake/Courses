#include <iostream>
#include <list>

using namespace std;

int main()
{

  list<string> names;
  names.push_back("Cristiano");
  names.push_back("Sara");
  names.push_back("Samuel");

  list<string>::iterator iter = names.begin();

  while(iter != names.end()){
    cout << *iter << endl;
    ++iter;
  }
  return 0;
}
