#include "Noble.h"
#include "Warrior.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

namespace WarriorCraft{
	Noble::Noble(const string& name):nobleName(name), alive(true){}
	string Noble::getNobleName() const{
		return nobleName;
	}
	bool Noble::getNobleStat()const{
		return alive;
	}
	//vector<Warrior*> getArmy() const {
	//	return army;
	//}
	/*double getNobleStr(){
		return nobleStr;
	}
	*/
	void Noble::setNobleStat(bool newStat){
		alive = newStat;
	}
	/*
	void setNobleStr(double newStr){
		nobleStr = newStr;
	}
	*/
	void  Noble::hire(Warrior& warrior){
		if(warrior.getWarriorStat() != true){
			army.push_back(&warrior);
			warrior.setWarriorStat(true);
		} 
	}
	void Noble::fire(Warrior& badWarrior){
		badWarrior.setWarriorStat(false);
		for(size_t i = 0; i < army.size(); ++i){
			if(&badWarrior == army[i]){
				army.erase(army.begin()+i);
				break;
			}
		}
		cout << "You dont work for me anymore" << badWarrior.getWarriorName() << "--" << nobleName << endl;
	}

	void Noble::display() const{
		cout << nobleName << "has an army of" << army.size() << endl;
		for(size_t i = 0; i < army.size(); ++i){
			cout << " " << army[i]->getWarriorName() << " : " << army[i]->getWarriorStr() << endl; 
		}
	}
	ostream& operator<<(ostream& os, const Noble& newNobleName){
		newNobleName.display();
		return os;
	}

	void Noble::battle(Noble& evilNoble){
		cout << nobleName << "Battles" << evilNoble << endl;
		double nobleStr = army[0]->getWarriorStr();
		double evilNobleStr = evilNoble.army[0]->getWarriorStr();
		for(size_t i = 0; i < army.size(); ++i){
			nobleStr = nobleStr + army[i]->getWarriorStr();
		}
		for(size_t i = 0; i < evilNoble.army.size(); ++i){
			evilNobleStr = evilNobleStr + evilNoble.army[i]->getWarriorStr();
		}

		if(nobleStr > evilNobleStr){
			if(!evilNoble.getNobleStat()){
				cout << "He's dead" << evilNoble.getNobleName() << endl;
				return;
			}
			cout << nobleName << "Defeats" << evilNoble.getNobleName();
			double ratio = evilNobleStr/nobleStr;
			for(size_t i = 0; i < evilNoble.army.size(); ++i){
				evilNoble.army[i]->setWarriorStr(0);
				evilNoble.setNobleStat(false);
			}
			for(size_t i = 0; i < army.size(); ++i){
				army[i]->setWarriorStr(army[i]->getWarriorStr() - army[i]->getWarriorStr()*ratio);
			}
		}
		if(nobleStr < evilNobleStr){
			if(!alive){
				cout << " He's dead" << nobleName << endl;
				return;
			}
			cout << evilNoble.getNobleName() << "Defeats" << nobleName << endl;
			double ratio = nobleStr/evilNobleStr;
			for(size_t i = 0; i < army.size(); ++i){
				army[i]->setWarriorStr(0);
				alive = false;
			}
			for(size_t i = 0; i < evilNoble.army.size(); ++i){
				evilNoble.army[i]->setWarriorStr(evilNoble.army[i]->getWarriorStr() - evilNoble.army[i]->getWarriorStr()*ratio);
			}
		}
		if(nobleStr == evilNobleStr){
			if(!alive && !evilNoble.getNobleStat()){
				cout << "Oh, NO! They're both daed"<< endl;
			}
			else{
				cout << "Mutal Annihalation" << nobleName << "and" << evilNoble.getNobleName() << "died at each other's hand" << endl;
				for(size_t i = 0; i < army.size(); ++i){
					army[i]->setWarriorStr(0);
					alive = false;
				}
				for(size_t i = 0; i < evilNoble.army.size(); ++i){
					evilNoble.army[i]->setWarriorStr(0);
					evilNoble.setNobleStat(false);
				}
			}
		}
	}
}
