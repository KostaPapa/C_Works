// First Use Of C++ For Loop

#include <iostream>
using namespace std;

int main() {
    
    char holdScr;
    int j = 3;
    
    for (int i=0; i<10; i=j+i) {
        cout << "Hello There!"<< endl;
    }
    
    cout << "Please, type y to exit...";
    cin >> holdScr;
    
}
