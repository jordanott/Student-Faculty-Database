#ifndef PROGRAM_H
#define PROGRAM_H
#include "BinarySearchTree.h"
#include "Student.h"
#include "Faculty.h"
#include <iostream>
using namespace std;

class Program
{
public:
	Program();
	~Program();
	
	void runProgram();
	void choices();
	int advisorCheck(int facultyID);
	int studentCheck(int studentID);
	void changeStudentAdvisor(int ,int);
	void removeAdvisee(int studentID,int facultyID,int changeID);
	int checkInt(); 
	double checkDouble();
	BST<Student>* masterStudent;
	BST<Faculty>* masterFaculty;
	

};
void deleteNodeWrapper(Student,int,int,Program*);
void insertWrapper(Student student,int studentID, int facultyID,Program* prgPtr);
void changeSAwrapper(Student student,int studentID, int facultyID,Program* prgPtr);
void removeAdviseeWrapper(Student student,int studentID, int facultyID,Program* prgPtr);

void deleteNodeWrapperFaculty(Faculty faculty,int studentID,int facultyID,Program* b);
void insertWrapperFaculty(Faculty faculty,int studentID,int facultyID,Program* b);
#endif