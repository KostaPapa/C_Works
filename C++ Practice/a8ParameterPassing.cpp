//Parameter Passing

#include <iostream>
using namespace std;

int addOne( int& number){
    //This function will add one to the passed number.
    
    number += 1;
    return number;
    
}

int main() {
    
    char holdScr;
    int answer, userNo;
    
    cout << "Enter an integer: ";
    cin >> userNo;    
    answer = addOne(userNo);    
    cout << "Number: " << userNo << "\t" << "Answer: " << answer << endl << endl;
    
    cout << "Enter another number: ";
    cin >> userNo;
    answer = addOne(userNo);
    cout << "Number: " << userNo << "\t" << "Answer: " << answer << endl << endl;
    
    
    cout << "Press any key to exit...";
    cin >> holdScr;
    
}
