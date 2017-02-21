#include "Orders.h"
#include <string>
#include <fstream>
void Orders::addOrder(Order * m)
{
	m_ordersUnfilled.push(m);
}

void Orders::completeOrder()
{
	//m_ordersCompleted.push(m_pCurrentOrder);
	m_ordersUnfilled.pop();
	//m_pCurrentOrder = m_ordersUnfilled.front();
}
 int Orders::getNumOfOrders() {
	return m_ordersUnfilled.size();
}
Order * Orders::getCurrentORder()
{ 
	/*
	if (m_pCurrentOrder != nullptr) {
		return m_pCurrentOrder;
	}
	else {*/
		return m_ordersUnfilled.front();
	//}
}

void Orders::loadOrders(string filename)
{
	string line;
	ifstream myfile;
	myfile.open(filename.c_str(), ifstream::in);
	string word;
	vector <string> words;
	std::vector <std::vector <string> > lines;
	int quotationsCheck = 0;
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			line += ' ';
			quotationsCheck = 0;

			for (int i = 0; i < line.size(); i++) {
				if (line[i] != ' ') {
					if (line[i] == '"') {
						quotationsCheck++;
					}
					else {
						word += line[i];
					}
				}
				else if (line[i] == ' ' && quotationsCheck != 1) {
					words.push_back(word);
					//	cout << word << endl;
					word.clear();
				}
				else if (line[i] == ' ' && quotationsCheck == 1) {
					word += ' ';
				}
				else {
					words.push_back(word);
					word.clear();
				}


			}

			lines.push_back(words);
			words.clear();

		}

		myfile.close();
	}
	




	for (int i = 0; i < lines.size(); i++) {
		
		string customerName;
		bool partialOrder;
		queue<Food::FOOD_TYPE> requests;
		//cout << lines.size()<< endl;
		for (int j = 0; j < lines[i].size(); j++) {
		
			if (j == 0) {
				customerName = lines[i][j];
			}
			if (j == 1) {
				if (lines[i][j] == "yes") {

					partialOrder = true;

				}
				else {
					partialOrder = false;
				}
			}

			if (j > 1) {
				//cout << lines[i][j] << endl;
				if (lines[i][j] == "starch") {
				
				  //Food::FOOD_TYPE s = Food::FOOD_TYPE::STARCH;
					requests.push(Food::STARCH);
				}
				if (lines[i][j] == "sweet") {
				  Food::FOOD_TYPE s = Food::SWEET;
					requests.push(s);
				}
				if (lines[i][j] == "meat") {
					Food::FOOD_TYPE s = Food::MEAT;
					requests.push(s);
				}
				if (lines[i][j] == "fruit") {
					Food::FOOD_TYPE s = Food::FRUIT;
					requests.push(s);
				}
				if (lines[i][j] == "vegetable") {
					Food::FOOD_TYPE s = Food::VEGETABLE;
					requests.push(s);
				}

			}
		}
		//cout << "Customer NAame: " << customerName << " partial order: " << partialOrder << " number of orders: " << requests.size() << endl;
		Order *m = new Order(customerName, partialOrder, requests);
		
		m_ordersUnfilled.push(m);
	}


}

void Orders::printOrders(ofstream & out)
{
	
	out << "---------- Orders -----------" << endl;
	queue<Order*> ordersUnfilled;
	if (m_ordersUnfilled.size() > 0) {
		for (int i = 0; i < m_ordersUnfilled.size(); i++) {

			Order *orderQ = m_ordersUnfilled.front();
			Order order = *orderQ;

			out << order.getCustomerName() << endl;
			vector<Food::FOOD_TYPE> foodtypes = order.getRequests();

			out << "Requests: ";
			for (int j = 0; j < order.getNumRequests(); j++) {

			  if (Food::STARCH==foodtypes[j]) {
					out << "Starch ";
				}
				if (foodtypes[j] == Food::MEAT) {
					out << "Meat ";
				}
				if (foodtypes[j] == Food::SWEET) {
					out << "Sweet ";
				}
				if (foodtypes[j] == Food::VEGETABLE) {
					out << "Vegetable ";
				}
				if (foodtypes[j] == Food::FRUIT) {
					out << "Fruit ";
				}
			}
			out << "\n ----- \n";
			m_ordersUnfilled.pop();
			m_ordersUnfilled.push(orderQ);
		}
	}





}

queue<Order*> Orders::getOrdersUnfilled()
{
	return m_ordersUnfilled;
}
