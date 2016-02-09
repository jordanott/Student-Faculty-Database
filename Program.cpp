#include "Program.h"
#include "BinarySearchTree.h"
#include <cstdlib>
#include <stdlib.h>
#include <sstream>
#include "LinkedListCopy.h"
using namespace std;
typedef void (*FunctionStudent)(Student,int,int,BST<Student>* );
typedef void (*FunctionFaculty)(Faculty,int,int );
Program::Program(){
	masterStudent = new BST<Student>();
	masterFaculty = new BST<Faculty>();
	ifstream reader("serialization.txt");
	string line;
	int counter = 0;
	int numStudents;
	string studentArray[6];
	string facultyArray[4];
	int index = 0;
	while(getline(reader,line) != NULL){
		if (counter == 0)
		{
			numStudents = atoi(line.c_str());
			numStudents *= 6;
		}
		else if (counter <= numStudents && counter != 0)
		{
			if (index < 6)
			{
				studentArray[index++] = line.c_str();
				if (index == 6)
				{
					Student* newStudent = new Student(atoi(studentArray[0].c_str()),studentArray[1],studentArray[2],studentArray[3],
					atoi(studentArray[4].c_str()),atoi(studentArray[5].c_str()));
					masterStudent->insert(*newStudent);
					delete newStudent;
					index = 0;
				}
			}
			
		}else if(counter > numStudents){
			Faculty* newFaculty;
			//cout << line <<  "   " << index << endl;
			if (index < 4)
			{
				facultyArray[index] = line.c_str();
				if (index == 3)
				{
					newFaculty = new Faculty(atoi(facultyArray[0].c_str()),facultyArray[1],facultyArray[2],facultyArray[3]);
				}	
				index++;
			}
			else if(index == 4){
				if(line == "***"){
					index = 0;
					masterFaculty->insert(*newFaculty);
					delete newFaculty;
				}else{
					newFaculty->add(atoi(line.c_str()));
				}
			}
		}
		counter++;
	}
	reader.close();
}
Program::~Program(){
}

void Program::choices(){
	cout << "1. Print all students and their information (sorted by ascending id #)" << endl;
	cout << "2. Print all faculty and their information (sorted by ascending id #)" << endl;
	cout << "3. Find and display student information given the students id"<< endl;
	cout << "4. Find and display faculty information given the faculty id"<< endl;
	cout << "5. Given a student’s id, print the name and info of their faculty advisor"<< endl;
	cout << "6. Given a faculty id, print ALL the names and info of his/her advisees."<< endl;
	cout << "7. Add a new student"<< endl;
	cout << "8. Delete a student given the id"<< endl;
	cout << "9. Add a new faculty member"<< endl;
	cout << "10. Delete a faculty member given the id."<< endl;
	cout << "11. Change a student’s advisor given the student id and the new faculty id."<< endl;
	cout << "12. Remove an advisee from a faculty member given the ids"<< endl;
	cout << "13. Rollback" << endl;
	cout << "14. Exit" << endl;
}

