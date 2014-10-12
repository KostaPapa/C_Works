/*

rec08.cpp
Project:      Course.cpp
Name:         Kostaq Papa
ID:           0412768
Semester:     Spring 2011
Course:       CS 1124
Lab Section:  CS 1124LAB - B2


*/




#include "Course.h"
#include <iostream>
#include <string>

using namespace BrooklynPoly;

Course::Course(std::string name):name(name){}

std::string Course::getName()
{
	return name;
}

void Course::addStudent( Student* student )
{
	bool foundStudent = false;
	
	for( unsigned i = 0; i < students.size(); ++i )
	{
		if( students[i] == student )
		{
			foundStudent = true;
			break;
		}
	}

	if( !foundStudent )
		students.push_back( student );
}

void Course::dropStudent( Student* student )
{
	for( unsigned i = 0; i < students.size(); ++i )
	{
		if( students[i] == student )
		{
			students[i] = students[students.size()-1];
			students.pop_back();
		}
	}
}

void Course::printReport() const
{
	std::cout << name << ":" << std::endl;
	std::cout << "Students in this course: " << std::endl;

	for( unsigned i = 0; i < students.size(); ++i )
		students[i]->printReport();
}
