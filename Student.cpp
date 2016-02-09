#include "Student.h"
#include <string>
#include <iostream>
#include <typeinfo>
#include <fstream>
using namespace std;
Student::Student(){}
Student::Student(int id){
	ID = id;
}
Student::Student(Student& other){
	ID = other.ID;
	name = other.name;
	level = other.level;
	major = other.major;
	GPA = other.GPA;
	advisorID = other.advisorID;
	
}
Student::Student(int sID, string sName, string sLevel, string sMajor, double sGPA,int sAdvisorID){
	ID = sID;
	name = sName;
	level = sLevel;
	major = sMajor;
	GPA = sGPA;
	advisorID = sAdvisorID;
}
Student::~Student(){
}
bool Student::operator==(Student& other){
	if (ID == other.ID)
	{
		return true;
	}else{
		return false;
	}
}
bool Student::operator>(Student& other){
	if (ID > other.ID)
	{
		return true;
	}
	else{
		return false;
	}
}
bool Student::operator<(Student& other){
	if (ID < other.ID)
	{
		return true;
	}
	else{
		return false;
	}
}
void Student::operator=(Student& other){
	ID = other.ID;
	name = other.name;
	level = other.level;
	major = other.major;
	GPA = other.GPA;
	advisorID = other.advisorID;
}

ostream& operator<<(ostream& os, Student& other)
{
	if (typeid(os) == typeid(ofstream) )
	{
		os << other.ID << endl;
	    os << other.name << endl;
	    os << other.level << endl;
	    os << other.major << endl;
	    os << other.GPA << endl;
	    os << other.advisorID << endl;
	}else{
		os <<"Student ID: " << other.ID << endl;
		os <<"Student Name: " << other.name << endl;
		os <<"Student Level: " << other.level << endl;
		os <<"Student Major: " << other.major << endl;
		os <<"Student GPA: " << other.GPA << endl;
		os <<"Advisor ID: " << other.advisorID << endl;
	}
    
    return os;
}