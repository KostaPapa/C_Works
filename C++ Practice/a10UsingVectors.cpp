//Using functions of vectors

#include <iostream>
#include <vector>
using namespace std;

void displayVector (const vector<int>& aVector){
     
     for (size_t i = 0; i < aVector.size(); i++ ){
         cout << aVector[i] << endl;
     }
}

int main(){
    
    char holdScr;
    vector<int> intVector;
    
    intVector.push_back(10);
    intVector.push_back(12);
    intVector.push_back(7);
    intVector.push_back(4);
    
    displayVector (intVector);
    
    cout << "Press any key to exit...";
    cin >> holdScr;
    
}
