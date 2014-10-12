#ifndef WARRIOR_H
#define WARRIOR_H
#include <string>
#include <vector>

namespace WarriorCraft{
	class Noble;

	class Warrior{
	public:
		Warrior(const std::string& name, double strength);
		std::string getWarriorName() const;
		double getWarriorStr() const;
		bool getWarriorStat()const;
		void setWarriorStat(bool newStat);
		void setWarriorStr(double newStr);
		void setNoble(Noble* nameOfNoble);
		void runaway();
	private:
		std::string warriorName;
		double warriorStr;
		bool hired;
		Noble* owner;
	};
}
#endif
