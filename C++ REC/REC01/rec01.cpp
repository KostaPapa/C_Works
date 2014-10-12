/*

FileName:     hw01.cpp 
Name:         Kostaq Papa
Semester:     Spring 2011 
Course:       CS 1124
Lab Section:  CS 1124LAB - B2

*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;


void readAllFile(ifstream& rec01Filename){
     //This funtion will read all the file without spaces.
     
     string readAllFile;
     
     while (rec01Filename >> readAllFile){
           cout << readAllFile;
           }
            
}


void readLineByLine(ifstream& rec01Filename){
     //This funtion will read the file line by line and will find the total number of lines.
     
     int countLines;
     string lines;
     
     countLines = 0;
     while (getline (rec01Filename, lines)){
           cout << lines << endl;
           countLines += 1;
           }
           cout << "\nThe total number of lines is: " << countLines << endl;           
}
    

void readWordByWord(ifstream& rec01Filename){
     //This funtion will read the file word by word and will find the total number of words.
     
     int countWords;
     string words;
     
     countWords=0;
     while (rec01Filename >> words){
           cout << words << endl; countWords += 1;
           }
           cout << "\nTotal number of words is: " << countWords << endl;      
}


int main(){
    
    ifstream rec01Filename("dataRec01.txt");
    
    if (!rec01Filename){
                         cout << "The filename dataRec01.txt does not exist." << endl
                         << "Check if the dataRec01.txt and rec01.cpp files are in the same directory." << endl
                         << "Check if the name of the text file is written correctly." << endl << endl;
                         }
                         
    else{
         ifstream rec01Filename("dataRec01.txt");
         cout << "************************************************************************************* " << endl;
         cout << "Below is displayed the entire file. Note that the spaces in the file are not included:" << endl << endl;
         readAllFile(rec01Filename);
         cout << "\n\n**********************************************************************************" << endl << endl;
         }
         
    if (!rec01Filename){
                         cout << "The filename dataRec01.txt does not exist." << endl
                         << "Check if the dataRec01.txt and rec01.cpp files are in the same directory." << endl
                         << "Check if the name of the text file is written correctly." << endl << endl;
                         }
    else{
         ifstream rec01Filename("dataRec01.txt");
         cout << "Below the file is displayed line by line: " << endl << endl;
         readLineByLine(rec01Filename);
         cout << "\n\n**********************************************************************************" << endl << endl;
         }
         
    if (!rec01Filename){
                         cout << "The filename dataRec01.txt does not exist." << endl
                         << "Check if the dataRec01.txt and rec01.cpp files are in the same directory." << endl
                         << "Check if the name of the text file is written correctly." << endl << endl;
                         }
    else {
         ifstream rec01Filename("dataRec01.txt");
         cout << "Below the file is displayed word by word:" << endl << endl;
         readWordByWord(rec01Filename);
         cout << "\n\n**********************************************************************************" << endl << endl;
         }
             
    system("pause");
            
}
