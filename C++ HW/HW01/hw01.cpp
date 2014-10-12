/*
  FileName:     hw01.cpp 
  Name:         Kostaq Papa
  Semester:     Spring 2011 
  Course:       CS 1124      
  
*/


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;


void welcomeScreen(){
     //This funtion describe the program.
     
     string welcome = "R|O|M|A|N N|U|M|E|R|A|L|S C|O|N|V|E|R|T|E|R \nThis program will read integers from a file and will convert them into Roman Numerals.\n";
     
     cout << welcome << endl;
}



void convertToRomans(ifstream& integerFileName, const vector<int>& intDataVec){
    //This funtion will convert decimal numbers to romans.
    
    int decimalThousands = 1000, decimalHundreds = 100, decimalTens = 10; // Will be used to find the weight place of the integers.
    int thousandsPlace, hundredsPlace, tensPlace, onesPlace; // Each weight of the integers will be stored in this variables.
    char romanThousand = 'M', romanFiveHundred = 'D', romanHundred = 'C', romanFifty = 'L', romanTen = 'X', romanFive = 'V', romanOne = 'I';
    
    for (size_t i = 0; i < intDataVec.size(); ++i){ //Looping the vector element by element.
        
        //Calculating the weight of each integer.
        thousandsPlace = (intDataVec[i] / decimalThousands);
        hundredsPlace = (intDataVec[i] / decimalHundreds) % decimalTens;
        tensPlace = (intDataVec[i] / decimalTens) % decimalTens;
        onesPlace = intDataVec[i] % decimalTens;
        
        string romanNumber;       // Will hold the roman value.
              
        if (thousandsPlace >= 1){
                           
                           // Converting the thousands place into roman number.
                           while (thousandsPlace >= 1){
                                 romanNumber += romanThousand;
                                 thousandsPlace--;
                                 }
                                 
                          // Converting the hundreds place, between 500 and 10000, into roman number.
                          if (hundredsPlace >= 5  && hundredsPlace < 10){
                                            romanNumber += romanFiveHundred;
                                            while (hundredsPlace > 5  && hundredsPlace < 10){
                                                  romanNumber += romanHundred;
                                                  hundredsPlace--;
                                                  }
                                            }
                                            
                          // Converting the hundreds place, between 100 to 500, into roman number.                 
                          else if (hundredsPlace >= 1  && hundredsPlace < 5){
                               while (hundredsPlace >= 1  && hundredsPlace < 5){
                                     romanNumber += romanHundred;
                                     hundredsPlace--;
                                     }
                               }
                          
                          // Converting the tens place, between 50 to 100, into roman number.       
                          if (tensPlace >= 5  && tensPlace < 10){
                               romanNumber += romanFifty;
                               while (tensPlace > 5  && tensPlace < 10){
                                     romanNumber += romanTen;
                                     tensPlace--;
                                     }
                               }
                           
                          // Converting the tens place, between 10 to 50, into roman number.     
                          else if (tensPlace >= 1 && tensPlace < 5){
                               while (tensPlace >= 1 && tensPlace < 5){
                                     romanNumber += romanTen;
                                     tensPlace--;
                                     }
                               }
                          
                          // Converting the number nine into roman number.     
                          if (onesPlace == 9){
                               romanNumber += romanOne;
                               romanNumber += romanTen;
                               }
                          
                          // Converting the ones place, between 5 to 9, into roman number.     
                          else if (onesPlace >= 5  && onesPlace < 9){
                               romanNumber += romanFive;
                               while (onesPlace > 5 && onesPlace < 9){
                                     romanNumber += romanOne;
                                     onesPlace--;
                                     }
                               }
                          // Converting number 4 into roman number.
                          else if (onesPlace == 4){
                               romanNumber += romanOne;
                               romanNumber += romanFive;
                               }
                          
                          // Converting the ones place, between 1 to 4, into roman number.     
                          else{// (onesPlace >= 1 && onesPlace < 4){
                                  while (onesPlace >= 1 && onesPlace < 4){
                                        romanNumber += romanOne;
                                        onesPlace--;
                                        }
                                  }
                                  
                          cout << intDataVec[i] << ":\t" << romanNumber << endl;
        }
        
        else {// (thousandsPlace >= 1){
                                 
                          // Converting the hundreds place, between 500 to 1000, into roman number.      
                          if (hundredsPlace >= 5  && hundredsPlace < 10){
                                            romanNumber += romanFiveHundred;
                                            while (hundredsPlace > 5  && hundredsPlace < 10){
                                                  romanNumber += romanHundred;
                                                  hundredsPlace--;
                                                  }
                                            }
                          
                          // Converting the hundreds place, between 100 to 500, into roman number.                  
                          else if (hundredsPlace >= 1  && hundredsPlace < 5){
                               while (hundredsPlace >= 1  && hundredsPlace < 5){
                                     romanNumber += romanHundred;
                                     hundredsPlace--;
                                     }
                               }

                          // Converting the tens place, between 50 to 100, into roman number.     
                          if (tensPlace >= 5  && tensPlace < 10){
                               romanNumber += romanFifty;
                               while (tensPlace > 5  && tensPlace < 10){
                                     romanNumber += romanTen;
                                     tensPlace--;
                                     }
                               }
                          
                          // Converting the tens place, between 10 to 50, into roman number.     
                          else if (tensPlace >= 1  && tensPlace < 5){
                               while (tensPlace >= 1  && tensPlace < 5){
                                     romanNumber += romanTen;
                                     tensPlace--;
                                     }
                               }
                          // Converting number 9 into roman number.     
                          if (onesPlace == 9){
                               romanNumber += romanOne;
                               romanNumber += romanTen;
                               }
                          
                          // Converting the ones place, between 5 to 9, into roman number.     
                          else if (onesPlace >= 5  && onesPlace < 9){
                               romanNumber += romanFive;
                               while (onesPlace > 5 && onesPlace < 9){
                                     romanNumber += romanOne;
                                     onesPlace--;
                                     }
                               }
                          // Converting number four into roman number.
                          else if (onesPlace == 4){
                               romanNumber += romanOne;
                               romanNumber += romanFive;
                               }

                          // Converting the ones place, between 1 to 4, into roman number.     
                          else{// (onesPlace >= 1 && onesPlace < 4){
                                  while (onesPlace >= 1 && onesPlace < 4){
                                        romanNumber += romanOne;
                                        onesPlace--;
                                        }
                                  }
                                  
                          cout << intDataVec[i] << ":\t" << romanNumber << endl;
        }
             
    }
}



int main(){
    

    char holdScr;                        // Will hold the data on the computer screen by preventing the cmd window to close.
    int decimalNo;                       // Will hold all the information that will be read form integersFilename.
    ifstream integerFileName("integers.txt"); // Opens the "integers.txt" file.
    vector<int> intDataVec;                   // Will hold a vectors of ints.(numbers that will be read from the file)

    welcomeScreen();  // Calling the respective void function.
    
    if (!integerFileName){ // Checking if the file is sucesfully opened.
       cerr << "The filename integers.txt does not exist." << endl
       << "Check if the integers.txt and hw01.cpp files are in the same directory."
       << endl << "Check if the name of the text file is written correctly." << endl << endl;
       }
            
    while (integerFileName >> decimalNo){ // Storing all the file data into the decimalNo variable.
          intDataVec.push_back(decimalNo); // Pushing the information into the vector variable.
          }
    
    convertToRomans(integerFileName, intDataVec); // Calling the respective void funtion.
    
    cout << "\nPlease, press any key to exit...";
    cin >> holdScr;                 
}
