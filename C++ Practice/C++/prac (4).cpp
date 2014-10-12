#include <iostream>
#include <string>
#include "Frog.h"
#include "Function.h"
#include "Princess.h"
using namespace std;



int main(){system ("pause");}

void Frog::setSpouse(Princess& snowWhite){
            spouse = &snowWhite;
       }
       
void Frog::display() const {
     cout << "Frog name: " << name;
     if(spouse != NULL){
               cout << "; spouse: " << spouse->getName();
               cout << endl;
     }
}
