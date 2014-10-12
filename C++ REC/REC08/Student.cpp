/*

rec08.cpp
Project:      Student.cpp
Name:         Kostaq Papa
ID:           0412768
Semester:     Spring 2011
Course:       CS 1124
Lab Section:  CS 1124LAB - B2


*/

#include "Student.h"
#include <string>
#include <iostream>

using namespace BrooklynPoly;

Student::Student(std::string name):name(name){}

std::string Student::getName()
{
	return name;
}

void Student::changeName( std::string newName )
{
	name = newName;
}

void Student::printReport()
{
	std::cout << name 
			  << std::endl;
}

void Student::addCourse( Course* c )
{
	bool foundCourse = false;
	
	for( unsigned i = 0; i < courses.size(); ++i )
	{
		if( courses[i] == c )
		{
			foundCourse = true;
			break;
		}
	}

	if( !foundCourse )
	{
		courses.push_back( c );
		std::cout << "Added " << name << " to course " << c->getName() << std::endl;
	}
}

void Student::removeSelf()
{
	for( unsigned i = 0; i < courses.size(); ++i )
	{
		courses[i]->dropStudent( this );
	}
}
