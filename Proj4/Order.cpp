#include <iostream>

#include "Order.h"

using namespace std;

Order::Order() : m_orderCompleted(false)
{
}

Order::~Order()
{
	Food* temp;
	while(!m_filledRequests.empty()) {
		temp = m_filledRequests.front();
		m_filledRequests.pop();
		delete temp;
	}
}

void Order::addRequestToOrder(Food::FOOD_TYPE type) {
	m_qRequests.push(type);
}

bool Order::addFoodToOrder(Food* food) {
	Food::FOOD_TYPE& nextRequest = getNextRequest();
	if (nextRequest == food->getType()) {
		m_qRequests.pop();
		m_filledRequests.push(food);

		if (m_qRequests.empty()) {
			m_orderCompleted = true;
		}
		return true;
	}
	else {
		return false;
	}
}

Food::FOOD_TYPE& Order::getNextRequest() {
	Food::FOOD_TYPE* outOfBounds = new Food::FOOD_TYPE(Food::TOTAL);
	if (m_qRequests.empty()) {
		return *outOfBounds;
	}
	else {
		return m_qRequests.front();
	}
}

Food* Order::popFoodFromOrder() {
	if (m_filledRequests.empty()) {
		return NULL;
	}

	Food* poppedFood = m_filledRequests.front();
	m_qRequests.push(poppedFood->getType());
	m_filledRequests.pop();
	return poppedFood;
}

void Order::printOrder(std::ofstream& fileStream) {
	queue< Food::FOOD_TYPE > tempRequests = m_qRequests;
	queue< Food* > tempFilledOrders = m_filledRequests;
	Food* cur = NULL;

	fileStream << m_sCustomerName;
	if (m_orderCompleted) {
		if (m_filledRequests.empty()) {
			fileStream << " - Unable to complete order";
		}
		else if (acceptPartial() && !m_qRequests.empty()) {
			fileStream << " (Partial)";
		}
	}
	fileStream << endl;
	if (!tempRequests.empty()) {
		if (m_orderCompleted) {
			fileStream << "Unfilled ";
		}
		fileStream << "Requests: ";
		while (!tempRequests.empty()) {
			fileStream << Food::getTypeName(tempRequests.front()) << ' ';
			tempRequests.pop();
		}
		fileStream << endl;
	}

	if (!m_filledRequests.empty()) {
		fileStream << "Items: " << ((m_orderCompleted) ? "" : " (Partial)") <<endl;
		while (!m_filledRequests.empty()) {
			cur = m_filledRequests.front();
			cur->printFood(fileStream);
			m_filledRequests.pop();
		}

		m_filledRequests = tempFilledOrders;

		fileStream << "***Total: $" << getOrderTotal() << endl;
	}
	
	fileStream << "-----" << endl;
}

void Order::removeCurrentRequest()
{
	m_qRequests.pop();
}

void Order::setCustomerName(std::string name) {
	m_sCustomerName = name;
}

void Order::setAcceptsPartial(bool accept) {
	m_bAcceptsPartial = accept;
}

void Order::setOrderType(bool x)
{
	if (x == true) {
		m_eType = Order::MAX;
	}
	else {
		m_eType = Order::MIN;
	}
}

bool Order::acceptPartial()
{
	return m_bAcceptsPartial;
}

double Order::getOrderTotal()
{
	double total = 0;
	queue< Food* > tempFilledOrders = m_filledRequests;
	Food* cur = NULL;

	if (!m_filledRequests.empty()) {
		while (!m_filledRequests.empty()) {
			cur = m_filledRequests.front();
			total += cur->getCost();
			m_filledRequests.pop();
		}

		m_filledRequests = tempFilledOrders;
	}

	return total;
}
