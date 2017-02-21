#pragma once

#include <fstream>
#include <string>
#include <queue>

#include "Food.h"

class Order
{
public:
	Order();
	~Order();

	void addRequestToOrder(Food::FOOD_TYPE type);
	enum ORDER_TYPE{MAX,MIN};
	// Returns true if successful
	bool addFoodToOrder(Food* food);
	Food::FOOD_TYPE& getNextRequest();
	Food* popFoodFromOrder();
	void printOrder(std::ofstream& fileStream);
	void removeCurrentRequest();

	void setCustomerName(std::string name);
	void setAcceptsPartial(bool accept);
	void setOrderComplete() { m_orderCompleted = true; }
	void setOrderType(bool x);
	bool acceptPartial();

	double getOrderTotal();

private:
	std::string m_sCustomerName;
	std::queue< Food::FOOD_TYPE >	m_qRequests;
	bool m_bAcceptsPartial;
	bool m_orderCompleted;
	std::queue< Food* > m_filledRequests;
	ORDER_TYPE m_eType;
};

