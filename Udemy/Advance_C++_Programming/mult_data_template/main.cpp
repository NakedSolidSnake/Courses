#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <class T, class U>
class CMap{
  private:
    vector<T> keys;
    vector<U> values;

  public:
    void insert(T key, U value){
      keys.push_back(key);
      values.push_back(value);
    }

    void get(int pos){
      cout << keys[pos] << ": " << values[pos];
    }
};

int main()
{
  CMap<string, int> grades;
  grades.insert("Cristiano", 90);
  grades.insert("Sara", 95);

  grades.get(0);
  grades.get(1);
  return 0;
}
