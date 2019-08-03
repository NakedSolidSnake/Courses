#include <iostream>
#include <sstream>

using namespace std;

class Employee{

  protected:
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

    ~Employee(){

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

    double grossPay(int hours){
      return pay * hours;
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
    Manager() : salaried(true)
    {

    } 

    Manager(string name, double payRate, bool isSalaried)
      : Employee(name, payRate)
    {
      this->salaried = isSalaried;
    }

    ~Manager(){

    }

    bool getSalaried() const {
      return this->salaried;
    }

    double grossPay(int hours){
      if(salaried){
        return pay;
      }else{
        return pay * hours; //must protected
      }
    }

    string toString(){
      stringstream stm;
      string salary;

      if(salaried){
        salary = "Salaried";
      }else{
        salary = "Hourly";
      }

      stm << name << ": " << pay << ": " << salary << endl;
      return stm.str();
    }
};

int main()
{

  Employee emp1("Mary Smith", 15.00);
  cout << "Employee name; " << emp1.getName() << endl;
  cout << "Employee pay rate: " << emp1.getPay() << endl;
  cout << "Gross pay: "<< emp1.grossPay(40) << endl;
 
  Manager emp2("Bob Brown", 1500, true);
  cout << "Gross pay: " << emp2.grossPay(0);
  cout << emp2.toString();
  return 0;
}
