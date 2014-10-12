/*

rec08.cpp
Project:      Registrar.cpp
Name:         Kostaq Papa
ID:           0412768
Semester:     Spring 2011
Course:       CS 1124
Lab Section:  CS 1124LAB - B2


*/

#include "Registrar.h"
#include <string>
#include <iostream>

using namespace BrooklynPoly;

Registrar::Registrar(){}

void Registrar::addCourse( std::string course )
{
	bool courseFound = false;

	for( unsigned i = 0; i < courses.size(); ++i )
	{
		if( courses[i]->getName() == course )
		{
			courseFound = true;
			std::cout << course << " already exists" << std::endl;
			break;
		}
	}

	if( !courseFound )
	{
		courses.push_back( new Course( course ) );
		std::cout << course << " added to registrar" << std::endl;
	}
}
void Registrar::addStudent( std::string student )
{
	students.push_back( new Student( student ) );
	std::cout << student << " added to registrar" << std::endl;
}

void Registrar::printReport() const
{
	std::cout << "All courses: " << std::endl; 
	
	for( unsigned i = 0; i < courses.size(); ++i )
	{
		courses[i]->printReport();
	}
}

void Registrar::enrollStudentInCourse( std::string student, std::string course )
{
	Student* foundStudent = NULL;
	Course* foundCourse = NULL;
	bool courseFound = false;

	for( unsigned i = 0; i < students.size(); ++i )
	{
		if( students[i]->getName() == student )
			foundStudent = students[i];
	}

	for( unsigned j = 0; j < courses.size(); ++j )
	{
		if( courses[j]->getName() == course )
			foundCourse = courses[j];
	}

	if( foundCourse )
	{	
		if( foundStudent )
		{
			foundStudent->addCourse( foundCourse );
			foundCourse->addStudent( foundStudent );
			std::cout << student << " added to " << course << std::endl;
		}
	}
	else 
		std::cout << "This course was not found in this school." << std::endl;
	
	if( !foundStudent )
		std::cout << student << " is not in this school." << std::endl;	
}

void Registrar::cancelCourse( std::string course )
{
	bool foundCourse = false;

	for( unsigned i = 0; i < courses.size(); ++i )
	{
		if(courses[i]->getName() == course)
		{
			foundCourse = true;

			if( courses.size()-1 > i )
			{
				courses[i] = courses[course.size()-1];
				delete(courses[courses.size()-1]);
				courses.pop_back();
			}

			else 
			{
				delete( courses[i] );
				courses.pop_back();
			}

			std::cout << course << " cancelled" << std::endl;
			break;
		}
	}
	if( !foundCourse )
			std::cout << "Course to cancel not found" << std::endl;
}

void Registrar::changeStudentName( std::string currentName, std::string newName )
{
	
	for( unsigned i = 0; i < students.size(); ++i )
	{
		if( students[i]->getName() == currentName )
		{
			std::cout << students[i]->getName() << " changed name to ";
			students[i]->changeName( newName );
			std::cout << students[i]->getName() << std::endl;
			break;
		}
	}
}

void Registrar::dropStudentFromCourse( std::string student, std::string course )
{	
	for( unsigned i = 0; i < students.size(); ++i )
	{
		if( students[i]->getName() == student )
		{
			for( unsigned j = 0; j < courses.size(); ++j )
			{
				if( courses[j]->getName() == course )
				courses[j]->dropStudent( students[i] );
			}
		}
	}
}

void Registrar::removeStudent( std::string name )
{
	for( unsigned i = 0; i < students.size(); ++i )
	{
		if( students[i]->getName() == name )
		{
			students[i] = students[students.size()-1];
			students.pop_back();
			break;
		}
	}
}

void Registrar::purge()
{
	std::cout << "Registrar being purged." << std::endl;
	
	for( unsigned i = 0; i < students.size(); ++i )
		delete( students[i] );
	
	for( unsigned j = 0; j < courses.size(); ++j )
		delete( courses[j] );
	
	students.clear();
	courses.clear();
}
