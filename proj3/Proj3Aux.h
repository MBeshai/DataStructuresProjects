#ifndef PROJ3AUX_H
#define PROJ3AUX_H

#include <fstream>
#include <iostream>
template <class Comparable>
class AugmentedBinarySearchTree;

template <class Comparable>
class BinarySearchTree;

#include "BinarySearchTree.h"
#include "AugmentedBinarySearchTree.h"

#include <stdlib.h> 
using namespace std;

class Proj3Aux {

public:
	Proj3Aux();
	~Proj3Aux();

	void DoPrintCommand(string command, int depth);
	int DoRemoveCommand(string command, int element);
	int GetMedanCommand(string command);
	int GetNthElementCommand(string command, int nthElement);
	int GetRankCommand(string command,int element);
	bool isComplete(string command);
	bool isPerfect(string command);
	int GetResidualsCommand(string command);
	int ReadFromCommandFile(char* commandFile);
	int ReadFromInputFile(char* inputFile);

private:

	AugmentedBinarySearchTree<int> m_tree;

	ifstream infile;

};



#endif

