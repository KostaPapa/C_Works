#ifndef STUDENT_H

#define STUDENT_H
#include <vector>
#include "Course.h"
#include "Registrar.h"

namespace BrooklynPoly
{
	class Registrar;
	class Course;
	class Student
	{
		public:
			Student( std::string name );
			std::string getName();

			void printReport();
			void changeName( std::string newName );
			void addCourse( Course* c );
			void removeSelf();

		private:
				std::string name;
				std::vector<Course*> courses;		
	};
}

#endif