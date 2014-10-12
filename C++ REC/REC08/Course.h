#ifndef COURSE_H

#define COURSE_H
#include <vector>
#include "Student.h"

namespace BrooklynPoly
{
	class Student;
	class Course
	{
		public:
			Course( std::string name );
			std::string getName();
			void addStudent( Student* student );
			void dropStudent( Student* student );
			void printReport() const;

		private:
			std::string name;
			std::vector<Student*> students;
	};
}

#endif