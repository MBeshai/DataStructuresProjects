#include "HashLibrary.h"

HashLibrary::HashLibrary(int min, int max, string filename)
{
	

	createPrimes(min,max);
	readFile(filename);
	m_hashs.resize(m_primes.back());
	
}



vector<string> HashLibrary::getWords() {
	return m_words;
}
vector<int> HashLibrary::getPrimes()
{
	return m_primes;
}
 int HashLibrary::lengthHash(string hashs, int prime)
{
	

	int length = hashs.size();
	int hashValue = length % prime;
	
	return hashValue;
}
 
 int HashLibrary::sumHash(string hashs, int prime)
{
	

	int sumHash = 0;
	for (unsigned int i = 0; i < hashs.size(); i++) {
		sumHash += int(hashs[i]);
	}
	
	int hashValue = sumHash % prime;
	return hashValue;
}

 
int HashLibrary::sumProdHash(string hashs,int prime)
{

	int sumProd = 0;
	int size = hashs.size();
	for (int i = 0; i <size; i++) {
		sumProd = int(hashs[i])*(i + 1);
	}
	int hashValue = sumProd % prime;

	return hashValue;
}

int HashLibrary::polynomialHash(string hashs, int prime,int base)
{


	int polyH = 0;
	for (unsigned int i = 0; i < hashs.size(); i++) {
		polyH += int(hashs[i])*pow(base, i);
	}
	
	int hashValue = polyH % prime;
	
	return hashValue;

	return 0;
}




int HashLibrary::createPrimes(int min, int max)
{
	cout << "Bucket sizes : ";
	if (2 < max) {
		
	}
	for (int i = min; i<max; i++)
		for (int j = 2; j<i; j++)
		{
			if (i % j == 0)
				break;
			else if (i == j + 1)
				cout << ", " <<i ;
			m_primes.push_back(i);
		}
	cout << endl;
	return 0;
}


bool HashLibrary::readFile(string filename)
{

	bool isOpen = false;
	ifstream myfile(filename.c_str());
	string line;

	if (myfile.is_open())
	{
		isOpen = true;
		string word;
		while (getline(myfile, line))
		{
			for (unsigned int i = 0; i < line.size(); i++) {
				if (line[i] != ' ') {
					word += line[i];
				}
				else {
					m_words.push_back(word);
					word.clear();
				}
			}
		}



	}
	if (isOpen)
	{
		cout << "Read " << m_words.size() << " words from" << filename << endl;
	}
	else {
		cout << "Read file" << filename << "failed!!!Terminating." << endl;
		exit(1);
	}
	myfile.close();
	return isOpen;
}