#ifndef FACULTY_H
#define FACULTY_H
#include "LinkedList.h"
#include <string>
#include <iostream>
using namespace std;

class Faculty {

	public:
		Faculty(int,string,string,string);
		~Faculty();
		Faculty(int);
		Faculty(Faculty&);
		Faculty();
		bool operator>(const Faculty&);
		bool operator<(const Faculty&);
		void operator=(Faculty&);
		bool operator==(const Faculty&);
		
		void add(int);

		int ID;
		string name;
		string level;
		string dept;
		LinkedList<int>* advisees;
		bool constructor;
	
};
ostream& operator<<(ostream&, Faculty&);
#endif