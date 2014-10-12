/*
  FileName:     hw02.cpp 
  Name:         Kostaq Papa
  Semester:     Spring 2011 
  Course:       CS 1124      
  Assumption:   A battle command cannot appear until the specified warriors have been seen.
  
*/


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


struct MedievalCombatant{
              
       string nameOfWarrior;     //--> will hold the name of a warrior
       int strengthOfWarrior;    //--> will hold the strength of a warrior 
       
};
     
void commandWarrior(ifstream& warriorsFile, vector<MedievalCombatant>& warriorData){
     //This funtion will add all the warriors data to vector<MedievalCombatant> warriorData."
     
     string fighter;                 // fighter --> will hold the fighter name.
     int power;                      // power --> will hold the power (strength) of the warrios.
    
     MedievalCombatant warriorWorld;
     warriorsFile >> fighter;
     warriorWorld.nameOfWarrior = fighter;
     warriorsFile >> power;
     warriorWorld.strengthOfWarrior = power;
     warriorData.push_back(warriorWorld);
}

void commandStatus(vector<MedievalCombatant>& warriorData){
     //This function will print the information in the vector<MedievalCombatant> warriorData.
      
      cout << "There are " << warriorData.size() << " warriors." << endl;
      for (size_t i=0; i<warriorData.size(); ++i){
          cout << "Warrior: " << warriorData[i].nameOfWarrior 
          << ", strength: " << warriorData[i].strengthOfWarrior << endl;
      }
}

void commandBattle(ifstream& warriorsFile, vector<MedievalCombatant>& warriorData){
     //This funtction will start the warriors' battle and will decide the winners.
     
     string fighterOne, fighterTwo;     //--> will hold the name of first and second fighter.
     int ndxOne = 0;                    //--> will be used to find the index of strength and name, of the first fighter, in the vector<MedievalCombatant>& warriorData
     int ndxTwo = 0;
     
     warriorsFile >> fighterOne;        //--> reads the first fighter's name
     warriorsFile >> fighterTwo;        //--> reads the second fighter's name
     
     cout << fighterOne << " battles " << fighterTwo << endl; //--> will print who fights whom.
     
     for (size_t i=0; i<warriorData.size(); ++i){ //--> finding the index1 in vector<MedievalCombatant>& warriorData
         if (fighterOne == warriorData[i].nameOfWarrior){
                        ndxOne = i;
         }
     }
     
     for (size_t i=0; i<warriorData.size(); ++i){//--> finding the index2 in vector<MedievalCombatant>& warriorData
         if (fighterTwo == warriorData[i].nameOfWarrior){
                        ndxTwo = i;
         }
     }
                
     //Checking if the warriors has the same, but not equal to 0, strength.
     if (warriorData[ndxOne].strengthOfWarrior != 0 && warriorData[ndxTwo].strengthOfWarrior !=0 && warriorData[ndxOne].strengthOfWarrior == warriorData[ndxTwo].strengthOfWarrior){
        cout << "Mutual Annihilation: " << warriorData[ndxOne].nameOfWarrior << " and "
        << warriorData[ndxTwo].nameOfWarrior << " die at each other's hands." << endl;
        warriorData[ndxOne].strengthOfWarrior = 0;
        warriorData[ndxTwo].strengthOfWarrior = 0;
     }
     
     //Checking if the warriors' strength is 0.
     else if (warriorData[ndxOne].strengthOfWarrior == 0 && warriorData[ndxTwo].strengthOfWarrior == 0){
          cout << "Oh, NO! They're both dead! Yuck!" << endl;
     }
     
     //Checking if the first fighter is stronger than the second fighter and the second fighter has a strength of 0.
     else if (warriorData[ndxOne].strengthOfWarrior > warriorData[ndxTwo].strengthOfWarrior &&  warriorData[ndxTwo].strengthOfWarrior == 0){
          cout << "He's dead "
          << warriorData[ndxOne].nameOfWarrior << endl;
     }
     
     else if (warriorData[ndxOne].strengthOfWarrior > warriorData[ndxTwo].strengthOfWarrior > 0){
          cout << warriorData[ndxOne].nameOfWarrior << " defeats " <<  warriorData[ndxTwo].nameOfWarrior << endl;
          warriorData[ndxOne].strengthOfWarrior = warriorData[ndxOne].strengthOfWarrior - warriorData[ndxTwo].strengthOfWarrior;
          warriorData[ndxTwo].strengthOfWarrior = 0;
     }
     
     //Checking if the second fighter is stronger than the first fighter and if the first fighter has a strength of 0.
     else if (warriorData[ndxTwo].strengthOfWarrior > warriorData[ndxOne].strengthOfWarrior && warriorData[ndxOne].strengthOfWarrior == 0){
          cout << "He's dead "
          << warriorData[ndxTwo].nameOfWarrior << endl;
     }
     
     else{
          cout << warriorData[ndxTwo].nameOfWarrior << " defeats " <<  warriorData[ndxOne].nameOfWarrior << endl;
          warriorData[ndxTwo].strengthOfWarrior = warriorData[ndxTwo].strengthOfWarrior - warriorData[ndxOne].strengthOfWarrior;
          warriorData[ndxOne].strengthOfWarrior = 0;
     }
}

void playGame(ifstream& warriorsFile, vector<MedievalCombatant>& warriorData){
     //This function will paly the game!!
     
     string command;      //--> will hold the command (first word) that will be read from the file.
     string warriorCommand="Warrior", statusCommand="Status";      //--> will be used to check what command was read from the file.

     while (warriorsFile >> command){
           
           if (command == warriorCommand){
                       commandWarrior(warriorsFile, warriorData);
           }           
           else if (command == statusCommand){
                commandStatus(warriorData);
           }           
           else{// (command == "Battle"){
                   commandBattle(warriorsFile, warriorData);
           }
     }
}
           
           
           
    
int main(){
    
    ifstream warriorsFile("warriors.txt");
    if (!warriorsFile){
                       cerr << "The file couldn't be opened." << endl << endl;
                       exit(1);
    }
    
    vector<MedievalCombatant> warriorData;  // --> will hold all the data of the warriors. Used in the "commandWarrior", "commandStatus" and "commandBattle" functions.
        
    playGame(warriorsFile, warriorData);
    system ("pause");
    
}
    
    

