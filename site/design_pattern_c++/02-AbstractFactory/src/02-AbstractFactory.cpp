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

struct Square : Shape{
	void draw() override{
		cout << "Inside Square::draw()" << endl;
	}
};

struct RoundedRectangle : Shape{
	void draw() override{
		cout << "Inside RoundedRectangle::draw()" << endl;
	}
};

struct RoundedSquare : Shape{
	void draw() override{
		cout << "Inside RoundedSquare::draw()" << endl;
	}
};

struct AbstractFactory{
	virtual Shape *getShape(string shapeType) = 0;
};

struct RoundedShapeFactory : AbstractFactory{
	Shape *getShape(string shapeType) override
	{
		if(shapeType == "RECTANGLE")
		{
			return new RoundedRectangle();
		}else if(shapeType == "SQUARE")
		{
			return new RoundedSquare();
		}

		return NULL;
	}
};

struct ShapeFactory : AbstractFactory{
	Shape *getShape(string shapeType) override
	{
		if(shapeType == "RECTANGLE")
		{
			return new Rectangle();
		}else if(shapeType == "SQUARE")
		{
			return new Square();
		}

		return NULL;
	}
};

struct FactoryProducer
{
	static AbstractFactory *getFactory(bool rounded)
	{
		if(rounded)
		{
			return new RoundedShapeFactory();
		}else
		{
			return new ShapeFactory();
		}
	}
};

int main() {
	vector<string> shapes = {"RECTANGLE", "SQUARE"};

	AbstractFactory *af;

	af = FactoryProducer::getFactory(true);

	for(int i = 0; i < shapes.size(); i++){
		Shape *s = af->getShape(shapes[i]);
		s->draw();
	}

	af = FactoryProducer::getFactory(false);

	for(int i = 0; i < shapes.size(); i++){
		Shape *s = af->getShape(shapes[i]);
		s->draw();
	}



	return 0;
}
