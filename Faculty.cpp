#include "Faculty.h"
#include <iostream>
#include <string>
#include <typeinfo>
#include <fstream>
#include "Node.h"
using namespace std;
Faculty::Faculty(){

}
Faculty::Faculty(int id){
	ID = id;
	advisees = NULL;
}
Faculty::Faculty(int fID, string fName, string fLevel, string fDept){
	ID = fID;
	name = fName;
	level = fLevel;
	dept = fDept;
	advisees = new LinkedList<int>();
}
Faculty::Faculty(Faculty& other){
	ID = other.ID;
	name = other.name;
	level = other.level;
	dept = other.dept;
	advisees = other.advisees;
	other.advisees = NULL;
}
bool Faculty::operator>(const Faculty& other){
	if (ID > other.ID)
	{
		return true;
	}
	else{
		return false;
	}
}
bool Faculty::operator<(const Faculty& other){
	if (ID < other.ID)
	{
		return true;
	}
	else{
		return false;
	}
}
void Faculty::operator=(Faculty& other){
	ID = other.ID;
	name = other.name;
	level = other.level;
	dept = other.dept;
	advisees = other.advisees;
	other.advisees = NULL;
}
ostream& operator<<(ostream& os, Faculty& other)
{
	if (typeid(os) == typeid(ofstream) )
	{
		os << other.ID << endl;
		os << other.name << endl;
		os << other.level << endl;
		os << other.dept << endl;
		if (other.advisees != NULL)
		{
			node<int>* temp = other.advisees->list_head;
			while(temp != NULL){
				os << temp->data << endl;
				
				temp = temp->next;
			}
			temp = NULL;
		}
		os << "***" << endl;

	}else{
		os << endl;
		os <<"Faculty ID: " << other.ID << endl;
		os <<"Faculty name: " << other.name << endl;
		os <<"Faculty level: " << other.level << endl;
		os <<"Faculty department: " << other.dept << endl;
		if (other.advisees != NULL)
		{
			node<int>* temp = other.advisees->list_head;
			while(temp != NULL){
				os << temp->data << ",";
				temp = temp->next;
			}
			temp = NULL;
		}
		os << endl;	
	}
    return os;
}
bool Faculty::operator==(const Faculty& other){
	if (ID == other.ID)
	{
		return true;
	}return false;
}
void Faculty::add(int d){
	advisees->insertFront(d);
}
Faculty::~Faculty(){

	if (advisees != 0)
	{
		delete advisees;
		advisees = NULL;
	}
}