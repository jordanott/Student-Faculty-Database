#ifndef NODECOPY_H
#define NODECOPY_H
#include <iostream>
using namespace std;
template<typename T, typename P>
class nodeCopy{
public:
	T data;
	nodeCopy(T);
	~nodeCopy();
	nodeCopy* next;
	nodeCopy* prev;
	P person;
	int faculty;
	int student;
};
template<typename T, typename P>
nodeCopy<T,P>::nodeCopy(T dataPassed){
	data = dataPassed;
	next = 0;
	prev = 0;
}
template<typename T, typename P>
nodeCopy<T,P>::~nodeCopy(){

	next = 0;
	prev = 0;
}

#endif