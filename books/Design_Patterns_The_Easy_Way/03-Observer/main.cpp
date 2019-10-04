/*
 * main.cpp
 *
 *  Created on: Oct 3, 2019
 *      Author: cssouza
 */

#include <vector>
#include <algorithm>
#include <memory>
#include <string>
#include <iostream>

using namespace std;

class Subject;
class Observer;


class Terrorist : public Subject{
private:
	vector<unique_ptr<Observer>> obs;

public :
	string location;

	void notifyObservers(){
		for(auto it(obs.begin()), ite(obs.end()); it != ite; ++it){
			(*it)->update();
		}
	}

	void addObs(Observer *o){
		obs.push_back(move(unique_ptr<Observer>(o)));
	}

	void deleteObs(Observer *o){

	}

};

class Module{
public:
	string location;
	bool alert;
	string notifications;

	void sendAlerts(){
		if(alert){
			cout << "ALERT: " << notifications << "Agents in " << location << "\n";
		}
	}
};

class Observer{
public:
	virtual void update() = 0;
};

class Subject{
public:
	virtual void notifyObservers() = 0;
	virtual void addObs(Observer *o) = 0;
	virtual void deleteObs(Observer *o) = 0;
};





