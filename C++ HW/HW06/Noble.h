#ifndef NOBLE_H
#define NOBLE_H
#include <string>
#include <vector>

namespace WarriorCraft{
	class Warrior;

	class Noble{
	public:
		Noble(const std::string& name);
		std::string getNobleName() const;
		bool getNobleStat() const;
		void setNobleStat(bool newStat);
		void display()const;
		void hire(Warrior& warrior);
		void fire(Warrior& badWarrior);
		void battle(Noble& evilNoble);
		friend std::ostream& operator<<(std::ostream& os,const Noble& newNobleName);
	private:
		std::string nobleName;
		//double nobleStr;
		bool alive;
		std::vector<Warrior*> army;

	};
}
#endif
