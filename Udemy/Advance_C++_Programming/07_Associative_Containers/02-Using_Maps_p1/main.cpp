#include <iostream>
#include <map>

using namespace std;

int main()
{

  map<string, string> numbers;

  numbers["Jones"] = "365";
  numbers["Smith"] = "467";
  numbers["Brown"] = "111";

  cout << "Jones: " << numbers["Jones"] << endl;

  cout << "Size: " << numbers.size() << endl;

  numbers.erase("Smith");
  cout << "Size: " << numbers.size() << endl;

  return 0;
}
