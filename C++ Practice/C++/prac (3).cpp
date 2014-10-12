#include<iostream>
#include<string>
#include<vector>
using namespace std;


class Pet{
      // operator << (cout, peeve);
friend ostream& operator << (ostream& os, const Pet& aPet); //returning by reference
friend bool operator == (const Pet& lhs, const Pet& rhs){ //u can put all the definition inside the class
     return lhs.name == rhs.name;
}
friend bool operator < (const Pet& lhs, const Pet& rhs);
friend bool operator <= (const Pet& lhs, const Pet& rhs);

public:
       Pet(const string& name) : name(name){}
       virtual void display() const{
            cout << "Name: " << name << endl;
       }
       
       virtual void eat(){
               cout << "eating" << endl;
       }

protected: //other classes can get the code too.
          string getName()const{return name;}
private:
        string name;
};

// operator << (cout, peeve);
ostream& operator << (ostream& os, const Pet& aPet){
         //os << "Pet name: " << aPet.name; will not compile
         //os << "Pet name: " << aPet.getName(); not required cause is wirtten at the friend place on the class.
         os << "Pet name: " << aPet.name; //now willl compile
     return os;
}

bool operator != (const Pet& lhs, const Pet& rhs){ //u can put all the definition inside the class
     return !(lhs == rhs);
}

bool operator <= (const Pet& lhs, const Pet& rhs){ //u can put all the definition inside the class
       return (lhs < rhs) || (lhs == rhs);
}

int main(){
    
    Pet peeve("Peeve");
    
    //the function call will look like:
    //operator << (cout, peeve);
    cout << peeve << endl; //if i do not return the os in the above funtion, the chain in endl will not happen.
    
    cout << "\nOR\n\n";
    operator << (cout, peeve) << endl;
    
    // operator // (test) ? evaluate if test true : evaluate if test false // this cannot be overloaded
    
    cout << "\nAND\n\n";
    Pet fred("Fred");
    //if(peeve == fred){ dont
    if( operator == (peeve, fred)){
        cout << peeve << fred << endl;
    }
    else {
         //operator << (peeve, fred);
         cout << peeve << endl <<fred << endl;
    }
    
    
    system("pause");
}
    
    
    
    
    
    
