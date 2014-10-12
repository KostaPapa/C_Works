#ifndef REGISTRAR_H

#define REGISTRAR_H
#include <vector>
#include "Student.h"
#include "Course.h"

namespace BrooklynPoly
{
	class Student;
	class Course;
	class Registrar
	{
		public:
			Registrar();

			void addCourse( std::string course );
			void addStudent( std::string student );
			void printReport() const;
			void enrollStudentInCourse( std::string student, std::string course );
			void cancelCourse( std::string course );
			void changeStudentName( std::string currentName, std::string newName );
			void dropStudentFromCourse( std::string student, std::string course );
			void removeStudent( std::string name );
			void purge();

		private:
			std::vector<Student*> students;
			std::vector<Course*> courses;
	};
}

#endif