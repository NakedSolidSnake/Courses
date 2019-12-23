/*
 * main.cpp
 *
 *  Created on: Dec 20, 2019
 *      Author: cssouza
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <fstream>
#include <tuple>

using namespace std;

enum class Relationship
{
	parent,
	child,
	sibling
};

struct Person
{
	string name;
};

struct RelationshipBrowser
{
	virtual vector<Person> find_all_children(const string &name) = 0;
};

struct Relationships : RelationshipBrowser	//Low level
{
	vector<tuple<Person, Relationship, Person>> relations;

	void add_parent_and_child(const Person& parent, const Person& child){
		relations.push_back({parent, Relationship::parent, child});
		relations.push_back({child, Relationship::child, parent});
	}

	vector<Person> find_all_children(const string &name) override{
		vector<Person> result;

		for(auto&& [first, rel, second] : relations){
			if(first.name == name && rel == Relationship::parent){
				result.push_back(second);
			}
		}

		return result;
	}
};

struct Research	//high level
{
	Research(RelationshipBrowser& browser){
		for(auto& child : browser.find_all_children("John")){
			cout << "John has a child called " << child.name << endl;
		}
	}
};



int main(int argc, char **argv) {

	Person parent {"John"};
	Person child1{"Chris"}, child2{"Matt"};

	Relationships relationships;
	relationships.add_parent_and_child(parent, child1);
	relationships.add_parent_and_child(parent, child2);

	Research _(relationships);

	return 0;
}






