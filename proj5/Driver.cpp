#include <iostream>
#include "HashTable.h"
#include "HashLibrary.h"
#include <cstdlib> 
#include <string>
using namespace std;


int main(int argc, char* argv[]) {
	


	if (argc < 3) {
		cout<<"Usage: make run INPUT=<filename> MIN_SIZE=<positive integer>	MAX_SIZE=<positive integer larger than MIN_SIZE>[MIN_BASE = <positiveinteger > MAX_BASE = <positive integer larger than MIN_BASE>]"<<endl;
	}
	
	else if (atoi(argv[1]) < 0 || atoi(argv[2]) < 0 || atoi(argv[2]) < atoi(argv[1])) {
		cout << "Min or Max is negative or min is greater than max." << endl;
	}
	int min = atoi(argv[2]);
	int max = atoi(argv[3]);
	char* filename = argv[1];
	HashLibrary c(min,max,filename);
	
	vector<string> words = c.getWords();
	vector<int> primes = c.getPrimes();
	
	int (*lengthhashPTR)(string,int);
	lengthhashPTR = &HashLibrary::lengthHash;

	int (*sumhashPTR)(string,int);
	sumhashPTR = &HashLibrary::sumHash;

	int(*sumProdhashPTR)(string, int);
	sumProdhashPTR = &HashLibrary::sumProdHash;

	
	
	int lenghtcount=10000, sumcount=10000, sumprodcount=10000;
	int bestPrime1,bestprime2,bestprime3;
	 
	for ( int j = 0; j < primes.size();j++){
		int temp1, temp2, temp3;
		for ( int i = 0; i < words.size(); i++) {
			HashTable lengthHashObject(max, lengthhashPTR, primes[j], words[i]);
			temp1 +=lengthHashObject.getNumberOfCollisions();
			HashTable sumHashObject(max, sumhashPTR, primes[j], words[i]);
			temp2 += sumHashObject.getNumberOfCollisions();
			HashTable sumProdhashObject(max, sumhashPTR, primes[j], words[i]);
			temp3 += sumProdhashObject.getNumberOfCollisions();
		}
		if (temp1 < lenghtcount) {
			lenghtcount = temp1;
			bestPrime1 = primes[j];
		}
		if (temp2 < sumcount) {
			sumcount = temp2;
			bestprime2 = primes[j];
		}
		if (temp3 < sumprodcount) {
			sumprodcount = temp3;
			bestprime3 = primes[j];
		
		}
	
	}

	

	if (lenghtcount < sumcount) {
		if (lenghtcount < sumprodcount) {
			cout << "Recommend length  hash function with size :" << bestPrime1 << ", collisions: " << lenghtcount << endl;
		}
		else {
			cout << "Recommend Sum Production hash function with size :" << bestprime3 << ", collisions: " << sumprodcount << endl;

		}
	}
	else {
		cout << "Recommend Sum hash function with size :" << bestprime2 << ", collisions: " << sumcount << endl;

	}

	/*if (argc > 3) {
		HashTable
		cout << "Recommend polinomial function with size :" << primes[0] << ", collisions: " << lengthHashObject.getNumberOfCollisions() << endl;

	}*/
	return 0;
}
