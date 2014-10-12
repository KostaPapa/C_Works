//Reading from a file

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int readFile() {
    
    char holdScr;
    int integers;
    ifstream numFileName("a5ReadingFromFile.txt");
    
    while (numFileName >> integers){
          cout << integers;
    
    
    }
    
    cout << "Please, press y to exit...";
    cin >> holdScr;
}

int main(){
    
    readFile();
    
}
    

