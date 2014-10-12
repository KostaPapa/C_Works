/*

rec05.cpp
Name:         Kostaq Papa
ID:           0412768
Semester:     Spring 2011
Course:       CS 1124
Lab Section:  CS 1124LAB - B2

*/ 


#include <vector>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Student
{
	public:
		Student ( const string& name) : name(name), grades(13, -1) {}
		string getStudentName() {
			return name;
		}

		void displayStudentInfo()
		{
			cout << "Student's Name: " << name << "; Grades Of the Student: ";
			for(size_t i= 0; i < grades.size(); ++i)
			{	
				cout << grades[i];
			}
			cout << endl;
		}

		void addStudentGrades( int grade, int week )
		{
			grades[week] = grade;
		}
	private:
		string name;
		vector<int> grades;
};

class TimeSlot
{
	public:
		TimeSlot( const string& day, unsigned int time ) : day( day ), time( time ) {}
		void displayTime() 
		{
			cout << day
				 << " " << time;
		}
	private:
		string day;
		unsigned int time;
};


class Section 
{
	public:
		Section (const string& secName, string day, unsigned int time) : secName(secName), time(day, time){} ;
		string getSecName()
		{
			return secName;
		}

		void getTime() 
		{
			time.displayTime();
		}
		void addStudent(string name)
		{
			Student* studentName = new Student(name) ;
			students.push_back(studentName);
		}
		void display()
		{
			cout << "Section "
				 << getSecName()
				 << " ";
			getTime();
			cout << endl;
		}

		void displayGrades()
		{
			for(size_t i= 0; i < students.size(); ++i)
			{
				students[i]->displayStudentInfo();
			}
		}

		void reset()
		{
			students.clear();
			/*for(size_t i = 0; i < students.size(); ++i)
			{
			}*/
		}
		
	private:
		vector<Student*> students;
		const string secName;
		TimeSlot time;
};


class LabWorker 
{
	public:
		LabWorker(const string& name) : name(name) {}
		void addSection( Section& section )
		{
			sectionName = &section;
		}

		void addGrade(const string& name, int grade, int week)
		{
			sectionName->addStudent( name );
			//studentGrade->addStudentGrades( grade, week );

		}
		void displayGrades() 
		{
			sectionName->displayGrades();
		}

	private:
		string name;
		Section* sectionName;
		Student* studentGrade;
};


int main() {

   // lab workers
   LabWorker moe( "Moe" );
   LabWorker jane( "Jane" );
   
   // sections and setup and testing
   Section secA2( "A2", "Tuesday", 16 );
   //secA2.loadStudentsFromFile( "A2.txt" );
   secA2.addStudent("John");
   secA2.addStudent("George");
   secA2.addStudent("Paul");
   secA2.addStudent("Ringo");
   cout << "\ntest A2\n";    // here the modeler-programmer checks that load worked   secA2.display();          // YOU'll DO THIS LATER AS: cout << secA2 << endl;
   moe.addSection( secA2 );
   moe.displayGrades();       // here the modeler-programmer checks that adding the Section worked  
   Section secB3( "B3", "Thursday", 11 );
   //secB3.loadStudentsFromFile( "B3.txt" );
   secB3.addStudent("Thorin");
   secB3.addStudent("Dwalin");
   secB3.addStudent("Balin");
   secB3.addStudent("Kili");
   secB3.addStudent("Fili");
   secB3.addStudent("Dori");
   secB3.addStudent("Nori");
   secB3.addStudent("Ori");
   secB3.addStudent("Oin");
   secB3.addStudent("Gloin");
   secB3.addStudent("Bifur");
   secB3.addStudent("Bofur");
   secB3.addStudent("Bombur");

   cout << "\ntest B3\n";    
   secB3.display();            
   jane.addSection( secB3 );
   jane.displayGrades();     


   

     
   cout << "\nModeling week: 1\n";
   moe.addGrade( "John", 7, 1 );  
   moe.addGrade( "Paul", 9, 1 );  
   moe.addGrade( "George", 7, 1 );  
   moe.addGrade( "Ringo", 7, 1 );  
   cout << "End of week one\n";
   moe.displayGrades();

   
   cout << "\nModeling week: 2\n";
   moe.addGrade( "John", 5, 2 );  
   moe.addGrade( "Paul", 10, 2 );  
   moe.addGrade( "Ringo", 0, 2 );  
   cout << "End of week two\n";
   moe.displayGrades();

   
   cout << "\ntesting reset()\n";   
   secA2.reset();   
   secA2.display();
   moe.displayGrades();
   system("PAUSE");
} 
