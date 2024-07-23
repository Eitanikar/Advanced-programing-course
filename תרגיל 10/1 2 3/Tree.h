#pragma once
#include<iostream>
#include <vector>

// Eitan ikar / 213450661 / q 10

using namespace std;
//-----------------------------------
//  class Tree (Binary Trees)
// process nodes in Pre/In/Post  order
//-----------------------------------
template <class T> class Tree
{
protected:
	//--------------------------------------------------------
	//  inner class Node
	//      a single Node from a binary tree
	//--------------------------------------------------------
	class Node
	{
	public:
		Node* left;
		Node* right;
		T value;
		Node(T val)
			: value(val), left(nullptr), right(nullptr) {}
		Node(T val, Node* l, Node* r)
			: value(val), left(l), right(r) {}
	};		//end of Node class

	Node* root;

public:
	Tree() { root = nullptr; }	 // initialize tree
	~Tree();
	bool isEmpty() const;
	void clear() { clear(root); root = nullptr; }
	void preOrder() { preOrder(root); }
	void inOrder() { inOrder(root); }
	void postOrder() { postOrder(root); }

	int leaves() { return leaves(root); }
	int height() { return height(root); }
	void reflect() { reflect(root); }
	int onlyLeftSon() { return onlyLeftSon(root); }

	virtual void process(T val) { cout << val << " "; }
	virtual void add(T val) = 0;
	virtual bool search(T val) = 0;
	virtual void remove(T val) = 0;


private:
	void  clear(Node* current);
	void  preOrder(Node* current);
	void  inOrder(Node* current);
	void  postOrder(Node* current);

	int leaves(Node* current);
	int height(Node* current);
	void reflect(Node* current);
	int onlyLeftSon(Node* current);


};
//----------------------------------------------------------
//  class Tree implementation
//----------------------------------------------------------
template <class T>
Tree<T>::~Tree() // deallocate tree
{
	if (root != nullptr)
		clear(root);
}

template <class T>
void Tree<T>::clear(Node* current)
{
	if (current)
	{    // Release memory associated with children
		if (current->left)
			clear(current->left);
		if (current->right)
			clear(current->right);
		delete current;
	}
}

template <class T>
bool Tree<T>::isEmpty() const
{
	return  root == nullptr;
}

// preOrder processing of tree rooted at current
template <class T>
void Tree<T>::preOrder(Node* current)
{    // visit Node, left child, right child
	if (current)
	{   // process current Node
		process(current->value);
		// then visit children
		preOrder(current->left);
		preOrder(current->right);
	}
}

// inOrder processing of tree rooted at current
template <class T>
void Tree<T>::inOrder(Node* current)
{    // visit left child, Node, right child
	if (current)
	{
		inOrder(current->left);
		process(current->value);
		inOrder(current->right);
	}
}


template<class T>
// postOrder processing of tree rooted at current
inline void Tree<T>::postOrder(Node* current)
{   // visit left child, right child, node
	if (current)
	{
		postOrder(current->left);
		postOrder(current->right);
		process(current->value);
	}

}

template<class T>
inline int Tree<T>::leaves(Node* current)
{
	if (!current)
		return 0;
	if (!current->left && !current->right)
		return 1;
	return leaves(current->left) + leaves(current->right);
}

template<class T>
inline int Tree<T>::height(Node* current)
{
	if (!current)
		return 0;
	return max(height(current->left), height(current->right)) + 1;
}

template<class T>
inline void Tree<T>::reflect(Node* current)
{
	Node* tamp = nullptr;
	if (current)
	{
		tamp = current->left, current->left = current->right, current->right = tamp;
		reflect(current->left);
		reflect(current->right);
	}
}

template<class T>
inline int Tree<T>::onlyLeftSon(Node* current)
{
	if (!current)
		return 0;
	if (current->left && !current->right)
		return onlyLeftSon(current->left) + 1;
	return onlyLeftSon(current->left) + onlyLeftSon(current->right);
}