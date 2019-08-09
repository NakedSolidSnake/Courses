#include <iostream>
#include <stdexcept>

using namespace std;

class DivideByZero : public runtime_error
{
  public:
    DivideByZero() : 
      runtime_error("Divide by zero exception\n"){};
};

double quotient(double numer, double denom){
  if(denom == 0)
    throw DivideByZero();
  else
    return numer / denom;
}

int main(){
  double numer = 10;
  double denom = 0;
  double ret;

  try{
    ret = quotient(numer, denom);
    cout << "Result: " << ret; 
  }
  catch(DivideByZero &e){
    cerr << e.what();
  }
}
