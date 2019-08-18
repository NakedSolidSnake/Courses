#include <iostream>
#include <map>
#include <utility>

using namespace std;

int main()
{
  multimap<string, string> numbers;
  numbers.insert(pair<string, string>("Jones", "123"));
  numbers.insert(pair<string, string>("Smith", "245"));
  numbers.insert(pair<string, string>("Brown", "245"));
  numbers.insert(pair<string, string>("Jones", "245"));
  numbers.insert(pair<string, string>("Smith", "245"));
  numbers.insert(pair<string, string>("Jones", "627"));

  string searchName = "Jones";
  multimap<string, string>::iterator iter = numbers.find(searchName);
  multimap<string, string>::iterator last = numbers.upper_bound(searchName);

  for(; iter != last; ++ iter){
    cout << iter->first << ": " << iter->second << endl;
  }
  return 0;
}
