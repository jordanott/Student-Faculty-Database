#ifndef BST_H
#define BST_H
#include <iostream>
#include <string>
#include "BSTnode.h"
#include <fstream>
#include <typeinfo>
#include "Student.h"
#include "Faculty.h"
#include <exception>
using namespace std;

template <typename T>
class BST {

	public:
		BST();
		~BST();
		int size;
		TreeNode<T>* createLeaf(T d);
		void insert(T d);
		TreeNode<T>* search(T d);
		void printInOrder();
		void printPreOrder();
		void printPostOrder();
		TreeNode<T>* getMin();
		TreeNode<T>* getMax();
		TreeNode<T>* getParent(T d);
		void deleteNode(T d);
		void serializePreOrder(ofstream&);
		void deleteNodeWrapper(T,int,int);
		void insertWrapper(T,int,int);

	private:
		void serializePreOrderPrivate(TreeNode<T>* node,ofstream&);
		TreeNode<T>* root;
		void printInOrderPrivate(TreeNode<T>* node);
		void printPreOrderPrivate(TreeNode<T>* node);
		void printPostOrderPrivate(TreeNode<T>* node);
		void insertPrivate(T d, TreeNode<T>* node);
		TreeNode<T>* searchPrivate(T d, TreeNode<T>* node);
		TreeNode<T>* getMinPrivate(TreeNode<T>* node);
		TreeNode<T>* getMaxPrivate(TreeNode<T>* node);
		TreeNode<T>* getParentPrivate(T d, TreeNode<T>* node);
};

template <typename T>
BST<T>::BST() {
	root = NULL;
	size = 0;
}

template <typename T>
BST<T>::~BST() {
	delete root;
}

template <typename T>
void BST<T>::serializePreOrderPrivate(TreeNode<T>* node,ofstream& writer) 
{	
	if (node != NULL)
	{
		writer << node->data;

		serializePreOrderPrivate(node->left,writer);
		serializePreOrderPrivate(node->right,writer);
	}
}

template <typename T>
void BST<T>::serializePreOrder(ofstream& writer) {
	serializePreOrderPrivate(root,writer);
}

template <typename T>
TreeNode<T>* BST<T>::createLeaf(T d) {
	TreeNode<T>* newNode = new TreeNode<T>(d);
	size++;
	return newNode;
}
template <typename T>
void BST<T>::insertWrapper(T d,int a,int b) {
	insertPrivate(d,root);
}

template <typename T>
void BST<T>::insertPrivate(T d, TreeNode<T>* node) {

	if (root == NULL)
	{
		root = createLeaf(d);
	}
	else if (d < node->data)
	{
		if (node->left != NULL)
		{
			insertPrivate(d, node->left);
		}
		else
		{
			node->left = createLeaf(d);
		}
	}
	else if (d > node->data)
	{
		if (node->right != NULL) 
		{
			insertPrivate(d, node->right);
		}
		else
		{
			node->right = createLeaf(d);
		}
	}
	else
	{
		cout << "Data:"  << " has already been added to the tree" << endl;
	}
}
template <typename T>
void BST<T>::insert(T d) {
	insertPrivate(d, root);

}


template <typename T>
void BST<T>::printInOrderPrivate(TreeNode<T>* node) {
	
	if (root != NULL)
	{
		if (node->left != NULL)
		{
			printInOrderPrivate(node->left);
		}
		cout << node->data << endl;
		if (node->right != NULL)
		{
			printInOrderPrivate(node->right);
		}
	}
	else
	{
		cout << "The tree is empty" << endl;
	}	
}

template <typename T>
void BST<T>::printInOrder() {
	printInOrderPrivate(root);
}

template <typename T>
void BST<T>::printPreOrderPrivate(TreeNode<T>* node) {

	if (node != NULL)
	{
		cout << node->data << endl;
		printPreOrderPrivate(node->left);
		printPreOrderPrivate(node->right);
	}
	else
	{
		cout << "Tree is empty" << endl;
	}
}

template <typename T>
void BST<T>::printPreOrder() {
	printPreOrderPrivate(root);
}

template <typename T>
void BST<T>::printPostOrderPrivate(TreeNode<T>* node) {

	if (node != NULL)
	{
		printPostOrderPrivate(node->left);
		printPostOrderPrivate(node->right);
		cout << node->data << endl;
	}
	else
	{
		cout << "Tree is empty" << endl;
	}
}

template <typename T>
void BST<T>::printPostOrder() {
	printPostOrderPrivate(root);
}

template <typename T>
TreeNode<T>* BST<T>::searchPrivate(T d, TreeNode<T>* node) {
	if (node == NULL)
	{
		return NULL;
	}
	if (node->data == d)
	{
		return node;
	}
	else
	{
		if (d > node->data)
		{
			return searchPrivate(d, node->right);
		}
		else
		{
			return searchPrivate(d, node->left);
		}
	}
}

template <typename T>
TreeNode<T>* BST<T>::search(T d) {
	return searchPrivate(d, root);
}

template <typename T>
TreeNode<T>* BST<T>::getMinPrivate(TreeNode<T>* node) {

	if (root == NULL)
	{
		cout << "The tree is empty" << endl;
		return NULL;
	}
	else
	{
		if (node->left != NULL)
		{
			return getMinPrivate(node->left);
		}
		else
		{
			return node;
		}
	}
}


