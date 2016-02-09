#ifndef STUDENT_H
#define STUDENT_H
#include <string>
using namespace std;

class Student {

	public:
		Student();
		Student(int,string,string,string,double,int);
		Student(int);
		Student(Student&);
		~Student();
		bool operator>(Student&);
		bool operator<(Student&);
		void operator=(Student&);
		bool operator==(Student&);
		int ID;
		string name;
		string level;
		string major;
		double GPA;
		int advisorID;	
};
ostream& operator<<(ostream& cout, Student& other);
//ofstream& operator<<(ofstream& os, Student& other);

#endif