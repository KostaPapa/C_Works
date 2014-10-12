/*

creating class

*/


#include <iostream>
#include <string>
using namespace std;

class Person {
public:
       Person(const string& name) : name(name), spouse(NULL){}
       
       void display(ostream& os = cout) const { //what does the = cout do? alowwos me to call this method in two different ways, allows me to pass the stream or not to use the strem (ostream) and directly use the cout.
            os << "Name: " << name;
            if (spouse == NULL){ // means not married
               os  << "; Single \n";
            else{
                 //os << "; Spouse: " << spouse << endl //will print only the address that way
                 //os << "; Spouse: " << *spouse.name << endl //what we want. the name..the correct way of writng it
                 //os << "; Spouse: " << (*spouse.name) << endl //if i use ( ) it says get the filed from the pointer whivh it doent have a name or a field. NOT GOOD
                  os << "; Spouse: " << *spouse->name << endl //the bast way ever. //we can acces the name.
       }       
       
       
       
       bool married() const { //getter, return true or false
            //if (spouse!= NULL){
              // return true;
            //}
            
            //else {
              //   return false;
            //}       
            return spouse != NULL; //This is more usable.. than the if else
       }
       //john.marry(marry) in this case the object is waht is being passed as mary
       //john.marry(&marry) if i woant to pass the address.
       void marry(Person &betrothed){ //it is passed by value, wiich is a copy which is a temporary copy. if we want brtoennend to be acually married we have to pass by reference. is fixed to pass by reference.
            spouse = &betrothed; //i take the person address(is done by using this character &) and i store it at the spouse pointer.
            betrothed.spouse = this; //it is holding the adreess of the function being called, getting our own adress. this is a hidden variable that holds our adress, that holds the address of the person u re colling, so it is the address of john. we can pass by constant but we want to modyfy it, we wanted to store the address in the tspuse funtcion. In this way i wanted it changable.
            
            //example
            //1) const int x = 17;
            //2) int* p = &x;  -->   this is the compilation error, becouse we have declared x as a constatnt and using the pointer it doesnt guarantee that its address or even its value to be unchangle.
            //3) *p=42;
            
            

private:    
            
        
        string name;
        //Person spouse;  //Everything has a size. The objceet is goinf to take a particulary no of stape in memory. The size of the objetc is 20 + 8 = 28 includeing the string and the Person. How do I squesse space?? 
        
        Person* spouse; //will hold the reference of spouse
        
        };
        
void badFillPersons(ifsteam& ifs, vector<Person>& vpp){
     
      //an alternative
    //VERY VERY Worse
    string name;
    while (peopleStream >> name){
          Person aPerson(name);
          vpp.push_back(&aPerson); //pushing back its address. the aPerson exists in the callStack and want exist after the while loop is executed.
}
}
        
int main(){
    
    Person john("John");
    //john.display(cout) // if i dont write the ostream at the void display function, back to the class.
    john.display() //the right way of writing it if u use the osstream
    Person mary("Mary");
    //john.marry(mary)
    
    int x = 48;
    cout << &x << endl; //Finds where 48 is located in memiry. It can be used to save the space 20 + 8 = 28 expamle.
    int* p = &x; //Storing the palce of mamery in the variable p. What type would that be?...That type is called a pointer. it is written int* p = ..
    cout << p << endl; //So u will get the reference.
    cout << *p << endl; //will print the number int.
    *p = 17; //modyfing the pointer, [putting a new value.
    cout << *p << endl;
    p = NULL; //a varibale and a value that it is not pointed to anything. if u use zero in stead of null it will have a reference.
    
    int y = 20;
    int* q = &y;
    //int *q = &y;
    //or
    //int * q = &y; //not usable   
    
    int *r,s; //only r is a pointer
    int *r, *s; //ponts to every variable;
    
    //constant pointer --> means cant change which is pointing.
    int* const ptr = &x; //ptr cannont be changes. the folloing lines with give errors. i can change the contect of the ptr.
    ptr = &y;
    const int* ptr = &x //am not allowed to modify the contact of what ptr have. The folloinw will be an error. ??? qustion
    *ptr = 100; //this is legal. 
    
    new Person("Elvis"); //--> creating a variable in the heap.
    //new returns the adress that is put in the heap.
    
    Person* personPtr = new Person("Elvis"); // --> storing the address of "Elvis".
    //"elvis" is on the heap.
    
    delete personPtr; //it is ok in this case. Before the personPtr.
    personPtr->display(); //displayng by using the method of People. //*spouse->name makes this possible.
    //delete personPtr; //operator. add the address the thing u dont want. effect the place in memory the object was. it doent delete the variable or its adress. it remves it form the place of heap.
    
    personPtr = NULL; // in this case a can delete as many as i need.
    delete personPtr; //ok
    delete personPtr; //ok
    delete personPtr; //ok
    delete personPtr; //ok


    //>>>reading from the file.<<<
    
    ifstream peopleStream("people.txt");
    if (!peopleStream){
                       cerr<<"Error" << endl;
                       exit(17);
    }
    /creating vectors of pointers.

//callstack --> it is a memory where variables stays temp
//heap --> heap grows and thus callstack increases too. is used to create things and keep them as long as u want.

    vector<Person*> people; //vectro of pointers to persons taht will hold not the name but their adresses.
    string name;
    while (peopleStream >> name){
          Person* p = new Person(name);
          people.push_back(p); //adding the address.//we have only one person but two addresses that pointes to the same person. If i cande the na,e in the first adress, we will find that even if we call the same name by the second address the name..
          //delete p; //never do that. it delets the address. it is called dangling pointers.
    }
    
    for (size_t i=0; i< people.size; ++i){
        people[i]->display(); //calling the names by their addresses and dispalys them.
    }
    
    //an alternative
    //VERY VERY BAD
    while (peopleStream >> name){
          Person aPerson(name);
          people.push_back(&aPerson); //pushing back is address.//is used as worse in the void funtion in the main
    
    
    
    system("pause");   
}}    
    
    
    
    
    
