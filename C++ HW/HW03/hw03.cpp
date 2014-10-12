/*
  FileName:     hw03.cpp 
  Name:         Kostaq Papa
  Semester:     Spring 2011 
  Course:       CS 1124      
  
*/


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


class Warrior{

public:
       Warrior(const string& name, int strength) : warriorName(name), warriorStrength(strength) {}
              
       bool checkWarriorStatus() const {         //this funtion will be use to check if the warrior is already hired.
            return warriorMaster != "";
       }
       
       void hireWarrior(const string& noble) {   //this funtion will be used to hire a warrior.
            warriorMaster = noble;
       }
       
       void fireWarrior(const string& noble){    //this funtion will be used to fire a warrior
            warriorMaster = noble;
       }
       
       string getWarriorMaster(){                //this funtion will be used to get the name of the warrior's noble
              return warriorMaster;
       }

       string getWarriorName(){                  //this funtion wil be used to get the warrior name
              return warriorName;
       }
           
       int getWarriorStrength(){                  //this funtion will get the warrior strength
           return warriorStrength;
       }
       
        void newWarriorStrength(const int& newStrength){ //this funtion will be used to change the warrior strength after they battle.
           warriorStrength = newStrength;
       }
             
      void displayWarrior() const {
           cout << warriorName << ": " << warriorStrength << endl;
      }
       
private:
        string warriorName, warriorMaster;
        int warriorStrength;
        
};


class Noble{

public:
       Noble(const string& name) : nobleName(name){}                  
            
       void hire(Warrior& aWarrior){                                  //will hire a warrior
            if (!aWarrior.checkWarriorStatus()){
                                     aWarrior.hireWarrior(nobleName);
                                     nobleArmy.push_back(&aWarrior);
            }
       }
              
       int searchWarrior(Warrior& aWarrior){                        //will search and find for a specific warrior
            int ndx = 0;
            
            while(ndx < nobleArmy.size()) {
                      if(aWarrior.getWarriorName() == nobleArmy[ndx]->getWarriorName()){return ndx;}
                      ++ndx;
            }
       }
       
       void fire(Warrior& aWarrior){               //will fire a warrior
            int ndx;
            ndx = searchWarrior(aWarrior);
            cout << "You don't work for me anymore " <<  nobleArmy[ndx]->getWarriorName() 
            << " -- "  << nobleName << endl;
            nobleArmy.erase(nobleArmy.begin() + ndx);
       }           
       
       void battle(Noble& aNoble){
                        
            for (size_t i=0; i<nobleArmy.size(); ++i){
                cout << nobleArmy[i]->getWarriorMaster() 
                << " battles " << aNoble.nobleArmy[i]->getWarriorMaster() << endl;
                
                int nobleStrength1 = 0;
                int nobleStrength2 = 0;
                
                nobleStrength1 += nobleArmy[i]->getWarriorStrength();
                nobleStrength2 += aNoble.nobleArmy[i]->getWarriorStrength();
                
                if(nobleStrength1 != 0 && nobleStrength2 !=0 && nobleStrength1 == nobleStrength2){
                                                      cout << "Mutual Annihalation: "
                                                      << nobleArmy[i]->getWarriorMaster() << " and "
                                                      << aNoble.nobleArmy[i]->getWarriorMaster()
                                                      << " die at each other's hands" << endl;
                                                      
                                                      nobleStrength1 = 0;
                                                      nobleStrength2 = 0;
                                                      //nobleArmy[i]->getWarriorStrength() = nobleArmy[i]->newWarriorStrength(nobleStrength1);
                                                      //this was my issue. I was having difficulties in changing the warrior stregth after each fight.
                                                      
                }
                
                else if (nobleStrength1 == 0 && nobleStrength2 == 0){
                     cout << "Oh, NO! They're both dead! Yuck!" << endl;
                }
                
                else if (nobleStrength1 > nobleStrength2 &&  nobleStrength2 == 0){
                     cout << "He's dead " << nobleArmy[i]->getWarriorMaster() << endl;
                }
                
                else if (nobleStrength1 > nobleStrength2 > 0){
                     cout << nobleArmy[i]->getWarriorMaster() << " defeats " <<  aNoble.nobleArmy[i]->getWarriorMaster() << endl;
                     nobleStrength1 = nobleStrength1 - nobleStrength2;
                     nobleStrength2 = 0;
                }
                
                else if (nobleStrength2 > nobleStrength1 && nobleStrength1 == 0){
                     cout << "He's dead " << aNoble.nobleArmy[i]->getWarriorMaster() << endl;
                }
                
                else{
                     cout << aNoble.nobleArmy[i]->getWarriorMaster() << " defeats " <<  nobleArmy[i]->getWarriorMaster() << endl;
                     nobleStrength2 = nobleStrength2 - nobleStrength1;
                     nobleStrength1 = 0;
                }
            }
       }
       
       void display() const {
            cout << nobleName << " has an army of " << nobleArmy.size() << endl;
            for (size_t i=0; i<nobleArmy.size(); ++i){
                nobleArmy[i]->displayWarrior();
            }                        
       }
       
private:
        string nobleName;
        vector<Warrior*> nobleArmy;        //vector of pointers.
};


int main(){
    
    Noble art("King Arthur");
    Noble lance("Lancelot du Lac");
    Noble jim("Jim");
    Noble linus("Linus Torvalds");
    Noble billie("Bill Gates");
    
    Warrior cheetah("Tarzan", 10);
    Warrior wizard("Merlin", 15);
    Warrior theGovernator("Conan", 12);
    Warrior nimoy("Spock", 15);
    Warrior lawless("Xena", 20);
    Warrior mrGreen("Hulk", 8);
    Warrior dylan("Hercules", 3);
    

    jim.hire(nimoy);
    lance.hire(theGovernator);
    art.hire(wizard);
    lance.hire(dylan);
    linus.hire(lawless);
    billie.hire(mrGreen);
    art.hire(cheetah);
    
    jim.display();
    lance.display();
    art.display();
    linus.display();
    billie.display();
    
    art.fire(cheetah);
    art.display();
    
    art.battle(lance);
    jim.battle(lance);
    linus.battle(billie);
    billie.battle(lance);
    
    system("pause");
}
    


       
