//Using Structs

#include <iostream>
#include <string>
using namespace std;

int main() {
    
    string holdScr;
    
    struct Cat {
           
           string name, color;
           double age;
           
    };
    
    {
           Cat myCat;
           myCat.name = "Felix";
           myCat.color = "White";
           myCat.age = 3.33;
           cout << myCat.name << "\t" << myCat.color << "\t" << myCat.age << endl;
    
           Cat friendCat;
           myCat.name = "John";
           myCat.color = "Black";
           myCat.age = 0.5;
           cout << myCat.name << "\t" << myCat.color << "\t" << myCat.age << endl;
    
           Cat sameAsMyCat;
           sameAsMyCat = myCat;
           cout << sameAsMyCat.name << '\t' << sameAsMyCat.color << '\t' <<sameAsMyCat.age << endl << endl;
    
           if (sameAsMyCat.name == friendCat.name && sameAsMyCat.color == friendCat.color && sameAsMyCat.age == friendCat.age){
                         cout << "They are the same" << endl;
           }
           else {
                         cout << "They are not the same" << endl;
           }
    }
    
    cout << "Please press y to exit...";
    cin >> holdScr;
    
}
