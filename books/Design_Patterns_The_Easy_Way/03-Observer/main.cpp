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

class Observer{
public:
	virtual void update(string loc) = 0;
};

class Subject{
public:
	virtual void notifyObservers() = 0;
	virtual void addObs(Observer *o) = 0;
	virtual void deleteObs(Observer *o) = 0;
};

class Terrorist : public Subject{
private:
	vector<unique_ptr<Observer>> obs;

public :
	string location;

	void notifyObservers(){
		for(auto it(obs.begin()), ite(obs.end()); it != ite; ++it){
			(*it)->update(this->location);
		}
	}

	void addObs(Observer *o){
		obs.push_back(move(unique_ptr<Observer>(o)));
	}

	void deleteObs(Observer *o){

	}

};

class Module : public Observer{
public:
	string location;
	bool alert;
	string notifications;

	void update(string loc){
		if(this->location == loc){
			this->alert = true;
			this->notifications = "Terrorist Nearby";
		}else{
			this->alert = false;
			this->notifications = "";
		}

		sendAlerts();
	}

	void sendAlerts(){
		if(alert){
			cout << "ALERT: " << notifications << " Agents in " << location << "\n";
		}
	}
};

static void scenary1(void);
static void scenary2(void);

int main(int argc, char **argv) {
	scenary1();
}

static void scenary1(void){
	Terrorist *t = new Terrorist();
		Module *m1 = new Module();
		Module *m2 = new Module();
		Module *m3 = new Module();
		Module *m4 = new Module();

		t->addObs(m1);
		t->addObs(m2);
		t->addObs(m3);
		t->addObs(m4);

		string locs[] = {
				"Los Angeles",
				"Chicago",
				"New York",
				"Seattle",
				"Cleveland",
				"Boston",
				"San Francisco",
				"Miami",
				"St. Louis",
				"Dallas"
		};

		m1->location = locs[1];
		m2->location = locs[4];
		m3->location = locs[5];
		m4->location = locs[9];

		for(int i = 0; i < 10; i++){
			t->location = locs[i];
			t->notifyObservers();
		}
}

static void scenary2(void){
	Terrorist *t1 = new Terrorist();
	Terrorist *t2 = new Terrorist();
	Terrorist *t3 = new Terrorist();
	Terrorist *t4 = new Terrorist();
	Terrorist *t5 = new Terrorist();

	Module *m = new Module();

	t1->addObs(m);
	t2->addObs(m);
	t3->addObs(m);
	t4->addObs(m);
	t5->addObs(m);

	string locs[] = {
			"Los Angeles",
			"Chicago",
			"New York",
			"Seattle",
			"Cleveland",
			"Boston",
			"San Francisco",
			"Miami",
			"St. Louis",
			"Dallas"
	};

	t1->location = locs[1];
	t2->location = locs[4];
	t3->location = locs[2];
	t4->location = locs[7];
	t5->location = locs[5];

	for(int i = 0; i < 10; i++){
		m->location = locs[i];
		t1->notifyObservers();
		t2->notifyObservers();
		t3->notifyObservers();
		t4->notifyObservers();
		t5->notifyObservers();
	}
}
