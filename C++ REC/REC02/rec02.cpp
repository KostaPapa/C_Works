/*

FileName:     rec02.cpp 
Name:         Kostaq Papa
Semester:     Spring 2011 
Course:       CS 1124
Lab Section:  CS 1124LAB - B2

*/

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;


struct Molecule{
       
       int carbonAtoms;                     // Will hold the number of carbon atoms.
       int hydroAtoms;                      // Will hold the number of hydrogen atoms.
       vector<string> hydroCarbonName;      // Will hold the name of HydroCarbons.

};


void sortHydroCarbons (ifstream& hydroCarbonFile){
     //This funtion will sort the hydrocarbons.
     
     char carbonChar, hydrogenChar;         // Will hold the character 'C' for carbon and character 'H' for hydrogen.
     int carbonNo, hydrogenNo, max=1;       // Will hold the number of carbon atoms and hydrogen atoms.
     string formulaName;                    // Will hold the name of hydrocarbons.
     vector<Molecule> hydroCarbonsVec;      // Will hold information for all hydrocarbon molecules.
     
     //Reading from the file 'hydrocarbons.txt' and puting the respective information into the 'struct Molecule'.
     while (hydroCarbonFile >> formulaName >> carbonChar >> carbonNo >> hydrogenChar >> hydrogenNo){
           
           Molecule hydroCarbon;
           hydroCarbon.hydroCarbonName.push_back(formulaName);
           hydroCarbon.carbonAtoms = carbonNo;
           hydroCarbon.hydroAtoms = hydrogenNo;
           hydroCarbonsVec.push_back(hydroCarbon);
                      
     }
           
     int maxCarbonAtom = 0;
     for (size_t i=0; i<hydroCarbonsVec.size(); ++i){
         if (hydroCarbonsVec[i].carbonAtoms > maxCarbonAtom){
                                            maxCarbonAtom = hydroCarbonsVec[i].carbonAtoms;
         }
     }
     
     cout << "Sorted Hydrocarbons: \n" << endl;
     int minCarbonAtoms = 1;
     while (minCarbonAtoms <= maxCarbonAtom){
           for (size_t i=0; i<hydroCarbonsVec.size(); ++i){
               if (hydroCarbonsVec[i].carbonAtoms == minCarbonAtoms){
                                                  cout << carbonChar << hydroCarbonsVec[i].carbonAtoms
                                                  << hydrogenChar << hydroCarbonsVec[i].hydroAtoms << "\t";
                                                  for (size_t j=0; j<hydroCarbonsVec[i].hydroCarbonName.size(); ++j){
                                                      cout << hydroCarbonsVec[i].hydroCarbonName[j] << endl;
                                                  }
               }
           }
           ++minCarbonAtoms;
     }
                                                   
}
                                            
             


int main(){
    
    char holdScr;
    ifstream hydroCarbonFile("hydrocarbons.txt");
    
    if (!hydroCarbonFile){
                          cerr << "ERROR" << endl;
    }
    
    sortHydroCarbons(hydroCarbonFile);
    
    cout << "\nPress any key to exit...";
    cin >>  holdScr;
    
    
}
