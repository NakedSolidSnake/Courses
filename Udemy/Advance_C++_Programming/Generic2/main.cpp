#include <iostream>

using namespace std;

class Stack{
  private:
    int datastore[100];
    int top;
  public:
    Stack(){
      top = -1;
    }

    void push(int val){
      ++top;
      datastore[top] = val;
    }

    int pop(void){
      int val = datastore[top];
      --top;
      return val;
    }

    int peek(void){

      return datastore[top];
    }
};

int main(){
  Stack stack;
  cout << stack.peek() << endl;
  stack.push(10);
  stack.push(2);

  cout << stack.peek() << endl;
  stack.pop();
  cout << stack.peek() << endl;
  return 0;
}
