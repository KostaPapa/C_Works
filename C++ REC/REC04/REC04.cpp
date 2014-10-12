/*

FileName:     rec04.cpp 
Name:         Kostaq Papa
ID:           0412768
Semester:     Spring 2011 
Course:       CS 1124
Lab Section:  CS 1124LAB - B2

*/


#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;

class PlainOldClass {  
public:
   PlainOldClass() : x(x) {}
   int getX() const { return x; }
   void setX( int x )  { this -> x = x; } 
   void display() {
	   cout << "this is x " << x << endl; }

private:
   int x;
};
class Colour {  
public:       
    Colour( const string& name, unsigned r, unsigned g, unsigned b )       
        : name(name), r(r), g(g), b(b) {}       
    void display() const { 
        cout << name << " (RBG: " << r << "," << g<< "," << b << ")"; 
    }   
private:       
    string   name;    // what we call this color       
    unsigned r, g, b; // red/green/blue values for displaying  
};         
struct Complex {
   double real;
   double img;
};

class Person {  
public:       
    Person( const string& name ) : name(name) {}
    void movesInWith( Person& newRoomate ) {
        roomie = &newRoomate;        // now I have a new roomie            
        newRoomate.roomie = this;    // and now they do too       
    }       
    string getName() const { return name; }       
    string getRoomiesName() const { return roomie->getName(); }  
private:
    Person* roomie;       
    string name;  
};           



int main() {
	PlainOldClass bored;
	bored.setX(42);
	bored.display();


	

	//////Task 2
	int x;
	x = 10;
	cout << "x = " << x << endl;
	
	int* p;
	p = &x;
	cout << "p = " << p << endl;
	*p = -2763;  
	cout << "p points to where " << *p << " is      stored\n";  
	cout << "*p now contains " << *p << endl;  
	cout << "x now contains " << x << endl;
	int y(13);      
	cout << "y contains " << y << endl;      
	p = &y;      
	cout << "p now points to where " << *p << " is stored\n";      
	cout << "*p now contains " << *p << endl;      
	*p = 980;      
	cout << "p points to where " << *p << " is stored\n";      
	cout << "*p now contains " << *p << endl;      
	cout << "y now contains " << y << endl;
	double d(33.44);      
	double* pD(&d);      
	*pD = *p;      
	*pD = 73.2343;      
	*p  = *pD; //questionable. p double and int wont work      
	//int* q  = *p; //this wont work...      
	//pD  = p;
	int joe( 24 );  
	const int sal( 19 );    
	int*  pI;  
	pI = &joe;  
	*pI = 234;  
	//pI = &sal;  //cant do this bcz next thing u wanna do is to change the value of that varible and its not allowed since its a const
	*pI = 7623;    

	//const int* pcI;
	//pcI = &joe;  
	//pcI = 234;  //not possible
	//pcI = &sal;  
	//*pcI = 7623;    

	//int* const cpI;
	//int* const cpI(&joe);
	//int* const cpI(&sal); //cant assign to different pointer
	//cpI = &joe;  
	//*cpI = 234;  
	//cpI = &sal;  
	//*cpI = 7623;    

	//const int* const cpcI;
	//const int* const cpcI(&joe);
	//const int* const cpcI(&sal);
	//cpcI = &joe;  
	//*cpcI = 234;  
	//cpcI = &sal;  
	//*cpcI = 7623;  
	int *pDyn = new int(3);
	*pDyn = 17;
	cout << "The " << *pDyn << " is stored at address " << pDyn<< " which is in the heap\n";
	cout << "The " << *pDyn << " is stored at address " << &pDyn<< " which is in the heap\n";
	delete pDyn;
	pDyn = NULL;
	double* pDouble(NULL);
	vector<Complex*> compli;
	Complex* tempCmplx;
	for ( size_t ndx = 0 ; ndx < 3 ; ++ndx ) {
		tempCmplx = new Complex;
		tempCmplx->real = ndx;
		tempCmplx->img  = ndx;
		compli.push_back( tempCmplx );
}      
// display them      
	for ( size_t ndx = 0 ; ndx < 3 ; ++ndx ) {         
		cout << compli[ ndx ]->real << endl;         
		cout << compli[ ndx ]->img  << endl;      
//}      
// release them      
	//for ( size_t ndx = 0 ; ndx < 3 ; ++ndx ) {         
		//delete compli[ ndx ];      
//}      
// clear the vector      
//compli.clear();    
	vector< Colour* > colours;         
string inputName;       
unsigned inputR, inputG, inputB;   // fill vector with Colours from the file       
                                   // this could be from a file but we are using the keyboard for now       
                                   // (do you remember the keystrokes to indicate "end of file" at the keyboard?)   
ifstream ifs("colors.txt");

while ( ifs >> inputName >> inputR >> inputG >> inputB ) {            
    colours.push_back( new Colour(inputName, inputR, inputG, inputB) );       
}         

// display all the Colours in the vector:       
for ( size_t ndx = 0; ndx < colours.size(); ++ndx ) {            
    colours[ndx]->display();            
    cout << endl;       
}
// write code to model two people in this world       
Person joeBob("Joe Bob"), billyJane("Billy Jane");         
// now model these two becoming roommates       
joeBob.movesInWith( billyJane );         
// did this work out?       
cout << joeBob.getName() << " lives with " << joeBob.getRoomiesName() << endl;
cout << billyJane.getName() << " lives with " << billyJane.getRoomiesName() << endl;

	system("pause");

	}
}
