#ifndef NODE_H
#define NODE_H
#include <iostream>
using namespace std;
template<typename T>
class node{
public:
	T data;
	node(T);
	~node();
	node* next;
	node* prev;
};
template<typename T>
node<T>::node(T dataPassed){
	data = dataPassed;
	next = 0;
	prev = 0;
}
template<typename T>
node<T>::~node(){

	next = 0;
	prev = 0;
}

#endif
