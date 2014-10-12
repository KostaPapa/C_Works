//INHERITANCE


#include<iostream>
#include<string>
#include<vector>
using namespace std;


class Pet{
public:
       Pet(const string& name) : name(name){}
       virtual void display() const{
            cout << "Name: " << name << endl;
       }
       
       virtual void eat(){ //eat is special method. So sluggies can eat differtently. 
             cout << "eating" << endl;
        }

protected: //other classes can get the code too.
          string getName()const{return name;}
private:
        string name;
};

      
class Cat : public Pet{
public:
       //Cat(const string& name) : name(name) {} //WRONG
       
       Cat(const string& name, const string breed) 
       : Pet(name), breed(breed) {}
       
       // void display() const{
         //   cout << "Name: " << name
           // << "Breed: " << breed << endl;
       //}
       
       void display()const{
            Pet::display();  //if i dont put Pet:: then dispaly will call itself.
            cout << "Breed: " << breed << endl;
       }
       
       void purr(){}
       
       //void dispaly(){
         //   cout << "Name: " << getName();
           // cout << "; Breed: " << breed << endl;
       //}
            
private:
        string name, breed;
       
};
class Slug : public Pet{
public:
       Slug(const string& name) : Pet(name) {}
       void eat(){
            cout << "slug eat they way" << endl; //overwritting if i want it different from what is written in the Pets class. This method will replace it.
       }
      
};
class Roach : public Pet{
public:
       Roach(const string& name) : Pet(name) {}
};

void displayPet(const Pet& aPet){ //it can be accesed not only using the pointer in the for loop but laso by creating this method.    aPet.display();
     aPet.display();
}

class Shape{
public:
       Shape(int x, int y) : x(x), y(y){}
       virtual void move() = 0; //equal 0 --> PURE VIRTUAL /OR/ ABSTRACT //not allowd to put a body in these methods.
       virtual void draw() const = 0;
private:
        int x,y;
};

void Shape::move() {cout << "Moving\n";}

class Circle: public Shape{
public:
       Circle(int x, int y) : Shape(x,y){} //constractor invoking the shape class.
       virtual void move() { Shape::move(); }
       virtual void draw() const {}       
       
};

//multiple inheritance ******
class Person{
private:
        string name;
};
class Studens : public virtual Person{    //virtual inheritance
public:
       void display() const {cout << "Students"<<endl;}     
private:
        //string name;
};
class Instructior : public virtual Person{
public:
       void display() const {cout << "Instructor"<<endl;}      
private:
        //string name;
};
class TA : public Studens, public Instructior
{
public:
       TA():Studens(), Instructior() {}
       void display() const {
            Studens::display();
            Instructior::display();            
       }      
};





int main(){
    
    Cat felix("Felix", "Persian");
    felix.display();
    felix.eat();
    
    Slug sluggo("Sluggo");
    sluggo.display();
    sluggo.eat(); //they eat in they own way
    
    Pet peeve("Peeve");
    
    //cout << felix.getName() << endl; //it cant be called in the main. it can be called only between classes
    
    cout <<"\n\nUSING VECTOR" << endl;
    
    /*
    vector<Pet> vp;
    vp.push_back(felix);
    vp.push_back(peeve);                    //this block will compile but will not print the way sluggs eat as specified in the slugg class.
    vp.push_back(sluggo);
    for (size_t i=0; i<vp.size(); ++i){
        vp[i].eat();
    }
    */
    
    vector<Pet*> vp;
    vp.push_back(&felix);
    vp.push_back(&peeve);
    vp.push_back(&sluggo);                  //two ways for written this bllok. See the funtion above main.
    for (size_t i=0; i<vp.size(); ++i){
        vp[i]->eat();
    }
    
    //Cat*cp = &peeve;
    //cp->purr();
    
    //Circle circ;
    
    Shape* shapedPtr = new Circle(1,2); //so it can be used polymorphism
    Circle circ(17,42);
    cout <<"\n\nMULTIPLE INHERITANCE" << endl;
    TA fred;
    //fred.display();
    fred.Studens::display();
    fred.Instructior::display();
    cout << "OR" << endl;//or
    fred.display();
    
    system("pause");
    
    //things to review
    //polymorphism --> being able to acces a derived object from its base class. (being able to write in code where each pet can eat in its own way.) Base class has to mark each method that wil be used as virtual. How u call them? by using vec of pointers or functions.
    //virtual mechanisms
    // complite-time --> static binding
    // run-time --> dynamic binding
    
    //new topic --> multiple inheritance --> student -- instructor -- TAs //
    
    /*
    wat can we do and and not do in terms of the assignemt
    
    
    
    
    
    
    
    
    */
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
}
