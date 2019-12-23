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

struct Relationships	//Low level
{
	vector<tuple<Person, Relationship, Person>> relations;

	void add_parent_and_child(const Person& parent, const Person& child){
		relations.push_back({parent, Relationship::parent, child});
		relations.push_back({child, Relationship::child, parent});
	}
};

struct Research	//high level
{
	Research(Relationships& relationships)
	{
		auto& relations = relationships.relations;
		for(auto&& [first, rel, second] : relations){
			if(first.name == "John" && rel == Relationship::parent){
				cout << "John has a child called " << second.name << endl;
			}
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






