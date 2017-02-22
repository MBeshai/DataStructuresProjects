#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
class HashTable {
public:
	HashTable();
	HashTable(int size, int(*hashFunction)(string,int),int prime,string hashWord);
	HashTable(int size, int(*hashFunction)(string,int,int),int prime, string hashWord, int base);

	
	void insert(string stringValue);
	int getNumberOfCollisions();
	int createPrimes(int n);
private:
	int m_size;
	vector<int> m_primes;
	int m_collusions;
	vector<string>m_words;
	vector<string> m_hashs;
};
#endif