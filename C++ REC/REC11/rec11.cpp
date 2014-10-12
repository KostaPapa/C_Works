/*

FileName:     rec11.cpp 
Name:         Kostaq Papa
ID:           0412768
Semester:     Spring 2011 
Course:       CS 1124
Lab Section:  CS 1124LAB - B2

*/

#include <iostream>
#include <cstdlib> // To allow NULL if no other includes
using namespace std;

struct Node {
	Node(int data = 0, Node* next = NULL) : data(data), next(next) {}
	int data;
	Node* next;
};

void listInsertHead(int entry, Node*& headPtr) {
	headPtr = new Node(entry, headPtr);
}

void listDisplay(const Node* headPtr) {
     
     const Node* p = headPtr;
     
     while (p != NULL) {
           cout << p->data << ' ';
           p = p->next;
     }
     cout << endl;
}

void addEntry (int entry, Node*& headPtr) {     
     
     Node* temp = new Node;
     temp->data = entry;
     temp->next = headPtr;
     headPtr = temp;
}

void spliceInto(int target, Node*& listOne, Node* listTwo) {
     Node* temp1 = listOne;
     while (temp1->data != target){
           temp1 = temp1->next;
     }
     Node* temp2 = temp1->next;
     temp1->next = listTwo;
     while(listTwo->next != NULL){
                         listTwo = listTwo->next;
     }
     listTwo->next = temp2;
}

void isSubList(Node*& targetList, Node* matchList){
     
     Node* tempT = targetList;
     Node* tempM = matchList;
          
     while(tempT->next != NULL && tempM->next != NULL){
                       if(tempT->next->data == tempM->next->data){
                                            Node* tempM1 = tempM->next;
                                            while(tempM1->next != NULL && tempT->next != NULL){
                                                               tempM1 = tempM1->next;
                                                               tempT = tempT->next;
                                            }
                                            if(tempM1->next == NULL){
                                                            targetList = tempT;
                                                            break;
                                            }
                       }
                       else{
                            //cout << "FAIL" << endl;
                            tempT = tempT->next;
                       }
     }
}  

int main(){
    
    cout << "Part One: \n" << endl;
    
    Node* L1 = NULL; 
    addEntry(1, L1);
    addEntry(9, L1);
    addEntry(7, L1);
    addEntry(5, L1);
    cout << "L1: "; 
    listDisplay(L1);
    
    Node* L2 = NULL;
    addEntry(2, L2);
    addEntry(3, L2);
    addEntry(6, L2);
    cout << "L2: ";
    listDisplay(L2);
    
    cout << "Target: 7 9 1" << endl;
    cout << "Splicing L2 at target in L1" << endl;
    
    //spliceFrom(7, L1);
    spliceInto(7, L1, L2);
    cout << "L1: ";
    listDisplay(L1);
    cout << "L2: ";
    listDisplay(L2);
    
    cout << "\n===============\n\n";
    cout << "Part Two: \n" << endl << endl;
    
    Node* T = NULL; 
    addEntry(6, T);
    addEntry(5, T);
    addEntry(4, T);
    addEntry(2, T);
    addEntry(3, T);
    addEntry(2, T);
    addEntry(3, T);
    addEntry(2, T);
    addEntry(1, T);
    cout << "Target: "; 
    listDisplay(T);
    cout << endl;
    
    Node* M1 = NULL;
    addEntry(1, M1);
    cout << "Attempt match: ";
    listDisplay(M1);
    isSubList (T, M1);
    listDisplay(T);   
    
    Node* M3 = NULL;
    addEntry(3, M3);
    addEntry(2, M3);
    cout << "\nAttempt match: ";
    listDisplay(M3);
    isSubList (T, M3);
    listDisplay(T);
    
    system("pause");
}













