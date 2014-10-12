/*

rec08.cpp
Project:      main.cpp
Name:         Kostaq Papa
ID:           0412768
Semester:     Spring 2011
Course:       CS 1124
Lab Section:  CS 1124LAB - B2


*/



#include "Registrar.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void processFile()
{
	BrooklynPoly::Registrar reg;
	ifstream ifs;
	string myFile, myLine, student, course;

	cout << "Please type in the file name: ";
	cin >> myFile;
	ifs.open( myFile.c_str() );

	while( !ifs )
	{
		cout << "ERROR! ";
		cout << "Please type your file name again: ";
		ifs.clear();
		cin >> myFile;
		ifs.open( myFile.c_str() );
	}

	while( getline( ifs, myLine ) )
	{
		istringstream iss ( myLine, istringstream::in );
		string string1, string2, string3;

		iss >> string1 >> string2 >> string3;
		if( string1 == "AddCourse" )
		{
			if( string2 != "" )
				reg.addCourse( string2 );
		}
		
		else if( string1 == "AddStudent" )
		{
			if( string2 != "" )
				reg.addStudent( string2 );
		}

		else if( string1 == "EnrollStudentInCourse" )
		{
			if( string2 != "" )
			{
				if( string3 != "" )
					reg.enrollStudentInCourse( string2, string3 );
				else 
					cout << "Course not specified." << endl;
			}
			else 
				cout << "Student not specified." << endl;
		}

		else if( string1 == "CancelCourse" )
		{
			if( string2 != "" )
				reg.cancelCourse( string2 );
			else 
				cout << "No course to cancel specified!" << endl;
		}

		else if( string1 == "ChangeStudentName" )
		{
			if( string2 != "" )
			{
				if( string3 != "" )
				{
					reg.changeStudentName( string2, string3 );
					1 == 1;
				}
				else cout << "New name not specified" << endl;
			}
			else 
				cout << "Student to change name not specified." << endl;
		}	

		else if( string1 == "DropStudentFromCourse" )
		{
			if( string2 != "" )
			{
				if( string3 != "" )
					reg.dropStudentFromCourse( string2, string3 );
				else cout << "Course to drop not specified.";
			}
			else 
				cout << "Student to drop not specified.";
		}

		else if( string1 == "RemoveStudent" )
		{
			if( string2 != "" )
				reg.removeStudent( string2 );
			else 
				cout << "Student to be removed not entered.";
		}

		else if( string1 == "PrintReport" )
			reg.printReport();

		else if( string1 == "Purge" )
			reg.purge();
	}
}

int main() 
{
	processFile();

	/*BrooklynPoly::Registrar r;

   // PrintReport
   r.printReport();
     
   // AddCourse CS101.001
   r.addCourse("CS101.001");

   // PrintReport
   r.printReport();

   // AddStudent FritzTheCat
   r.addStudent("FritzTheCat");

   // PrintReport
   r.printReport();

   // AddCourse CS102.001
   r.addCourse("CS102.001");

   // PrintReport
   r.printReport();

   // EnrollStudentInCourse FritzTheCat CS102.001
   r.enrollStudentInCourse("FritzTheCat", "CS102.001");

   // PrintReport
   r.printReport();

   // EnrollStudentInCourse Bullwinkle CS101.001
   r.enrollStudentInCourse("Bullwinkle", "CS101.001");

   // PrintReport
   r.printReport();

   // CancelCourse CS102.001
   r.cancelCourse("CS102.001");

   // PrintReport
   r.printReport();

   // EnrollStudentInCourse FritzTheCat
   // This is an invalid transaction, 
   // because it needs a student name and a course identifier
   // but it only has the student name.
   // No function call.

   // ChangeStudentName FritzTheCat MightyMouse
   r.changeStudentName("FritzTheCat", "MightyMouse");

   // PrintReport
   r.printReport();

   // DropStudentFromCourse MightyMouse CS101.001
   r.dropStudentFromCourse("MightyMouse", "CS101.001");

   // PrintReport
   r.printReport();

   // RemoveStudent FritzTheCat
   r.removeStudent("FritzTheCat");

   // PrintReport
   r.printReport();

   // Purge
   r.purge();

   // PrintReport
   r.printReport();*/


   
}
