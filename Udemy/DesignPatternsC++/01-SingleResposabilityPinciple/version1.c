#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <fstream>
#include <boost/lexical_cast.hpp>

using namespace std;
using namespace boost;


struct Journal
{
  string title;
  vector<string> entries;

  Journal(const string &title) : title(title){}

  void add_entry(const string& entry)
  {
    static int count = 1;
    entries.push_back(lexical_cast<string>(count++) + ": " + entry);
  }

  /* Here is the problem of this implementation
   * here the responsability for persist data
   * it is inside of class so if we need this method
   * in other class, or if we need other way to 
   * persist data lika a database if we have this code 
   * in all others classes it'll be a problem 
   * because we need to change every class that implement 
   * this method*/
  void save(const string& filename)
  {
    ofstream ofs(filename);
    for(auto& e: entries)
    {
      ofs <<  e << endl;
    }
  }
}

int main()
{
  Journal journal{"Dear Diary"};
  journal.add_entry("I ate a bug");
  journal.add_entry("I cried today");

  journal.save("diary.txt");

  return 0;
}
