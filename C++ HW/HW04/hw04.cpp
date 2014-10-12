/*
  FileName:     hw04.cpp 
  Name:         Kostaq Papa
  Semester:     Spring 2011 
  Course:       CS 1124      
  
*/

#include <string>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Warrior{
public:
	Warrior(const string& name, double strength)				// Constructor holding the name and strength of the warrior
		: name(name), hired(false), strength(strength) {}

    string getName() const{
    // Accessor that will get the name of the warrior
		return name;
	}
	
	double getStrength() const{
    // Accessor that will get the strength of the warrior
		return strength;
	}
    
    bool getStatus() const{
    // Accessor that will get the status of the warrior.
		return hired;
	}

	void setStrength(double newStrength){
    // Mutator that will change the stregth of the warrior
		strength = newStrength;
	}
	
    void setStatus(bool newStatus){
    // Mutator that will change the status of the warrior
		hired = newStatus;
	}
	
private:
	string name;          // Warrior Name
    double strength;        // Warrior Strength
    bool hired;			  // Warrior Status
};


class Noble{
public:
       Noble(const string& name) 
       : name(name), status(true) {}			// Constructor

	void hire(Warrior& aWarrior){
    // This method will hire a warrior
    
       if(status){
                  if(!aWarrior.getStatus()){
                                            nobleArmy.push_back(&aWarrior);
                                            aWarrior.setStatus(true);	// Warrior hired
                  }
       }
    }

	void fire(Warrior& aWarrior){
    // This method will fire a warrior
    
       aWarrior.setStatus(false);
       for(size_t i=1; i<=nobleArmy.size(); i++){
                  if(nobleArmy[i]== &aWarrior){
                                    nobleArmy.erase(nobleArmy.begin()+i);
                                    break;
                  }
       }
       cout << "You don't work for me anymore " << aWarrior.getName() << " -- " << name << endl;
    }
	
	void display() const{
    // This method will display warrior's name ans strength
        
		cout << name << " has an army of " << nobleArmy.size() << endl;
		for(size_t i=0; i<nobleArmy.size(); i++){
			
			cout << "	" << nobleArmy[i]->getName() << " : " << nobleArmy[i]->getStrength() << endl;
		}
	}

	void battle(Noble& aNoble){
    // This method will start a battle between two nobles

		cout << name << " battles " << aNoble.getName() << endl;

		double nobleArmy1 = nobleArmy[0]->getStrength();
		double nobleArmy2 = aNoble.nobleArmy[0]->getStrength();
		
		for(size_t i=1; i<nobleArmy.size(); i++){
                   nobleArmy1 = nobleArmy1 + nobleArmy[i]->getStrength();
        }
                   
		for(size_t i=1; i<aNoble.getNobleArmy().size(); i++) {
                   nobleArmy2 = nobleArmy2 + aNoble.nobleArmy[i]->getStrength();
        }

		if (nobleArmy1 > nobleArmy2){
                       if(!aNoble.getStatus()){
                                               cout << "He's dead " << name << endl;
                       }
                       cout << name << " defeats " << aNoble.getName() << endl;
                       double ratio = nobleArmy2/nobleArmy1;
        
                       for(size_t i=0; i<aNoble.getNobleArmy().size(); i++){
                                  aNoble.getNobleArmy()[i]->setStrength(0);
                                  aNoble.setStatus(false);
                       }
                       
                       for(size_t i=0; i<nobleArmy.size(); i++){
                                  nobleArmy[i]->setStrength(nobleArmy[i]->getStrength() - nobleArmy[i]->getStrength()*ratio);
                       }
        }
        
        if (nobleArmy1 < nobleArmy2){
                       cout << aNoble.getName() << " defeats " << name << endl;
                       if(!status){
                                   	cout << "He's dead " << aNoble.getName() << endl;
                       }
                       
                       double ratio = nobleArmy1/nobleArmy2;
                       
                       for(size_t i=0; i<nobleArmy.size(); i++){
                                  nobleArmy[i]->setStrength(0);
                                  status = false;
                       }
                       
                       for(size_t i=0; i<aNoble.getNobleArmy().size(); i++){
                                  aNoble.getNobleArmy()[i]->setStrength(aNoble.getNobleArmy()[i]->getStrength() - aNoble.getNobleArmy()[i]->getStrength()*ratio);
                       }
        }
        
        if(nobleArmy1 == nobleArmy2){
                        if(nobleArmy1 == 0){
                                      cout << "Oh, NO!  They're both dead!  Yuck!" << endl;
                        }
                        else{//(nobleArmy1 != 0){
                                           cout << "Mutual Annihalation: " << name << " and " << aNoble.getName() << " die at each other's hands." << endl;
                                           
                                           for(size_t i=0; i<nobleArmy.size(); i++){
                                                      nobleArmy[i]->setStrength(0);
                                                      status= false;
                                           }
                                           
                                           for(size_t i=0; i<aNoble.getNobleArmy().size(); i++){
                                                      aNoble.getNobleArmy()[i]->setStrength(0);
                                                      aNoble.setStatus(false);
                                           }
                        }
        }
  }
  
