#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

#include "Manager.h"

void printGreeding(std::ofstream& stream);

int main(int argc, char* argv[]) {
	std::ofstream outputFileStream;
	
	Manager manager(argv[1], argv[2]);

	outputFileStream.open("results.txt");

	printGreeding(outputFileStream);

	manager.printStatus(outputFileStream);

	manager.fillOrders(outputFileStream);

	manager.printStatus(outputFileStream);

	outputFileStream.close();

	return EXIT_SUCCESS;
}

void printGreeding(std::ofstream& stream) {
	stream << "Katherine Hirsch, Section 07" << std::endl;
}