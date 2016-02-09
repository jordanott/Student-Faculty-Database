#ifndef TREENODE_H
#define TREENODE_H

using namespace std;

template <typename T>
class TreeNode {

	public:
		T data;
		TreeNode<T>* left;
		TreeNode<T>* right;
		TreeNode();
		TreeNode(T d);
		~TreeNode();
};

template <typename T>
TreeNode<T>::TreeNode() {}

template <typename T>
TreeNode<T>::TreeNode(T d) {
	data = d;
	left = NULL;
	right = NULL;
}

template <typename T>
TreeNode<T>::~TreeNode() {
	delete left;
	delete right;
	left = NULL;
	right = NULL;
}

#endif