//Using Conditions

#include <iostream>
using namespace std;

int main() {
    
    char holdScr;
    int grade;
    
    cout << "Please, enter the grade: ";
    cin >> grade;
    
    if (grade < 50) {
         cout << "Your grade is F" << endl;
    }
    else if (50 <= grade <= 63){
         cout << "Your grade is D" << endl;  
    }     
    else if (64 <= grade <= 66){
         cout << "Your grade is D+" << endl;  
    }
    else if (67 <= grade <= 69){
         cout << "Your grade is C-" << endl;  
    }
    else if (70 <= grade <= 73){
         cout << "Your grade is C" << endl;  
    }
    else if (74 <= grade <= 76){
         cout << "Your grade is C+" << endl;  
    }
    else if (77 <= grade <= 79){
         cout << "Your grade is B-" << endl;  
    }
    else if (80 <= grade <= 83){
         cout << "Your grade is B" << endl;  
    }
    else if (84 <= grade <= 86){
         cout << "Your grade is B+" << endl;
    }
    else if (87 <= grade <= 89){
         cout << "Your grade is A-" << endl;
    }
    else //(90 <= grade <= 100)
    {
           cout << "Your grade is A" << endl;
    }
    
    cout << "Please, type y to exit...";
    cin >> holdScr;
    
}
    
    
    
    
       
