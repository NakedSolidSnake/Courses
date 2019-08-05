#include <iostream>

using namespace std;

class Shape{
  virtual void setX(int xcor) = 0;
  virtual void setY(int ycor) = 0;
  virtual int getX() const = 0;
  virtual int getY() const = 0;
  virtual void draw() const = 0;
};

class Circle : public Shape{
  private:
    int x;
    int y;
    int radius;

  public:
     Circle(int xcor, int ycor, int r){
      x = xcor;
      y = ycor;
      radius = r;
    }
  virtual void setX(int xcor){
    x = xcor;
  }

  virtual void setY(int ycor){
    y = ycor;
  }

  virtual int getX()const{
    return x;
  }

  virtual int  getY(){
    return y;
  }

  void setRadius(int r){
    radius = r;
  }

  int getRadius(void) const{
    return radius;
  }

  virtual void draw(){
    cout << "Drawing circle." << endl;
  }
};
