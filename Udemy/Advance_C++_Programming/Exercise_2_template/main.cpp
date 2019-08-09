#include <iostream>
#include <vector>

using namespace std;

template <class T>
class List{
  private:
    vector<T> datastore;
  public:
    List(){}

    void add(T item){
      datastore.push_back(item);
    }

    void display(){
      for(int i = 0; i < datastore.size(); i++){
        cout << datastore[i] << endl;
      }
    }
};

int main(){
  List <string> list;

  list.add("Cristiano");
  list.add("Adriano");
  list.add("Marcelo");

  list.display();
  return 0;
}