  string getName() const{
  // This method will get the noble's name
         return name;
  }
  
  vector<Warrior*> getNobleArmy() const{
  // This method will get the noble's army
          return nobleArmy;
  }
  
  bool getStatus() const{
       return status;
  }
  
  void setStatus(bool newStatus){
       status = newStatus;
  }

private:
	string name;
	vector<Warrior*> nobleArmy;       // Vector of noble's warrior
	bool status;					  // Noble's status (dead or alive)
};


void createNobles(ifstream& nobleWarrirorFile, vector<Noble*>& nobleVector) {
     // This funtion will create a noble and will push it back into a vector
   
   string nobleName;
   
   nobleWarrirorFile >> nobleName;
   Noble* ptrNoble = new Noble(nobleName);   // creating a noble on the heap
   nobleVector.push_back(ptrNoble);
}

void createWarriors(ifstream& nobleWarrirorFile, vector<Warrior*>& warriorVector){
     // This funtion will create a warrior and will push it back into a vector
     
     string warriorName;
     double strength;
     
     nobleWarrirorFile >> warriorName;
     nobleWarrirorFile >> strength;
     Warrior* ptrWarrior = new Warrior(warriorName, strength);   // creating a warrior on the heap
     warriorVector.push_back(ptrWarrior);
}

void hireWarriors(ifstream& nobleWarrirorFile, const vector<Noble*>& nobleVector, const vector<Warrior*>& warriorVector){
     // This function will hire a warrioe to a particular noble using the hire method
     
     string nobleName, warriorName;
     
     nobleWarrirorFile >> nobleName;
     nobleWarrirorFile >> warriorName;
     for (size_t i = 0; i < nobleVector.size(); ++i){                                
         if(nobleName == nobleVector[i]->getName()){                                  
                      for (size_t j = 0; j < warriorVector.size(); ++j){
                          if(warriorName == warriorVector[j]->getName()){
                                         nobleVector[i]->hire(*warriorVector[j]);
                          }
                      }
         }
     }
}

void fireWarriors(ifstream& nobleWarrirorFile, const vector<Noble*>& nobleVector, const vector<Warrior*>& warriorVector){
     // This function will fire a warrior to a particular noble using the fire method
     
     string nobleName, warriorName;
     
     nobleWarrirorFile >> nobleName;
     nobleWarrirorFile >> warriorName;
     for (size_t i = 0; i < nobleVector.size(); ++i){
         if(nobleName == nobleVector[i]->getName()){
                      for (size_t j = 0; j < warriorVector.size(); ++j){
                          if(warriorName == warriorVector[j]->getName()){
                                         nobleVector[i]->fire(*warriorVector[j]);
                          }
                      }
         }
     }
}

void battle(ifstream& nobleWarrirorFile, const vector<Noble*>& nobleVector){
     // This function will start the battle between two nobles.
     
     string nobleName, opponentNobleName;
     
     nobleWarrirorFile >> nobleName;
     nobleWarrirorFile >> opponentNobleName;
     
     for (size_t i = 0; i < nobleVector.size(); ++i){
         if(nobleName == nobleVector[i]->getName() && opponentNobleName == nobleVector[i]->getName()){
                      nobleVector[i]->battle(*nobleVector[i]);
         }
     }
}

int main(){
     
     ifstream nobleWarrirorFile("nobleWarriors.txt");                   //open file
     if (!nobleWarrirorFile){
                             cerr << "File couldnt be open!" << endl;
                             exit(1);
     }
    
    vector<Noble*> nobleVector;            // nobles vector
    vector<Warrior*> warriorVector;        // warriors vector
        
    string command;
    while(nobleWarrirorFile >> command){
                            if(command == "Noble"){                                       
                                       createNobles(nobleWarrirorFile, nobleVector);      // calling the appropriate function
                            }
                            else if (command == "Warrior"){
                                 createWarriors(nobleWarrirorFile, warriorVector);        // calling the appropriate function
                            }
                            else if (command == "Hire"){
                                 hireWarriors(nobleWarrirorFile, nobleVector, warriorVector);        // calling the appropriate function
                            }
                            else if (command == "Fire"){
                                 fireWarriors(nobleWarrirorFile, nobleVector, warriorVector);        // calling the appropriate function
                            }
                            else if (command == "Battle"){
                                 battle(nobleWarrirorFile, nobleVector);      // calling the appropriate function
                            }                                 
                            else if (command == "Status"){
                                 cout << "Nobles: " << endl;
                                 for (size_t i = 0; i < nobleVector.size(); ++i){
                                     nobleVector[i]->display();                          // dispaying status
                                 }
                            }
                            else{//(command == "Clear"){
                                 nobleVector.clear();
                                 warriorVector.clear();                                 // clearing all the data in noble and warrior vectors
                            }
    }
    
    system("pause");
}
