#include <iostream>

using namespace std;

template <typename T>
class Stack{
  private:
    int datastore[100];
    int top;
  public:
    Stack(){
      top = -1;
    }

    void push(T val){
      ++top;
      datastore[top] = val;
    }

    T pop(void){
      T val = datastore[top];
      datastore[top] = 0;  //here it will cause problem if use a string values
                           //so it is necessary to use template specialization
      --top;
      return val;
    }

    T peek(void){

      return datastore[top];
    }
};

template <>
class Stack<string>{
  private:
    string datastore[100];
    int top;
  public:
    Stack(){
      top = -1;
    }

    void push(string val){
      ++top;
      datastore[top] = val;
    }

    string pop(void){
    string val = datastore[top];
      datastore[top] = "";
      --top;
      return val;
    }

    string peek(void){

      return datastore[top];
    }
};
int main(){
 /* Stack<int> stack;
  cout << stack.peek() << endl;
  stack.push(10);
  stack.push(2);

  cout << stack.peek() << endl;
  stack.pop();
  cout << stack.peek() << endl;*/
  Stack<string> stack;

  stack.push("Cristiano");
  stack.push("Sara");
  cout << stack.peek() << endl;
  stack.pop();
  cout << stack.peek() << endl;
  return 0;
}
