//Using Vectors

#include <iostream>
#include <vector>
using namespace std;

int main() {
    
    char holdScr;
    vector<int> vectorOfInts(10);
    
    vectorOfInts.push_back(5);
    vectorOfInts.push_back(8);
    
    cout << "The elements of the vector are: " << vectorOfInts[10] << '\t' << vectorOfInts[11] << endl << endl;
    cout << "The size of the vector is: " << vectorOfInts.size() << endl << endl;
    
    cout <<"Press any key to exit...";
    cin >> holdScr;
    
}
