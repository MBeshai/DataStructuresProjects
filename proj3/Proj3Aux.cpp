#include "Proj3Aux.h"


Proj3Aux::Proj3Aux()
{
	//cout << "randasibda" << endl;
}

Proj3Aux::~Proj3Aux()
{
	//cout << "Sdfsdf" << endl;
}

void Proj3Aux::DoPrintCommand(string command, int depth)
{
}

int Proj3Aux::DoRemoveCommand(string command, int element)
{
	m_tree.remove(element);
	return 0;
}

int Proj3Aux::GetMedanCommand(string command)
{
	m_tree.Median();
	return 0;
}

int Proj3Aux::GetNthElementCommand(string command, int nthElement)
{
	m_tree.NthElement(nthElement);
	return 0;
}

int Proj3Aux::GetRankCommand(string command, int element)
{
	m_tree.Rank(element);
	return 0;
}

bool Proj3Aux::isComplete(string command)
{
	m_tree.IsComplete();
	return false;
}

bool Proj3Aux::isPerfect(string command)
{
	m_tree.IsPerfect();
	return false;
}
int Proj3Aux::GetResidualsCommand(string command) {
	return 1;
}

int Proj3Aux::ReadFromCommandFile(char * commandFile)
{


	
	int isFileopen = 0;
	ifstream myfile(commandFile);
	string line;

	if (myfile.is_open())
	{
		isFileopen = 1;
		
		while (getline(myfile, line))
		{
			string command;
			int lineSize = line.size();
			int intOfCommand;
			if (0 < lineSize && '#' != line[0]) {
				bool commandcheck = false;
				for (int i = 0; i < lineSize; i++) {

					if (' ' != line[i]) {
						command += line[i];
					}
					else {
						commandcheck = true;
					}
					if (true == commandcheck&&' ' != line[i]) {
						intOfCommand = line[i];
					}

				}
			}
			if ("PRINT" == command) {
				DoPrintCommand(command, intOfCommand);
			}
			if ("RESIDUALS" == command) {
				GetResidualsCommand(command);
			}
			if ("RANK" == command) {
				GetRankCommand(command, intOfCommand);
			}
			if ("NTH" == command) {
				GetNthElementCommand(command, intOfCommand);
			}
			if ("MEDIAN" == command) {
				GetMedanCommand(command);
			}
			if ("REMOVE" == command) {
				DoRemoveCommand(command, intOfCommand);
			}
			/*if ("PERFECT" == command) {
				isPerfect(command);
			}*/
			/*if ("COMPLETE" == command) {
				isComplete(command);

			}*/
		}
	}
	return isFileopen;
}

int Proj3Aux::ReadFromInputFile(char * inputFile)
{
	int isFileopen = 0;
	ifstream myfile(inputFile);
	string line;
	if (myfile.is_open())
	{
		isFileopen = 1;
		string numbers = "";
		while (getline(myfile, line))
		{
			int lineSize = line.size();
			if ( lineSize> 1) {
				for (int i = 0; i < lineSize; i++) {
					if (' ' != line[i]) {
						numbers += line[i];
					}
					if (' ' == line[i] && 0 <lineSize) {
						
						m_tree.insert(atoi(numbers.c_str()));
					}
				}
			}
		}

	}	
	myfile.close();
	
	return isFileopen;


}