void Program::runProgram(){
	int choice = 0;
	typedef void (*FunctionStudent)(Student,int,int ,Program*);
	typedef void (*FunctionFaculty)(Faculty,int,int,Program*);
	LinkedList<char>* whichType = new LinkedList<char>();
	LinkedListCopy<FunctionStudent,Student>* StudentFunctionPtr = new LinkedListCopy<FunctionStudent,Student>();
	LinkedListCopy<FunctionFaculty,Faculty>* FacultyFunctionPtr = new LinkedListCopy<FunctionFaculty,Faculty>();
	while(choice != 14){
		choices(); 
		cin >> choice;
		switch(choice){
			case 1:
				masterStudent->printInOrder();
				break;
			case 2:
				masterFaculty->printInOrder();
				break;
			case 3:
			{
				if (masterStudent->size = 0)
				{
					cout << "You must add a student before you can view them." << endl;
				}
				else {
					cout << "Enter student ID you wish to view" << endl;
					int temp_ID;
					temp_ID = checkInt();
					temp_ID = studentCheck(temp_ID);
					Student* temp = new Student(temp_ID);
					cout << masterStudent->search(*temp)->data << endl;
					delete temp;
					temp = NULL;
				}
				break;
			}
			case 4:
			{
				if (masterFaculty->size == 0)
				{
					cout << "You must add a faculty before you can view them." << endl;
				}
				else {
					cout << "Enter Faculty ID you wish to view" << endl;
					int temp_ID;
					temp_ID = checkInt();
					temp_ID = advisorCheck(temp_ID);
					Faculty* temp = new Faculty(temp_ID);
					cout << masterFaculty->search(*temp)->data << endl;
					delete temp;
					temp = NULL;
				}
				break;
			}
			case 5:
			{
				cout << masterStudent->size << endl;
				if (masterStudent->size == 0)
				{
					cout << "You must add a student before you can do this operation." << endl;
				}
				else {
					cout << "Enter student ID you wish to view" << endl;
					int temp_ID;
					temp_ID = checkInt();
					temp_ID = studentCheck(temp_ID);
					Student* temp = new Student(temp_ID);
					Faculty* temp_Faculty = new Faculty(masterStudent->search(*temp)->data.advisorID);
					cout << masterFaculty->search(*temp_Faculty)->data << endl;
					delete temp;
					delete temp_Faculty;
					temp_Faculty = NULL;
					temp = NULL;
				}
				break;
			}
			case 6:
			{
				if (masterFaculty->size == 0)
				{
					cout << "You must add a faculty before you can do this operation." << endl;
				}
				else {
					cout << "Enter Faculty ID you wish to view" << endl;
					int temp_ID;
					temp_ID = checkInt();
					temp_ID = advisorCheck(temp_ID);
					Faculty* temp = new Faculty(temp_ID);
					node<int>* faculty_advisees = masterFaculty->search(*temp)->data.advisees->list_head;
					while(faculty_advisees != NULL){
						temp_ID = faculty_advisees->data;
						Student* temp = new Student(temp_ID);
						cout << masterStudent->search(*temp)->data << endl;
						faculty_advisees = faculty_advisees->next;
						delete temp;
						temp = NULL;
					}
				}
				break;
			}
			case 7:
			{
				if (masterFaculty->size == 0)
				{
					cout << "You must add a faculty before you can add a student." << endl;
				}
				else {
					int id;
					string sname;
					string slevel;
					string smajor;
					double sgpa;
					int sfacultyid;
					cout << "Enter students info: " << endl;
					cout << "ID: ";
					id = checkInt();
					cout << "Name: ";
					cin.ignore(); 
					getline(cin,sname);
					cout << "Level: ";
					cin >> slevel;
					cout << "Major: ";
					cin.ignore(); 
					getline(cin,smajor);
					cout << "GPA: ";
					sgpa = checkDouble();
					cout << "Faculty ID: ";
					sfacultyid = checkInt();
					sfacultyid = advisorCheck(sfacultyid);
					Faculty* searchFaculty = new Faculty(sfacultyid);
					masterFaculty->search(*searchFaculty)->data.add(id);
					Student* newStudent = new Student(id,sname,slevel,smajor,sgpa,sfacultyid);
					masterStudent->insert(*newStudent);

					FunctionStudent x = &deleteNodeWrapper;
					StudentFunctionPtr->insertFront(x);
					StudentFunctionPtr->list_head->person = *newStudent;
					StudentFunctionPtr->list_head->faculty = sfacultyid;
					StudentFunctionPtr->list_head->student = id;
					whichType->insertFront('S');
					delete newStudent;
					newStudent = NULL;
				}
				break;
			}
			case 8:
			{
				if (masterStudent->size == 0)
				{
					cout << "Database does not have any students to delete." << endl;
				}
				else {
					cout << "Enter Student ID you wish to delete" << endl;
					int number;
					number = checkInt();
					number = studentCheck(number);
					Student* deleteStudent = new Student(number);
					Student save = masterStudent->search(*deleteStudent)->data;
					int fac = masterStudent->search(*deleteStudent)->data.advisorID;
					Faculty* changeFac = new Faculty(fac);
					//cout << masterFaculty->search(*changeFac)->data.advisees->list_head->data;
					masterFaculty->search(*changeFac)->data.advisees->remove(number);
					masterStudent->deleteNode(*deleteStudent);
					
					delete changeFac;
					changeFac = NULL;

					FunctionStudent x = &removeAdviseeWrapper;
					StudentFunctionPtr->insertFront(x);
					
					StudentFunctionPtr->list_head->person = save;
					StudentFunctionPtr->list_head->faculty = fac;
					StudentFunctionPtr->list_head->student = number;
					whichType->insertFront('S');
					delete deleteStudent;
					deleteStudent = NULL;
				}
				break;
			}
			case 9:{
				int id;
				string fname;
				string flevel;
				string fdept;
				cout << "Enter faculty member info: " << endl;
				cout << "ID: ";
				id = checkInt();
				cout << "Name: ";
				cin.ignore(); 
				getline(cin,fname);
				cout << "Level: ";
				cin >> flevel;
				cout << "Department: ";
				cin >> fdept;

				Faculty* newFaculty = new Faculty(id,fname,flevel,fdept);
				masterFaculty->insert(*newFaculty);

				FunctionFaculty x = &deleteNodeWrapperFaculty;
				FacultyFunctionPtr->insertFront(x);
				FacultyFunctionPtr->list_head->person = *newFaculty;
				FacultyFunctionPtr->list_head->faculty = 0;
				FacultyFunctionPtr->list_head->student = 0;
				whichType->insertFront('F');
				delete newFaculty;
				newFaculty = NULL;
				break;
			}
			case 10:
			{
				if (masterFaculty->size == 0)
				{
					cout << "Database does not have any faculty to delete." << endl;
				}
				else {
					cout << "Enter Faculty ID you wish to delete" << endl;
					int number;
					number = checkInt();
					number = advisorCheck(number);
					Faculty* deleteFaculty = new Faculty(number);
					node<int>* facultyAdvisees = masterFaculty->search(*deleteFaculty)->data.advisees->list_head;
					while(facultyAdvisees != NULL)
					{
						int stID;
						int fID;
						stID = studentCheck(facultyAdvisees->data);
						cout << "Enter the new faculty id: ";
						fID = checkInt();
						fID = advisorCheck(fID);
						facultyAdvisees = facultyAdvisees->next;
						changeStudentAdvisor(stID, fID);
						
					}
					whichType->insertFront('F');

					FunctionFaculty x = &insertWrapperFaculty;
					FacultyFunctionPtr->insertFront(x);
					FacultyFunctionPtr->list_head->person = masterFaculty->search(*deleteFaculty)->data;
					FacultyFunctionPtr->list_head->faculty = 0;
					FacultyFunctionPtr->list_head->student = 0;

					masterFaculty->deleteNode(*deleteFaculty);
					delete deleteFaculty;
					deleteFaculty = NULL;
				}
				break;
			}
			case 11:
			{
				if (masterFaculty->size == 0 || masterStudent->size == 0)
				{
					cout << "Database does not have enough students or faculty to do this operation" << endl;
				}
				else {
					int stID;
					int fID;
					cout << "Enter the student id: ";
					stID = checkInt();
					stID = studentCheck(stID);
					cout << "Enter the faculty id: ";
					fID = checkInt();
					fID = advisorCheck(fID);

					Student* searchStudent = new Student(stID);
					Student save = masterStudent->search(*searchStudent)->data;
					FunctionStudent x = &changeSAwrapper;
					StudentFunctionPtr->insertFront(x);
					
					StudentFunctionPtr->list_head->person = save;
					StudentFunctionPtr->list_head->faculty = save.advisorID;
					StudentFunctionPtr->list_head->student = save.ID;
					whichType->insertFront('S');
					changeStudentAdvisor(stID, fID);
					delete searchStudent;
				}
				break;
			}
			case 12:
			{
				if (masterFaculty->size == 0 || masterStudent->size == 0)
				{
					cout << "Database does not have enough students or faculty to do this operation" << endl;
				}
				else {
					cout << "Enter the student ID: " ;
					int studentID;
					studentID = checkInt();
					studentID = studentCheck(studentID);
					cout << "Enter the Faculty ID: ";
					int facultyID;
					facultyID = checkInt();
					facultyID = advisorCheck(facultyID);

					Student* searchStudent = new Student(studentID);
					Student save = masterStudent->search(*searchStudent)->data;
					FunctionStudent x = &removeAdviseeWrapper;
					StudentFunctionPtr->insertFront(x);
					StudentFunctionPtr->list_head->person = save;
					StudentFunctionPtr->list_head->faculty = facultyID;
					StudentFunctionPtr->list_head->student = studentID;
					whichType->insertFront('S');
					removeAdvisee(studentID, facultyID,-1);
					delete searchStudent;
				}
				break;
			}
			case 13:
			{
				if (masterFaculty->size == 0 || masterStudent->size == 0)
				{
					cout << "Database does not have enough students or faculty to do this operation" << endl;
				}
				else if (StudentFunctionPtr->size == 0)
				{
					cout << "Can't Rollback anymore." << endl;
				}
				else if (FacultyFunctionPtr->size == 0)
				{
					cout << "Can't Rollback anymore." << endl;
				}
				else if (StudentFunctionPtr->size == 0 && FacultyFunctionPtr->size == 0)
				{
					cout << "Can't Rollback anymore." << endl;
				}
				else {
					if (whichType->removeFront() == 'S')
					{
						nodeCopy<FunctionStudent,Student>* x =  StudentFunctionPtr->removeFront();
						x->data(x->person,x->student,x->faculty,this);
						delete x;
					}else{
						nodeCopy<FunctionFaculty,Faculty>* x =  FacultyFunctionPtr->removeFront();
						x->data(x->person,x->student,x->faculty,this);
						delete x;
					}
				}	
				break;
			}
			case 14:
			{
				ofstream writer("serialization.txt");
				writer << masterStudent->size << endl;
				masterStudent->serializePreOrder(writer);
				masterFaculty->serializePreOrder(writer);
				
				delete masterStudent;
				delete masterFaculty;
				delete FacultyFunctionPtr;
				delete StudentFunctionPtr;
				FacultyFunctionPtr = NULL;
				StudentFunctionPtr = NULL;
				masterStudent = NULL;
				masterFaculty = NULL;
				writer.close();

				break;
			}
		}
	}	
}
int Program::advisorCheck(int facultyID){
	Faculty* searchFaculty = new Faculty(facultyID);
	if (masterFaculty->search(*searchFaculty) == NULL)
	{
		delete searchFaculty;
		searchFaculty = NULL;
		cout << "Not a faculty member. Try again: " << endl;
		facultyID = checkInt();
		advisorCheck(facultyID);
	}else{
		delete searchFaculty;
		searchFaculty = NULL;
		
	}
	return facultyID;
}
int Program::studentCheck(int StudentID){
	Student* searchStudent = new Student(StudentID);
	if (masterStudent->search(*searchStudent) == NULL)
	{
		delete searchStudent;
		searchStudent = NULL;
		cout << "Not a Student member. Try again: " << endl;
		StudentID = checkInt();
		studentCheck(StudentID);
	}else{
		delete searchStudent;
		searchStudent = NULL;
		
	}
	return StudentID;
}
void Program::changeStudentAdvisor( int studentID,int facultyID){
	Student* change = new Student(studentID);
	Faculty* changePrevious = new Faculty(masterStudent->search(*change)->data.advisorID);
	masterFaculty->search(*changePrevious)->data.advisees->remove(studentID);
	masterStudent->search(*change)->data.advisorID = facultyID;
	Faculty* changFac = new Faculty(facultyID);
	masterFaculty->search(*changFac)->data.add(studentID);
	delete change;
	delete changFac;
	delete changePrevious;
	change = NULL;
	changFac = NULL;
	changePrevious = NULL;
}
void Program::removeAdvisee(int studentID, int facultyID,int changeID){
	Student* changeStudent = new Student(studentID);
	masterStudent->search(*changeStudent)->data.advisorID = changeID;
	Faculty* changFac = new Faculty(facultyID);
	masterFaculty->search(*changFac)->data.advisees->remove(studentID);
	delete changFac;
	delete changeStudent;
	changeStudent = NULL;
	changFac = NULL;
}

