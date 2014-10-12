#include <iostream>
#include <string>
using namespace std;

struct Node { int data; Node* link; };

void addToList(Node*& hPtr, int number){
     
     Node* tmpPtr = new Node;
     tmpPtr->data = number;
     
     tmpPtr->link = hPtr;
     hPtr = tmpPtr;
}

void copyList(Node* L1){
     
     if(L1 != NULL){
                 L2->data = L1->data;
                 L2->data = NULL;
     }
     copyList(L1->link, &((*L2)->link));
}
  
void display(Node* hPtr){
     while(hPtr != NULL){
                cout << hPtr->data << endl;
                hPtr = hPtr->link;
     }
}
      

int intToBinary(int num){
    
    int bit1 = 1;
    int bit0 = 0;
    
    if (num != 0){
    intToBinary(num/2);
    }
    if(num%2 == bit1){
             cout << bit1;
    }
    else{ //(num%2 == bit0){
         cout << bit0;         
    }
}

int main(){
    
    intToBinary(8);
    
    cout << endl << endl;
    
    Node *first = new Node;
    Node *second = new Node;
    first = NULL;
    second = NULL;
    
    addToList(first, 1);
    addToList(first, 2);
    addToList(first, 3);
    
    display(first);
    //copy(first, &second);
    //display(second);
    
    
    
    system("pause");
}
