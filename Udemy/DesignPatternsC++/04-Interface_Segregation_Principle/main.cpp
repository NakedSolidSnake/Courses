/*
 * main.cpp
 *
 *  Created on: Dec 15, 2019
 *      Author: cssouza
 */

#include <iostream>

using namespace std;

struct Document{

};

struct IMachine{
	virtual void print(Document& doc) = 0;
	virtual void scan(Document& doc) = 0;
	virtual void fax(Document& doc) = 0;
};

struct MFP : IMachine
{
	void print(Document& doc) override{
		cout << "printing..." << endl;
	}

	void scan(Document& doc){
		cout << "scanning..." << endl;
	}

	void fax(Document& doc){
		cout << "faxing..." << endl;
	}
};



int main(int argc, char **argv) {
	MFP mfp;
	Document d;

	mfp.print(d);
	mfp.scan(d);
	mfp.fax(d);

	return 0;
}

//The problem





