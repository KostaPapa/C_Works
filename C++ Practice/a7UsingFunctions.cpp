//Using Functions

#include <iostream>
#include <string>
using namespace std;

int fractional(int number);

int fractional(int number) {
    //This function will calculate the fractional of a certain number.
    
    int result = 1;
    
    for (int i=2; i<=number; ++i) {
        result *= i;
    }
    
    return result;
}

int main() {
    
    int userNumber, answer;
    string holdScr;
    
    cout << "Enter a number: ";
    cin >> userNumber;
    
    answer = fractional(userNumber);
    cout << "Number: " << userNumber << endl;
    cout << "Factorial:" << answer << endl << endl;
    
    cout << "Press any key to exit...";
    cin >> holdScr;
    
}
