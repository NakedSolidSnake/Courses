/*
 * main.cpp
 *
 *  Created on: 3 de out de 2019
 *      Author: solid
 */


#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Component{
public:
	string name;
	tm* dateCreated;
	tm* dateLastModified;

	Component(string n){
		this->name = n;
		this->dateCreated = new tm();
		this->dateLastModified = new tm();
	}
};

class File : public Component{
public:
	string fileType;
	File(string n, string f) : Component(n){
		this->fileType = f;
	}
};

class Folder : public Component{
public:
	vector<Component> *contents = new vector<Component>();
	Folder(string n) : Component(n){

	}
};

int main(int argc, char **argv) {
	Folder *top = new Folder("Top Folder");
	File *a = new File("A", "Spreadsheet");
	File *b = new File("B", "Picture");
	Folder *mid = new Folder("Mid Folder");
	top->contents->push_back(*a);
	top->contents->push_back(*b);
	top->contents->push_back(*mid);

	File *c = new File("C", "Video");
	File *d = new File("D", "Letter Document");
	Folder *bot = new Folder("Bottom Folder");
	mid->contents->push_back(*c);
	mid->contents->push_back(*d);
	mid->contents->push_back(*bot);

	File *e = new File("E", "PDF");
	bot->contents->push_back(*e);

	cout << top->name << "\n";
	for(Component i : *top->contents){
		cout << i.name << "\n";
	}

	for(Component i : *mid->contents){
		cout << i.name << "\n";
	}

	for(Component i : *bot->contents){
		cout << i.name << "\n";
	}

	return 0;
}


