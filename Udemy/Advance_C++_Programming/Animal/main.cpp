#include <iostream>

using namespace std;

class Animal{
  public:
    virtual void talk() = 0;
};


class Dog : public Animal{
  public:
    virtual void talk(){
      cout << "Auf auf" << endl;
    }
};

class Cat : public Animal{
  public:
    virtual void talk(){
      cout << "Meow!" << endl;
    }
};

int main()
{
  Cat cat;
  Dog dog;

  cat.talk();
  dog.talk();

  return 0;
}