int Program::checkInt() {
	int temp;
	cin >> temp;
	while (cin.fail()) {
		cout << "Please enter an integer:" << endl;
		cin.clear();
		cin.ignore(256, '\n');
		cin >> temp;
	}
	return temp;
}

double Program::checkDouble() {
	double temp;
	cin >> temp;
	while (cin.fail()) {
		cout << "Please enter a double:" << endl;
		cin.clear();
		cin.ignore(256, '\n');
		cin >> temp;
	}
	return temp;
}
void deleteNodeWrapper(Student student,int c,int s,Program* b){
	b->removeAdvisee(c,s,0);
	b->masterStudent->deleteNode(student);
}
void insertWrapper(Student student,int studentID, int facultyID,Program* prgPtr){
	prgPtr->masterStudent->insert(student);
	
	Faculty* searchFaculty = new Faculty(student.advisorID);
	cout << student.advisorID << endl;
	prgPtr->masterFaculty->search(*searchFaculty)->data.add(student.ID);
	
	delete searchFaculty;
}
void changeSAwrapper(Student student,int studentID, int facultyID,Program* prgPtr){
	prgPtr->changeStudentAdvisor(studentID,facultyID);
}
void removeAdviseeWrapper(Student student,int studentID, int facultyID,Program* prgPtr){
	Faculty* one = new Faculty(facultyID);
	prgPtr->masterStudent->search(student)->data.advisorID = student.advisorID;
	prgPtr->masterFaculty->search(*one)->data.add(studentID);
	
	delete one;
}



// Faculty

void deleteNodeWrapperFaculty(Faculty faculty,int studentID,int facultyID,Program* b){
	b->masterFaculty->deleteNode(faculty);
}

void insertWrapperFaculty(Faculty faculty,int studentID,int facultyID,Program* b){
	delete faculty.advisees;
	faculty.advisees = NULL;
	b->masterFaculty->insert(faculty);
}