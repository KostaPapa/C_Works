/*

FileName:     rec09.cpp 
Name:         Kostaq Papa
ID:           0412768
Semester:     Spring 2011 
Course:       CS 1124
Lab Section:  CS 1124LAB - B2

*/
#include <string>
#include <iostream>
using namespace std;

class Position {
public:
	Position(const string& aTitle, double aSalary)
	: title(aTitle), salary(aSalary) {}
	string getTitle() const {return title;}
	double getSalary() const {return salary;}
	void changeSalaryTo(double d) {salary = d;}
private:
	string title;
	double salary;
};

class Entry {
public:
	Entry(const string& aName, unsigned aRoom, unsigned aPhone, Position& aPosition) 
	: name(aName), room(aRoom), phone(aPhone), pos(&aPosition) {
	}
	friend ostream& operator<<( ostream& os, const Entry& e ) {
		os << e.name << '\n'
		<< e.room << '\n' 
		<< e.phone;
		return os;
	}
	string getName(){
		return name;
	}
	unsigned getPhone(){
		return phone;
	}
private:
	string name;
	unsigned room;
	unsigned phone;
	Position* pos;
}; // Entry

class Directory {
public:
	Directory()
	: capacity(2), size(0), entries(new Entry*[2] )
	{
		for (size_t i = 0; i < capacity; i++) {
			entries[i] = NULL;
		}
	}
	~Directory(){
		for( size_t i = 0; i < size; ++i){
			delete entries[i];
		}
		delete [] entries;
	}

	Directory(const Directory& newEntry){
		size = newEntry.size;
		capacity = newEntry.capacity;
		entries = new Entry*[newEntry.capacity];
		for (size_t i = 0; i < size; ++i){
			entries[i] = newEntry.entries[i];
		}
	}
	Directory& operator=(const Directory& newEntry){
		if(this != &newEntry){
			for( size_t i = 0; i < size; ++i){
delete entries[i];
			}
			delete [] entries;
			entries = new Entry*[newEntry.capacity];
			size = newEntry.size;
			capacity = newEntry.capacity;
			for (size_t i = 0; i < size; ++i){
				entries[i] = newEntry.entries[i];
			}
		}
		return *this;
	}
	void add(const string& name, unsigned room, unsigned ph, Position& pos) {
		if( size == capacity )	{
			// something is missing!!!  Add it!
			entries = new Entry*[ capacity *= 2 ];
			// something is missing!!!  Add it!
		}
		entries[size++] = new Entry(name, room, ph, pos);
	}
	friend ostream& operator<<( ostream& os, const Directory& z ) {
		for(size_t i=0; i < z.size; ++i ){
			os << z.entries[i];
		}
		return os;
	}
	unsigned operator[](string name){
		int index(0);
		while(size<this->capacity && name != this->entries[index]->getName()){
		index++;
		}
		
		return this->entries[index]->getPhone();
	}

private:	
	Entry** entries;
	size_t size;
	size_t capacity;
};

int main() {
	
	// Model as if there are these four kinds 
	// of position in the problem:
	Position boss("Boss", 3141.59);
	Position pointyHair("Pointy Hair", 271.83);
	Position techie("Techie", 14142.13);
	Position peon("Peonissimo", 34.79);
	
	// 
	Directory d;
	d.add("Marilyn", 123, 4567, boss);
	Directory d2 = d;	// What function is being used.
	d2.add("Gallagher", 111, 2222, techie);
	Directory d3;
	d3 = d2;
	
}

