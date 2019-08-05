#include <iostream>
#include <vector>

using namespace std;

class Quadrilateral{
  protected:
    double side1, side2, side3, side4;
  public:
    Quadrilateral(double s1, 
                  double s2,
                  double s3,
                  double s4)
    {
      side1 = s1;
      side2 = s2;
      side3 = s3;
      side4 = s4;
    }

    virtual void display(){
      cout << "Quadrilateral with side: " << side1 << " " << side2 << " " << side3 << " " << side4 << endl;
    }
};

class Trapezoid : public Quadrilateral{
  public:
    Trapezoid(double s1, double s2, double s3, double s4) :
      Quadrilateral(s1, s2, s3, s4){
        
      }

    virtual void display(){
      cout << "Trapezoid with side: " << side1 << " " << side2 << " " << side3 << " " << side4 << endl;
    }
};

class Square : public Quadrilateral{
  public:
    Square(double side) : 
      Quadrilateral(side, side, side, side){

      }

    virtual void display(){
      cout << "Square with side: " << side1 << " " << side2 << " " << side3 << " " << side4 << endl;
    }
};

int main(){
  vector<Quadrilateral *> shapes;
  Trapezoid t1(6,6,6,6);
  shapes.push_back(&t1);
  Square s1(4);
  shapes.push_back(&s1);

  for(int i = 0; i <shapes.size() ; i++){
    shapes[i]->display();
  }
}
