//============================================================================
// Name        : 01-Factory.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Shape
{
	virtual void draw() = 0;
};

struct Rectangle : Shape{
	void draw() override{
		cout << "Inside Rectangle::draw()" << endl;
	}
};

struct Circle : Shape{
	void draw() override{
		cout << "Inside Circle::draw()" << endl;
	}
};

struct Square : Shape{
	void draw() override{
		cout << "Inside Square::draw()" << endl;
	}
};

struct Factory{
	Shape *getShape(string shapeType){
		if(shapeType.empty())
			return NULL;

		if(shapeType == "RECTANGLE")
			return new Rectangle();
		else if(shapeType == "SQUARE")
			return new Square();
		else if(shapeType == "CIRCLE")
			return new Circle();

		return NULL;

	}
};

int main() {
	vector<string> shapes = {"RECTANGLE", "SQUARE", "CIRCLE"};

	Factory f;

	for(int i = 0; i < shapes.size(); i++){
		Shape *s = f.getShape(shapes[i]);
		s->draw();
	}



	return 0;
}
