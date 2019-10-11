/*
 * main.cpp
 *
 *  Created on: 11 de out de 2019
 *      Author: solid
 */

#include <iostream>
#include <random>
#include <string>

using namespace std;

class Team{
public:
	string name;

	Team(string n){
		this->name = n;
	}
};

class Championship{
private:
	Team *match(Team *ta, Team *tb, int odds){
		if( odds % 2 == 0){
			cout << ta->name << " Defeats " << tb->name << "\n";
			return ta;
		}else{
			cout << tb->name << " Defeats " << ta->name << "\n";
			return tb;
		}
	}

public:
	Team *champion;

	void playoffs(Team *t1, Team *t2, Team *t3, Team *t4, Team *t5, Team *t6, Team *t7, Team *t8){
		if(champion != NULL)
			return ;

		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<> dis(1, 100);

		Team *semi1 = match(t1, t8, dis(gen) % 100);
		Team *semi2 = match(t2, t7, dis(gen) % 100);
		Team *semi3 = match(t3, t6, dis(gen) % 100);
		Team *semi4 = match(t4, t5, dis(gen) % 100);
		cout << "\n";

		Team *finals1 = match(semi1, semi4, dis(gen) % 100);
		Team *finals2 = match(semi2, semi3, dis(gen) % 100);
		cout << "\n";

		Team *champ = match(finals1, finals2, dis(gen) % 100);
		this->champion = champ;

		cout << " Team " << champ->name << " WIN THE CHAMPIOSHIP!" << "\n";
	}
};


int main(int argc, char **argv) {
	Team *contender1 = new Team("Archers");
	Team *contender2 = new Team("Bobcats");
	Team *contender3 = new Team("Centurions");
	Team *contender4 = new Team("Danger Zone");
	Team *contender5 = new Team("Energy");
	Team *contender6 = new Team("Flames");
	Team *contender7 = new Team("Guards");
	Team *contender8 = new Team("Hunters");

	Championship *c = new Championship();
	c->playoffs(contender1, contender2, contender3, contender4, contender5, contender6, contender7, contender8);
}





