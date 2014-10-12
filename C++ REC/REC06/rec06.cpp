/*

rec06.cpp
Name:         Kostaq Papa
ID:           0412768
Semester:     Spring 2011
Course:       CS 1124
Lab Section:  CS 1124LAB - B2

*/ 



#include <iostream>
#include <vector>
using namespace std;

class PrintedMaterial {
public:
	PrintedMaterial(unsigned numPages):
	  numberOfPages(numPages) {
	  }
	  virtual
	  void displayNumPages() const{ 
		  cout << numberOfPages << endl; 
	  }
protected:
private:
	unsigned numberOfPages;
};

class Magazine : public PrintedMaterial {
public:
	Magazine( unsigned numPages):
	PrintedMaterial(numPages) {
	  }
	void displayNumPages() const{
		PrintedMaterial::displayNumPages();
	}
protected:
private:
	
};

class Book : public PrintedMaterial {
public:
	Book( unsigned numPages) :
	  PrintedMaterial(numPages) {
	  }
	 
	  
protected:
private:
	
};

class TextBook : public Book {
public:
	TextBook( unsigned numPages, unsigned numIndexPages) :
	  Book(numPages) , numOfIndexPages(numIndexPages) {
	  }
	  void displayNumPages() const {
		  PrintedMaterial::displayNumPages();
	  }
	 
protected:
private:
	unsigned numOfIndexPages;
	
};

class Novel : public Book {
public:
	Novel( unsigned numPages) :
	  Book(numPages) {
	  }
	  void displayNumPages() const {
		  PrintedMaterial::displayNumPages();
	  }

protected:
private:
	
};

void displayNumberOfPages(const PrintedMaterial& anytype) {
	anytype.displayNumPages();
}

// tester/modeler code
int main()
{
	TextBook t(2454, 25);
	Novel n(128);
	Magazine m(192);

	t.displayNumPages();
	n.displayNumPages();
	m.displayNumPages();

	//PrintedMaterial pm(2564);
	//pm.displayNumPages();

	//PrintedMaterial pm = t; // like putting a t into a vector of PrintedMaterials
    //pm.displayNumPages();

	PrintedMaterial* pmPtr;
	pmPtr = &t; // like putting t into a vector but
	            // we are actually putting the address of t
	            // into a vector pointers of pointers to
	            // PrintedMaterials. We'll "say" we are putting

	pmPtr->displayNumPages();

	displayNumberOfPages(t);
	displayNumberOfPages(n);
	displayNumberOfPages(m);

	vector<PrintedMaterial*> printAll;
	printAll.push_back(&t);
	printAll.push_back(&n);
	printAll.push_back(&m);

	for(size_t i = 0; i < printAll.size(); ++i) {
		printAll[i]->displayNumPages();
		cout << endl;
	}


}
