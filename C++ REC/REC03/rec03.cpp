/*

FileName:     rec02.cpp 
Name:         Kostaq Papa
Semester:     Spring 2011 
Course:       CS 1124
Lab Section:  CS 1124LAB - B2

*/


#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Sandwich {
      
public: 
        
        Sandwich (const string& breadName, const string& cheeseName, int tomatoSlice = 2, int cheeseSlice = 1, 
                 double mustard = 0.05, double mayonnaise = 1.0)
        : breadType(breadName), cheeseType(cheeseName), cheeseSlice(cheeseSlice), tomatoSlice(tomatoSlice),
          mayonnaise(mayonnaise), mustard(mustard)
                 
        {
                 
                 breadSlice = 2;
                 
        }                 
        
        void display() const{
             cout << "Type of bread: " << breadType << "\n"
                  << "Bread slices: " << breadSlice << "\n"
                  << "Tomato slices: " << tomatoSlice << "\n"
                  << "Type of cheese: " << cheeseType << "\n"
                  << "Cheese slices: " << cheeseSlice << "\n"
                  << "Mustard: " << mustard << "\n"
                  << "Mayonnaise: " << mayonnaise << endl;
             }
             
        void amountOfMoyo() const{
             cout << "Moyo: " << mayonnaise << endl;
        }
             
        void newAmountOfMoyo(int newMayonnaise){

             mayonnaise = newMayonnaise;
             cout << "New amount of moyo " << newMayonnaise << endl;
        }
        
        void newBreadName(string newBread){
             
             breadType = newBread;
             cout << "New bread name: " << newBread << endl;
             }
        
        void newAmountOfCheese(int newCheese){
             
             cheeseSlice = newCheese;
             cout << "New bread name: " << cheeseSlice << endl;
             }
        
        
private:
        
        string breadType;
        string cheeseType;
        int breadSlice;
        int tomatoSlice;
        int cheeseSlice;
        double mustard;
        double  mayonnaise;
        
};
        
        
class truckDelivary{

public: 
        
        void addSandwichinTheTruck(Sandwich sw){
             truck.push_back(sw);
        }
             
        
private:
        
        vector<Sandwich> truck;
        
};

int main(){
    
    cout <<"Customer1" << endl << endl;
    Sandwich Customer1("bread name", "cheese");
    Customer1.display();
    
    cout <<"Customer2" << endl << endl;
    Sandwich Customer2("bread name", "cheese");
    Customer2.newAmountOfMoyo(0);
    Customer2.display();
    
    cout <<"Customer3" << endl << endl;
    Sandwich Customer3("bread", "cheese");
    Customer3.newAmountOfCheese(2);
    Customer3.display();
    
    cout <<"Customer4" << endl << endl;
    Sandwich Customer4("bread", "cheese");
    Customer4.display();
       
    
    system ("pause");
    
}
    
    
    
    
    
