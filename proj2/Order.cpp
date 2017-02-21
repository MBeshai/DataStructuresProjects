#include "Order.h"

Order::Order() {

}
Order::Order(string name, bool partialOrder, queue<Food::FOOD_TYPE> requests)
{
	int x=requests.size();
	m_sCustomerName = name;
	m_bAcceptsPartialOrder = partialOrder;
	for (int i = 0; i < x; i++) {
		m_requests.push(requests.front());
		requests.pop();
	}
	
}
void Order::setCustomerName(string name)
{
	m_sCustomerName = name;
}

void Order::setAcceptPartial(bool partial)
{
}

void Order::setOrderComplete()
{
}

bool Order::isAcceptPartial()
{
	return m_bAcceptsPartialOrder;
}

string Order::getCustomerName()
{
	return m_sCustomerName;
}

int Order::getNumRequests()
{
	return m_requests.size();
}

vector<Food::FOOD_TYPE> Order::getRequests()
{
	vector<Food::FOOD_TYPE> mreqs;
	for (int i = 0; i < m_requests.size(); i++) {
		Food::FOOD_TYPE m;
		m = m_requests.front();
		mreqs.push_back(m);
		m_requests.pop();
		m_requests.push(m);
	}
	return mreqs;
}

Food::FOOD_TYPE& Order::getNextRequest()
{
	// TODO: insert return statement here
	
	return m_requests.front();

}

void Order::addRequestToOrder(Food::FOOD_TYPE)
{
}
