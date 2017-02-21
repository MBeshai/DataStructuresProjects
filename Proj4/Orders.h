#pragma once

#include <fstream>
#include <queue>
#include "Order.h"

class Orders
{
public:
	Orders();
	~Orders();

	void addOrder(Order* order);
	void completeOrder();
	Order* getCurrentOrder();
	void printOrders(std::ofstream& fileStream);
	void loadOrders(std::string filename);

private:
	std::vector<std::string> getArrayOfRequests(std::string requests);
	Food::FOOD_TYPE getFoodTypeFromString(std::string str);

	Order* m_pCurrentOrder;
	std::queue< Order* > m_ordersUnfilled;
	std::queue< Order* > m_ordersCompleted;
};

