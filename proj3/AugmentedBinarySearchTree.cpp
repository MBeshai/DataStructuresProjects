#ifndef AUGMENTEDBINARYSEARCHTREE_C
#define AUGMENTEDBINARYSEARCHTREE_C


#include "AugmentedBinarySearchTree.h"
#include <iostream>
//using namespace std;


/**
* Construct the tree.
*/
template <class Comparable>
AugmentedBinarySearchTree<Comparable>::AugmentedBinarySearchTree() :
	root(NULL)
{
	//no code
}


/**
* Copy constructor.
*/
template <class Comparable>
AugmentedBinarySearchTree<Comparable>::
AugmentedBinarySearchTree(const AugmentedBinarySearchTree<Comparable> & rhs) :
	root(NULL)
{
	*this = rhs;
}

/**
* Destructor for the tree.
*/
template <class Comparable>
AugmentedBinarySearchTree<Comparable>::~AugmentedBinarySearchTree()
{
	makeEmpty();
}
template<class Comparable>
int AugmentedBinarySearchTree<Comparable>::remove(const Comparable & x)
{
	remove(x, root);
	return 1;
}


template<class Comparable>
bool AugmentedBinarySearchTree<Comparable>::IsPerfect()
{
	//queue < queue <BinaryNode<Comparable> *> q;
	//int size = root->m_size;
	//IsPerfect(q, 0);
	return true;
}



template<class Comparable>
bool AugmentedBinarySearchTree<Comparable>::IsComplete()
{
	IsComplete(root,root->m_size);
	
	return true;
}
template<class Comparable>
void AugmentedBinarySearchTree<Comparable>::PrintLevels(int numlevels)
{
	PrintLevels(root, numlevels);
}
template<class Comparable>
inline void AugmentedBinarySearchTree<Comparable>::makeEmpty()
{

	makeEmpty(root);
}

template<class Comparable>
int AugmentedBinarySearchTree<Comparable>::RemoveResidue()
{
	static int counter;
	if (root == NULL) {
		return;
	}
	if (root->right != NULL && root->left == NULL) {
		counter++;
	}
	
	return counter;
}

template<class Comparable>
const Comparable & AugmentedBinarySearchTree<Comparable>::NthElement(int n)
{
	NthElement(root, NULL, n);
}

template<class Comparable>
int AugmentedBinarySearchTree<Comparable>::Rank(const Comparable & x)
{
	Rank(x, root, 0);
	return 1;
}

template<class Comparable>
const Comparable & AugmentedBinarySearchTree<Comparable>::Median()
{
	ofstream myfile;
	myfile.open("results.txt");

	int n = root->m_size%2;
	int j= (root->m_size-1) % 2;
	if (n== 0) {
	myfile<<"MEDIAN: "<<NthElement(n)<<"\n"<<endl;
	}
	else {
		myfile << "MEDIAN: " << NthElement(j) <<"\n" <<endl;
	}
	myfile.close();
	
}

template<class Comparable>
BinaryNode<Comparable>* AugmentedBinarySearchTree<Comparable>::findMin(BinaryNode<Comparable>* t) const
{
	if (t == NULL)
		return NULL;
	if (t->left == NULL)
		return t;
	return findMin(t->left);
}

template<class Comparable>
BinaryNode<Comparable>* AugmentedBinarySearchTree<Comparable>::NthElement(BinaryNode<Comparable>* t, int * nodesVisited, int n) const
{

	if (t == NULL)
		return root;

	static int counter;
	NthElement(t->right, nodesVisited++,n);
	counter++;
	if (counter== n)
	{
		
		return root;
	}

	NthElement(t->left, nodesVisited++, n);
}

template<class Comparable>
void AugmentedBinarySearchTree<Comparable>::Rank(const Comparable & x, BinaryNode<Comparable>* t, int * nodesVisited) const
{
	ofstream myfile;
	myfile.open("results.txt");
	if (x == t->element) {
		myfile << "RANK : " << nodesVisited + 1 << "\n" << endl;
	}
	Rank(x, t->right, nodesVisited++);
	Rank(x, t->left, nodesVisited++);
	
}
/*
template<class Comparable>
bool AugmentedBinarySearchTree<Comparable>::IsPerfect(queue<BinaryNode<Comparable>*> q, int height)
{
	static int counter=0;
	if (counter<height) {
		if (q.front()->right!=NULL && q.front()->left ==NULL)
			 return false;

	}
	counter++;
	q.pop();
	IsPerfect(q, height);
}
*/

template<class Comparable>
inline void AugmentedBinarySearchTree<Comparable>::makeEmpty(BinaryNode<Comparable>*& t) const
{

	if (t != NULL)
	{
		makeEmpty(t->left);
		makeEmpty(t->right);
		delete t;
	}
	t = NULL;   
}

template<class Comparable>
void AugmentedBinarySearchTree<Comparable>::IsComplete(BinaryNode<Comparable>*& t, int size)
{
	if (root == NULL) {
		ofstream myfile;
		myfile.open("results.txt");
		myfile << "COMPLETE TRUE" << endl;
	}
	if (root != NULL) {
		if (root->right == NULL and root->left != NULL) {
			ofstream myfile;
			myfile.open("results.txt");
			myfile << "COMPLETE FALSE" << endl;
		}
		if (root->right != NULL and root->left == NULL) {
			ofstream myfile;
			myfile.open("results.txt");
			myfile << "COMPLETE FALSE" << endl;
		}
		IsComplete(root->left, root->m_size);
		IsComplete(root->right,root->m_size);
	}
	ofstream myfile;
	myfile.open("results.txt");
	myfile << "COMPLETE TRUE" << endl;
}


template<class Comparable>
inline int AugmentedBinarySearchTree<Comparable>::insert(const Comparable & x)
{
	insert(x, root);
	return 1;
}

template<class Comparable>
int AugmentedBinarySearchTree<Comparable>::insert(const Comparable & x, BinaryNode<Comparable>*& t) const
{
	if (t == NULL) {
		t = new BinaryNode<Comparable>(x, NULL, NULL);
		t->m_size++;
	}
	else if (x < t->element) {
		insert(x, t->left);
	}
	else if (t->element < x) {
		insert(x, t->right);
	}

		
		return 1;
}

template<class Comparable>
int AugmentedBinarySearchTree<Comparable>::remove(const Comparable & x, BinaryNode<Comparable>*& t) const
{

	if (t == NULL)
		return 0;   // Item not found; do nothing
	if (x < t->element)
		remove(x, t->left);
	else if (t->element < x)
		remove(x, t->right);
	else if (t->left != NULL && t->right != NULL) // Two children
	{
		t->element = findMin(t->right)->element;
		remove(t->element, t->right);
	}
	else
	{
		BinaryNode <Comparable> *oldNode = t;
		t = (t->left != NULL) ? t->left : t->right;
		delete oldNode;
	

}
	return 0;
}

template<class Comparable>
void AugmentedBinarySearchTree<Comparable>::PrintLevels(queue<BinaryNode<Comparable>*> q, int levels)
{
	static int count = 0;
	if (q.top() == NULL) {
		return;
	}
	if (count<levels)
	{
	//	PrintLevels(root->left,levels);
		
		cout << "Level: " << count << "(" << q->element << endl;
	//	PrintLevels(toot->right,levels);
	}
	q.pop();
	count++;
}

template<class Comparable>
void AugmentedBinarySearchTree<Comparable>::RemoveResidue(BinaryNode<Comparable>*& t, int * deletions) const
{

	ofstream myfile;
	myfile.open("results.txt");
	
	myfile << "Residuals" << deletions << endl;
}


#endif
