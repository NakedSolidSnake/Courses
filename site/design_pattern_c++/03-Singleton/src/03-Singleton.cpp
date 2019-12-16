//============================================================================
// Name        : 03-Singleton.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
using namespace std;

class SingleObject
{

private:
	SingleObject();
	static SingleObject *instance;

public:
	static SingleObject *getInstance();
	void showMessage();
};

SingleObject *SingleObject::instance = 0;

SingleObject::SingleObject(){

}

SingleObject *SingleObject::getInstance(){
	if(instance == 0)
		instance = new SingleObject();

	return instance;
}

void SingleObject::showMessage(){
	cout << "Sigleton created" << endl;
}

int main() {
	SingleObject *obj = SingleObject::getInstance();
	obj->showMessage();
	return 0;
}
