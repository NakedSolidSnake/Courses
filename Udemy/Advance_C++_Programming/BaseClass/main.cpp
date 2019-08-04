#include <iostream>
#include <sstream>
#include <vector>

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

    virtual double grossPay(int hours){
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

    virtual double grossPay(int hours){
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
  vector<Employee *> emps;
  Employee emp1("Mary Smith", 25.00);
  emps.push_back(&emp1);
  Manager emp2("Bob Brown", 1200, true);
  emps.push_back(&emp2);

  for(int i = 0; i < emps.size(); i++){
    cout <<  emps[i]->grossPay(40) << endl;
  }


  return 0;
}
