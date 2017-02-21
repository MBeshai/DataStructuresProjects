#include <string>
#include <vector>

#include "Orders.h"

using namespace std;

Orders::Orders() : m_pCurrentOrder(NULL)
{
}


Orders::~Orders()
{
	Order* temp;
	while (!m_ordersUnfilled.empty()) {
		temp = m_ordersUnfilled.front();
		m_ordersUnfilled.pop();
		delete temp;
	}

	while (!m_ordersCompleted.empty()) {
		temp = m_ordersCompleted.front();
		m_ordersCompleted.pop();
		delete temp;
	}

	if (m_pCurrentOrder != NULL) {
		delete &m_pCurrentOrder;
		m_pCurrentOrder = NULL;
	}
}

void Orders::addOrder(Order* order) {
	m_ordersUnfilled.push(order);
}

void Orders::completeOrder()
{
	m_pCurrentOrder->setOrderComplete();
	m_ordersCompleted.push(m_pCurrentOrder);
	m_ordersUnfilled.pop();

	if (m_ordersUnfilled.empty()) {
		m_pCurrentOrder = NULL;
	}
	else {
		m_pCurrentOrder = m_ordersUnfilled.front();
	}
}

Order* Orders::getCurrentOrder() {
	if (m_pCurrentOrder == NULL && !m_ordersUnfilled.empty()) {
		m_pCurrentOrder = m_ordersUnfilled.front();
	}
	return m_pCurrentOrder;
}

void Orders::printOrders(std::ofstream& fileStream) {
	queue< Order* > tempOrdersUnfilled = m_ordersUnfilled;
	queue< Order* > tempOrdersCompleted = m_ordersCompleted;
	Order* cur;

	fileStream << "---------- Orders -----------" << endl;

	if (!m_ordersUnfilled.empty()) {
		while (!m_ordersUnfilled.empty()) {
			cur = m_ordersUnfilled.front();
			cur->printOrder(fileStream);
			m_ordersUnfilled.pop();
		}

		m_ordersUnfilled = tempOrdersUnfilled;
	}

	if (!m_ordersCompleted.empty()) {
		while (!m_ordersCompleted.empty()) {
			cur = m_ordersCompleted.front();
			cur->printOrder(fileStream);
			m_ordersCompleted.pop();
		}

		m_ordersCompleted = tempOrdersCompleted;
	}
}

void Orders::loadOrders(std::string filename) {
	string inputName, isAcceptPartial, inputRequests;
	vector<string> requests;
	ifstream ordersFileStream;
	Order* newOrder;

	ordersFileStream.open(filename.c_str());
	if (ordersFileStream.is_open()) {
		while (!ordersFileStream.eof()) {
			newOrder = new Order();

			// String gotten when the second quote is found is the string we want
			getline(ordersFileStream, inputName, '\"');
			getline(ordersFileStream, inputName, '\"');
			newOrder->setCustomerName(inputName);

			ordersFileStream >> isAcceptPartial;
			newOrder->setAcceptsPartial((isAcceptPartial.compare("yes") == 0));
			newOrder->setOrderType((isAcceptPartial.compare("max") == 0));
			getline( ordersFileStream, inputRequests, '\n');
			requests = getArrayOfRequests(inputRequests);

			for (vector<string>::iterator it = requests.begin(); it != requests.end(); ++it) {
				newOrder->addRequestToOrder(getFoodTypeFromString(*it));
			}

			m_ordersUnfilled.push(newOrder);
		}
	}
}

std::vector<std::string> Orders::getArrayOfRequests(std::string requests)
{
	vector<string> outputArr;
	size_t pos = 0;
	string token, delimiter = " ";
	while ((pos = requests.find(delimiter)) != std::string::npos) {
		token = requests.substr(0, pos);
		requests.erase(0, pos + delimiter.length());
		if (token.length() > 0) {
			outputArr.push_back(token);
		}
	}
	outputArr.push_back(requests);

	return outputArr;
}

Food::FOOD_TYPE Orders::getFoodTypeFromString(std::string str) {
	if (str.compare("meat") == 0) {
		return Food::MEAT;
	}
	else if (str.compare("fruit") == 0) {
		return Food::FRUIT;
	}
	else if (str.compare("vegetable") == 0) {
		return Food::VEGETABLE;
	}
	else if (str.compare("starch") == 0) {
		return Food::STARCH;
	}
	else {
		return Food::SWEET;
	}
}

