#include "HashTable.h"

HashTable::HashTable(int size, int(*hashFunction)(string,int),int prime, string hashWord)
{
	
	m_hashs.resize(prime);
	for (unsigned int i = 0; i < m_hashs.size(); i++) {
		m_hashs[i] = "null";
	}
	//createPrimes(size);
	int hashValue = (*hashFunction)(hashWord,prime);
	bool secondValue = true;
	int counter = 0;
	while (m_hashs[hashValue] != "null" && counter< m_hashs.size()) {
		m_collusions++;
		int stopValue = m_hashs.size()-1;
		if (hashValue == stopValue) {
			hashValue = 0;
		}
		else {
			hashValue++;
		}
		counter++;
	}
}

HashTable::HashTable(int size, int(*hashFunction)(string, int, int), int prime, string hashWord, int base)
{
	m_collusions = 0;
	m_hashs.resize(prime);
	//createPrimes(size);
	int hashValue = (*hashFunction)(hashWord, prime,base);
	bool secondValue = true;
	while (m_hashs[hashValue].length() > 0 && secondValue) {
		m_collusions++;
		int stopValue = m_hashs.size() - 1;
		if (hashValue == stopValue && !secondValue) {
			hashValue = 0;
		}
		else {
			hashValue++;
		}
	}
}

HashTable::HashTable()
{
	createPrimes(100);
}

void HashTable::insert(string stringValue)
{
	for (unsigned int i = 0; i < m_hashs.size(); i++) {
		if (m_hashs[i].length()==0) {
			m_hashs[i] == stringValue;
		}
	}
}

int HashTable::getNumberOfCollisions()
{
	return m_collusions;
}



int HashTable::createPrimes(int n)
{
	if (2 < n) {
		cout << "Bucket sizes : ";
	}
	for (int i = 2; i<n; i++)
		for (int j = 2; j<i; j++)
		{
			if (i % j == 0)
				break;
			else if (i == j + 1)
				cout << i << ", ";
			m_primes.push_back(i);
		}

	return 0;
}
