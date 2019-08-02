#include <iostream>
#include <sstream>

using namespace std;

class Employee{

  private:
    string name;
    double pay;
  public:
    Employee(){
      name = "";
      pay = 0.0;
    }

    Employee(string empName, double payRate){
      name = empName;
      pay = payRate;
    }

    void setName(string name){
      this->name = name;
    }

    string getName(void) const{
      return this->name;
    }

    void setPay(double payRate){
      this->pay = payRate;
    }

    double getPay(void) const{
      return this->pay;
    }

    string toString(){
      stringstream stm;
      stm << name << ": " << pay;
      return stm.str();
    }
};

int main()
{

  Employee emp1("Jane Smith", 35000);
  Employee emp2("Bill Brown", 32000);

  cout << emp1.toString() << endl;
  cout << emp2.toString() << endl;

  return 0;
}
