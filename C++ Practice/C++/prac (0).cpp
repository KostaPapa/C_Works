/*
rakinur alam
2/9/2011
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//struct engine{ STRUCT PUBLIC! CLASS = PRIVATW! BY DEFULT
class Engine {
public:
       // constructor
       //Engine(){} default constructor
       //Engine() : hp(200), cylcs(8) {} // if I dont specify take this values by default or
       //Engine e1():        // hp=200; cyls=8
       //Engine e2(150, 60); // hp=150, cycls =6
       //Engine e3 (150);    // hp=150, cyls=8
       
       Engine(int thehp = 200, int thecyls = 8): hp(thehp), cyls(thecyls, brand("BLA BLA")){
                  //the line inside the body is not intitialiozation but is an assigment } // *(: <-) to initialization
       
       //way of calling: engine.display(); 
       //void display() const {
         //   display(cout);
            //cout << "HP: " << hp 
            //     <<"; Cylinders: " << cyls
            //     << endl;
            // hp = -42; without const it can change. by using const it runs in a error.
       //}
       
       //display using default prameter value
       void display(ostream& ofs = cout) const { //the function can be overloaded by using the ofstream.
            ofs << "HP: " << hp 
                 <<"; Cylinders: " << cyls
                 << endl;
            // hp = -42; without const it can change. by using const it runs in a error.
       }
       
       // Setters or Mutators
       void setBrand(const string& theBrand) const {
            brand = theBrand;
            }
       
       // Getter or Accessor     
       int getCycls() const { return cyls; } //doesnt modify anything so it is ok to make it const
         
//private:makes private (private:) *no need to use with class
private:
       string brand; //it will not couse error because even if the string isnt initialized it will print the empty string. 
       int hp;
       int cyls;
//public: to make public(public:)
};
void someFunction(const Engine& myEngine){
     myEngine.display();
}
int main(){
    //Engine engine; //BAD.
    Engine engine(120, 4);
    //engine.hp = 120; // shouldn't be allowed
    //engine.setHP(120); // BAD.
    // cout << "HP: " << engine.hp << endl;
    engine.display();
    someFunction(engine);
    // Engine secondEngine(); - CANT DO not defuly engine after first engine
    system("pause");
    //cout << engine << endl;
    ifstream ifs("engines.txt");//inputfilesream reads from fil or can say ifstream ifs;\n ifs.open("engines.txt");
    if (!ifs){
              cerr << "Dnger, danger...\n"; //cerr useful when a lot of error msg say to use when error 
              exit(3);
    }
    vector<Engine> ve;
    int hp, cylinders;
    while( ifs >> hp >> cylinders ){
           Engine someEngine(hp, cylinders);
           ve.push_back(someEngine);
    }
    for (size_t i = 0, i < ve.size(); ++i){
        ve[i].display();
        }
        
    string myString;
    string someString("Hello");
    
}
