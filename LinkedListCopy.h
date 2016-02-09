#ifndef LINKEDLISTCOPY_H
#define LINKEDLISTCOPY_H
#include <iostream>
#include "NodeCopy.h"
using namespace std;
template<typename T,typename P>
class LinkedListCopy{
public:

	int size;
	nodeCopy<T,P>* list_head;
	nodeCopy<T,P>* list_tail;
	LinkedListCopy();
	~LinkedListCopy();
	void insertBack(T);
	void insertFront(T);
	nodeCopy<T,P>* removeFront();
	T removeBack();
	T remove(T);
	bool search(T);
};

template<typename T,typename P>
LinkedListCopy<T,P>::LinkedListCopy(){
	size = 0;
	list_head = NULL;
	list_tail = NULL;
}

template<typename T,typename P>
LinkedListCopy<T,P>::~LinkedListCopy(){
	nodeCopy<T,P>* temp;
	while(size != 0){
		temp = list_head;
		if (size == 1)
		{
			delete temp;
			list_head =NULL;
			list_tail = NULL;
			size--;
		}else{

			temp = list_head;
			list_head->next->prev = 0;
			list_head = list_head->next; //this was list_head->prev, should be list_head->next
			delete temp;
			size--;
		}
	}
} 

template<typename T,typename P>
void LinkedListCopy<T,P>::insertBack(T data){
	nodeCopy<T,P>* newNodeCopy = new nodeCopy<T,P>(data);
	if (size == 0)
	{
		list_head = newNodeCopy;
		list_tail = newNodeCopy;
	}
	else {
		list_tail->next = newNodeCopy;
		newNodeCopy->prev = list_tail;
		list_tail = newNodeCopy;
	}
	size++;
}
template<typename T,typename P>
void LinkedListCopy<T,P>::insertFront(T data){
	nodeCopy<T,P>* newNodeCopy = new nodeCopy<T,P>(data);
	if (size == 0)
	{
		list_head = newNodeCopy;
		list_tail = newNodeCopy;
	}else if(size == 5){
		removeBack();
		list_head->prev = newNodeCopy;
		newNodeCopy->next = list_head;
		list_head = newNodeCopy;
	}
	else{
		list_head->prev = newNodeCopy;
		newNodeCopy->next = list_head;
		list_head = newNodeCopy;
	}
	size++;
}
template<typename T,typename P>
nodeCopy<T,P>* LinkedListCopy<T,P>::removeFront(){
	T returnVal = list_head->data;
	nodeCopy<T,P>* temp = list_head;
	if (size == 1)
	{
		list_head = NULL;
		list_tail = NULL;
	}else{
		list_head->next->prev = NULL;
		list_head = list_head->next;

	}
	size--;
	return temp;
}
template<typename T,typename P>
T LinkedListCopy<T,P>::removeBack(){
	T returnVal = list_tail->data;
	nodeCopy<T,P>* temp = list_tail;
	if (size == 1)
	{
		list_tail = NULL;
		list_head = NULL;
	}else {
		list_tail = list_tail->prev;
		list_tail->next = 0;
	}
	delete temp;
	size--;
	return returnVal;
}
template<typename T,typename P>
T LinkedListCopy<T,P>::remove(T d){
	
	nodeCopy<T,P>* current = list_head;
	while(current->data != d){
		current = current->next;
		if (current == NULL)
		{
			return -1;
		}
	}
	if (current == list_head)
	{
		list_head = current->next;
	}else{
		current->prev->next = current->next;
	}
	if (current == list_tail)
	{
		list_tail = current->prev;
	}else{
		current->next->prev = current->prev;
	}
	current->next = NULL;
	current->prev = NULL;
	T data = current->data;
	delete current;
	size--;
	return data;
}

template<typename T,typename P>
bool LinkedListCopy<T,P>::search(T dataSearch){
	bool condition = false;
	nodeCopy<T,P>* temp = list_head;
	if (dataSearch == temp->data)
	{
		list_head = list_head->next;
		
	}
	else{
		while(temp->next != 0 && temp->next->data != dataSearch){
			temp = temp->next;
			if (temp->next!=0 && temp->next->data == dataSearch)
			{
				condition = true;
			}
		}
	}
	return condition;
}

#endif