#include "Warrior.h"
#include "Noble.h"
#include <string>
#include <iostream>
using namespace std;

namespace WarriorCraft{
	Warrior::Warrior(const string& name, double strength) : warriorName(name), warriorStr(strength), hired(false){}
	string Warrior::getWarriorName() const{
		return warriorName;
	}
	double Warrior::getWarriorStr() const{
		return warriorStr;
	}
	bool Warrior::getWarriorStat() const{
		return hired;
	}
	void Warrior::setWarriorStat(bool newStat){
		hired = newStat;
	}
	void Warrior::setWarriorStr(double newStr){
		warriorStr = newStr;
	}
	void Warrior::setNoble(Noble* nameOfNoble){
		owner =  nameOfNoble;
	}
	void Warrior::runaway(){
		cout << warriorName << " flees in terror, abdandoning his lord, " << owner->getNobleName() << endl;
		owner->fire(*this);
	}
}