template <typename T>
TreeNode<T>* BST<T>::getMin() {
	return getMinPrivate(root);
}

template <typename T>
TreeNode<T>* BST<T>::getMaxPrivate(TreeNode<T>* node) {

	if (root == NULL)
	{
		cout << "The tree is empty" << endl;
		return NULL;
	}
	else
	{
		if (node->right != NULL)
		{
			return getMaxPrivate(node->right);
		}
		else
		{
			return node;
		}
	}
}


template <typename T>
TreeNode<T>* BST<T>::getMax() {
	return getMaxPrivate(root);
}

template <typename T>
TreeNode<T>* BST<T>::getParentPrivate(T d, TreeNode<T>* node) {

	if (node->right != NULL && node->right->data == d)	
	{
		return node;
	}
	else if (node->left != NULL && node->left->data == d)
	{
		return node;
	}
	else if (node->data > d)	
	{
		return getParentPrivate(d, node->left);
	}
	else if (node->data < d)
	{
		return getParentPrivate(d, node->right);
	}
}

template <typename T>
TreeNode<T>* BST<T>::getParent(T d) {
	return getParentPrivate(root);
}
template <typename T>
void BST<T>::deleteNodeWrapper(T d,int a, int b){
	deleteNode(d);
}
template <typename T>
void BST<T>::deleteNode(T d) {

	TreeNode<T>* targetNode = searchPrivate(d, root);
	if (targetNode == NULL)
	{
		cout << "Node does not exist." << endl;
	}
	//covers if the target node is the root
	else if (targetNode == root)
	{
		//cout << "one" << endl;
		if (root->left == NULL && root->right == NULL)
		{
			root = NULL;
			delete targetNode;
		}
		else if (root->left == NULL || root->right == NULL)
		{
			//cout << "one.5" << endl;
			if (root->right == NULL)
			{
				//cout << "one.7" << endl;
				root = root->left;
				targetNode->left = NULL;
				//cout << "done" << endl;
			}
			else
			{
				root = root->right;
				targetNode->right = NULL;
			}
			delete targetNode;
			//cout << "done1" << endl;
		}
		else
		{
			//cout << "two" << endl;
			if (root->right->left == NULL)
			{
				//cout << "three1" << endl;
				root->right->left = root->left;
				root = root->right;
				//cout << "four" << endl;
			}
			else
			{
				//cout << "three" << endl;
				TreeNode<T>* targetSuccessor = getMinPrivate(root->right);
				//cout << "successor found" << endl;
				TreeNode<T>* targetSuccessorParent = getParentPrivate(d, targetSuccessor);
				//cout << "successor parent found" << endl;
				if (targetSuccessor->right == NULL)
				{
					targetSuccessor->left = root->left;
					targetSuccessor->right = root->right;
					targetSuccessorParent->left = NULL;
				}
				else
				{
					targetSuccessorParent->left = targetSuccessor->right;
					targetSuccessor->left = root->left;
					targetSuccessor->right = root->right;
				}
				root = targetSuccessor;
			}
			targetNode->left = NULL;
			targetNode->right = NULL;
			delete targetNode;
		}
		size--;
	}
	else {
		TreeNode<T>* parentNode = getParentPrivate(d, root);
		//covers if there are no children (ie: leaf)
		if (targetNode->left == NULL && targetNode->right == NULL)
		{
			if (parentNode->data > targetNode->data)
			{
				parentNode->left = NULL;
			}
			else if (parentNode->data < targetNode->data)
			{
				parentNode->right = NULL;
			}
			delete targetNode;
		}
		//covers if there is one child
		else if (targetNode->right == NULL || targetNode->left == NULL)
		{
			bool temp;
			if (parentNode->data > targetNode->data)
			{
				temp = true;
			}
			else if(parentNode->data < targetNode->data)
			{
				temp = false;
			}
			if (targetNode->right == NULL)
			{
				if (temp)
				{
					parentNode->left = targetNode->left;
				}
				else
				{
					parentNode->right = targetNode->left;
				}
				targetNode->left = NULL;
			}
			else
			{
				if (temp)
				{
					parentNode->left = targetNode->right;
				}
				else
				{
					parentNode->right = targetNode->right;
				}
				targetNode->right = NULL;
			}
			delete targetNode;		
		}
		//covers if there are two children
		else
		{
			if (targetNode->right->left != NULL)
			{
				TreeNode<T>* targetSuccessor = getMinPrivate(targetNode->right);
				TreeNode<T>* targetSuccessorParent = getParentPrivate(d, targetSuccessor);
				if (parentNode->data > targetNode->data)
				{
					parentNode->left = targetSuccessor;
				}
				else
				{
					parentNode->right = targetSuccessor;
				}
				targetSuccessorParent->left = targetSuccessor->right;
				targetSuccessor->left = targetNode->left;
				targetSuccessor->right = targetNode->right;
			}
			else
			{
				if (parentNode->data > targetNode->data)
				{
					parentNode->left = targetNode->right;
				}
				else
				{
					parentNode->right = targetNode->right;
				}
				targetNode->right->left = targetNode->left;
			}
			targetNode->left = NULL;
			targetNode->right = NULL;
			delete targetNode;
		}
		size--;
	}
}

#endif

