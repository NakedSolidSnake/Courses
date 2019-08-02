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

class Manager : public Employee{
  private:
    bool salaried;

  public:
    Manager(string name, double payRate, bool isSalaried)
      : Employee(name, payRate)
    {
      this->salaried = isSalaried;
    }

    bool getSalaried() const {
      return this->salaried;
    }
};

int main()
{

  Employee emp1("Mary Smith", 15.00);
  cout << "Employee name; " << emp1.getName() << endl;
  cout << "Employee pay rate: " << emp1.getPay() << endl;

  Manager emp2("Bob Brown", 1500, true);
  cout << "Employee name; " << emp2.getName() << endl;
  cout << "Employee pay rate: " << emp2.getPay() << endl;
  cout << "Emp2 salaried? " << emp2.getSalaried() << endl;

  return 0;
}
