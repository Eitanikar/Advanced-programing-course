#pragma once
#include "Tree.h"
template <class T>
class SearchTree : public Tree<T>
{
public:
	// protocol for search trees
	void add(T value);
	bool  search(T value)
	{
		return search(Tree<T>::root, value);
	}
	void remove(T value) { remove(Tree<T>::root, value); }
	int level(T value) { return level(Tree<T>::root, value); }

private:
	void add(typename Tree<T>::Node* current, T val);
	bool  search(typename Tree<T>::Node* current, T val);

	void remove(typename Tree<T>::Node* &current, T value);
	int level(typename Tree<T>::Node* current, T value);
};

//___________________________________________________________________________________



template <class T>
void SearchTree<T>::add(T val)
{
	// add value to binary search tree 
	if (!Tree<T>::root)
	{
		Tree<T>::root = new typename Tree<T>::Node(val);
		return;
	}
	add(Tree<T>::root, val);
}

template <class T>
bool SearchTree<T>::
search(typename Tree<T>::Node* current, T val)
{
	// see if argument value occurs in tree
	if (!current)
		return false;	// not found
	if (current->value == val)
		return true;
	if (current->value < val)
		return search(current->right, val);
	else
		return search(current->left, val);
}



template <class T>
void SearchTree<T>::add(typename Tree<T>::Node* current, T val)
{
	if (current->value <= val)
		// add to right subtree
		if (!current->right)
		{
			current->right = new typename Tree<T>::Node(val);
			return;
		}
		else add(current->right, val);
	else
		// add to left subtree
		if (!current->left)
		{
			current->left = new typename Tree<T>::Node(val);
			return;
		}
		else add(current->left, val);
}

template<class T>
inline void SearchTree<T>::remove(typename Tree<T>::Node*& current, T val)
{
	if (!current)//Empty
		return;
	if (current->value == val)//Found the value
	{
		if (current->left == nullptr && current->right == nullptr)//A case of deleting a leaf
		{
			delete current;
			current = nullptr;
			return;
		}
		if (current->left == nullptr && current->right != nullptr)//There is a right-handed son and there is no left-handed son
		{
			typename Tree<T>::Node* tamp = current;
			current = current->right;
			delete tamp;
			tamp = nullptr;
			return;
		}
		if (current->left != nullptr && current->right == nullptr)//There is a left - handed son and there is no right - handed son
		{
			typename Tree<T>::Node* tamp = current;
			current = current->left;
			delete tamp;
			tamp = nullptr;
			return;
		}
		if (current->left != nullptr && current->right != nullptr)//There are two sons
		{
			if (current->right->left == nullptr)//The right son has no left son
			{
				typename Tree<T>::Node* tamp = current;
				current->right->left = current->left;
				current = current->right;
				delete tamp; tamp = nullptr;
				return;
			}
			else//The right son has a left son
			{
				typename Tree<T>::Node* tamp = current->right->left;
				while (tamp->left != nullptr)
					tamp = tamp->left;

				current->value = tamp->value;
				remove(current->right, current->value);
			}
	    }
	}
	if (current->value < val)
		return remove(current->right, val);//go right
	else
		return remove(current->left, val);//go left
}

template<class T>
inline int SearchTree<T>::level(typename Tree<T>::Node* current, T value)
{
	if (search(current, value))
	{
		if (current->value == value)
			return 0;
		if (current->value < value)
			return level(current->right, value) + 1;//go right
		if (current->value > value)
			return level(current->left, value) + 1;//go left
	}
	return -1;
}








