// Simplest program

#include <iostream>
#include <string>
using namespace std;

int main() {
    
    string name, holdScreen;
    float num1, num2, sumOfSquares;
    
    cout << "Please enter your name: ";
    cin >> name;
    cout << "Hello Mr. " << name << endl << "Thank you for using this progam!!!" << endl << endl;
    
    cout << "Enter two numbers and I will find the sum of their squares." << endl;
    
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
    
    cout << "The sum of their squares is: ";
    sumOfSquares = (num1 * num1) + (num2 * num2);
    cout << sumOfSquares << endl;
    
    
    cout << "Please, type y to exit...";
    cin >> holdScreen;    
}
