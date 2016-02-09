#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include "Node.h"
using namespace std;

template<typename T>
class LinkedList{
public:
	int size;
	node<T>* list_head;
	node<T>* list_tail;
	LinkedList();
	~LinkedList();
	void insertBack(T);
	void insertFront(T);
	T removeFront();
	T removeBack();
	T remove(T);
	bool search(T);
};

template<typename T>
LinkedList<T>::LinkedList(){
	size = 0;
	list_head = NULL;
	list_tail = NULL;
}

template<typename T>
LinkedList<T>::~LinkedList(){
	node<T>* temp;
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

template<typename T>
void LinkedList<T>::insertBack(T data){
	node<T>* newNode = new node<T>(data);
	if (size == 0)
	{
		list_head = newNode;
		list_tail = newNode;
	}
	else {
		list_tail->next = newNode;
		newNode->prev = list_tail;
		list_tail = newNode;
	}
	size++;
}
template<typename T>
void LinkedList<T>::insertFront(T data){
	node<T>* newNode = new node<T>(data);
	if (size == 0)
	{
		list_head = newNode;
		list_tail = newNode;
	}else{
		list_head->prev = newNode;
		newNode->next = list_head;
		list_head = newNode;
	}
	size++;
}
template<typename T>
T LinkedList<T>::removeFront(){
	T returnVal = list_head->data;
	node<T>* temp = list_head;
	if (size == 1)
	{
		list_head = NULL;
		list_tail = NULL;
	}else{
		list_head->next->prev = NULL;
		list_head = list_head->next;

	}
	delete temp;
	size--;
	return returnVal;
}
template<typename T>
T LinkedList<T>::removeBack(){
	T returnVal = list_tail->data;
	node<T>* temp = list_tail;
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
template<typename T>
T LinkedList<T>::remove(T d){
	
	node<T>* current = list_head;
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

template<typename T>
bool LinkedList<T>::search(T dataSearch){
	bool condition = false;
	node<T>* temp = list_head;
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