/*

FileName:     rec12.cpp 
Name:         Kostaq Papa
ID:           0412768
Semester:     Spring 2011 
Course:       CS 1124
Lab Section:  CS 1124LAB - B2

*/



#include <iostream>
#include <string>
using namespace std;



struct Node
{
	Node(int data,Node* link):data(data),link(link){}
	int data;
	Node* link;
};


class Sequence
{
public:
	Sequence():hPtr(NULL),posPtr(NULL){}

	void add(const int data)                                           //adding a new element
	{
		if( posPtr == NULL)                                            //cheking if position pointer is NULL
		{
			hPtr = new Node(data,hPtr);                                //alocating a head pointer on the HEAP
			posPtr = hPtr;                                             //making position pointer to point at the same place as head pointer
		}

		else //(posPtr != NULL)
		{
			posPtr->link = new Node(data, posPtr->link);               //alocating on the HEAP what position pointer is connecting with
			posPtr = posPtr->link;                     
		}
	}
	void display()
	{
		Node* p = hPtr;                                                //creating a new pointer and making it point to the same place hPtr points
		while(p != NULL)                                               
		{
			cout << p->data << " ";
			p = p->link;
		}
	}
	void reset()                                                       //Resets the current position to the head of the list
	{
		posPtr = hPtr;                                                 //making position pointer to point at the same place as head pointer
	}
	void next()                                                        //advances the current position to refer to the next item 
	{
		if(posPtr != NULL)                                             //cheking if position pointer is not equal to NULL
		{
			posPtr = posPtr->link;                                     //position pointer is equal to what position pointer is connected with
		}
	}
	void remove()                                                      //removes the item at the current position
	{
		if(posPtr!=NULL)                                               //cheking if position pointer is not equal to NULL
		{
			Node* before = hPtr;                                       //creating a new pointer and making it point to the same place hPtr points

			Node* discard = NULL;                                      //creating a new pointer and making it point to NULL

			while(before->link != posPtr)
			{
				before = before->link;                                 //searching for the data that will be removed
			}
			before->link = posPtr->link;                               //linking the before pointer to what position pointer was linking
			discard = posPtr;                                          //setting the discard pointer equal po posPtr
			posPtr = posPtr->link;                                     //position pointer is equal to what position pointer is connected with
			delete discard;                                            //removing the discard element
			
		}
	}
	void data()                                                        //returns the data at the current position.
	{
		if(posPtr != NULL){
                  cout << posPtr->data;                                 //printing the corresponding data
                  }                                                                   
		else{
             cout<< "undefined";
             }
  }
	bool valid()                                                       //returns true if the current position is valid, false otherwise.
	{
		
			return (posPtr != NULL);
		
	}
	
private:
	Node* hPtr;
	Node* posPtr;
};




int main() {
  Sequence s;
  for (int i = 0; i < 6; ++i) s.add(i);
  s.display();
  cout <<endl<< "==========\n";
  s.reset();
  for (int i = 0; i < 2; ++i) s.next();
  s.add(42);
  s.display();
  cout <<endl<< "==========\n";
  s.reset();
  for (int i = 0; i < 2; ++i) s.next();
  s.remove();
  s.display();
  cout<<endl;
   cout<<boolalpha<<s.valid()<<endl;
  for (int i = 0; i < 10; ++i) s.next();
  s.data();
  cout<<endl;
  cout<<boolalpha<<s.valid()<<endl;
  
  system("pause");
}
