#ifndef HASHLIBRARY_H
#define HASHLIBRARY_H
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <cstdlib> 

#include <math.h> 
using namespace std;

class HashLibrary {

public:
	HashLibrary(int min, int max, string filename);
	int createPrimes(int min,int max);
	static int lengthHash(string hashs,int prime);	static int sumHash(string hashs, int prime);	static int sumProdHash(string hashs, int prime);	static int polynomialHash(string hashs, int prime,int base);	bool readFile(string filename);
	vector<string> getWords();
	vector<int> getPrimes();
private:
	 vector<int> m_primes;
	 vector<string>m_words;
	 vector<string> m_hashs;
};
#endif