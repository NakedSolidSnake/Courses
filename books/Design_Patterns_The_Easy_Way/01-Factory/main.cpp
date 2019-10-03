/*
 * main.cpp
 *
 *  Created on: 2 de out de 2019
 *      Author: solid
 */


#include <iostream>
#include <vector>
#include <string>

using namespace std;

class SportsBall{
public:
	string type;
	vector<string> materialsUsed;
	float radius;
	string comments;
	string make;
	string modelName;
};

class BallFactory{
public:
	virtual SportsBall *createBall() = 0;
};

class BasketballMaker : public BallFactory{
public:
	SportsBall *createBall(){
		SportsBall *b = new SportsBall();
		b->type = "Basketball";
		b->materialsUsed.reserve(3);
		b->materialsUsed.push_back("ruber");
		b->materialsUsed.push_back("fiber");
		b->materialsUsed.push_back("synthetic composite");
		b->radius = 4.8f;
		b->make = "Spalding";
		b->modelName = "Series Basketball";
		return b;
	}
};

class BaseballMaker : public BallFactory{
	SportsBall *createBall(){
		SportsBall *b = new SportsBall();
		b->type = "Baseball";
		b->materialsUsed.reserve(6);
		b->materialsUsed.push_back("cork");
		b->materialsUsed.push_back("wool");
		b->materialsUsed.push_back("poly/cotton");
		b->materialsUsed.push_back("cowhide");
		b->materialsUsed.push_back("yarn");
		b->materialsUsed.push_back("composite rubber");
		b->radius = 1.45f;
		b->make = "Rawlings";
		b->modelName = "MLB Official Baseball";
		return b;
	}

};

class SoccerBallMaker : public BallFactory{
	SportsBall *createBall(){
		SportsBall *b = new SportsBall();
		b->type = "Soccerball";
		b->materialsUsed.reserve(3);
		b->materialsUsed.push_back("wool");
		b->materialsUsed.push_back("Lether");
		b->materialsUsed.push_back("composite rubber");
		b->radius = 3.0f;
		b->make = "Topper";
		b->modelName = "Nike play similar";
		return b;
	}
};

class VolleyballMaker : public BallFactory{
	SportsBall *createBall(){
		SportsBall *b = new SportsBall();
		b->type = "Volleyball";
		b->materialsUsed.reserve(3);
		b->materialsUsed.push_back("wool");
		b->materialsUsed.push_back("Lether");
		b->materialsUsed.push_back("composite rubber");
		b->radius = 3.0f;
		b->make = "Topper";
		b->modelName = "World cup series";
		return b;
	}
};


int main(int argc, char **argv) {

	BallFactory *f1 = new BasketballMaker();
	BallFactory *f2 = new BaseballMaker();
	BallFactory *f3 = new SoccerBallMaker();
	BallFactory *f4 = new VolleyballMaker();

	SportsBall *bb1 = f1->createBall();
	SportsBall *bb2 = f2->createBall();
	SportsBall *bb3 = f3->createBall();
	SportsBall *bb4 = f4->createBall();

	cout << bb1->type << endl;
	cout << bb2->type << endl;
	cout << bb3->type << endl;
	cout << bb4->type << endl;
	return 0;
}


