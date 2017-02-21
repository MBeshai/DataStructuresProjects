#include "Manager.h"

#include <iostream>

using namespace std;

Manager::Manager()
{
}

Manager::Manager(std::string storeFile, std::string orderFile) {
	createStore(storeFile);
	createOrders(orderFile);
	m_totalSales = 0;
}

Manager::~Manager()
{
}



void Manager::createStore(std::string filename) {
	m_store.stockStore(filename);
}

void Manager::createOrders(std::string filename) {
	m_orders.loadOrders(filename);
}

void Manager::fillOrders(std::ofstream& fileStream) {
	Order* currentOrder = m_orders.getCurrentOrder();
	queue< Food::FOOD_TYPE > unfilledRequests;
	Food::FOOD_TYPE currentRequest;
	Food* currentFood;

	while (currentOrder != NULL) {
		currentRequest = currentOrder->getNextRequest();
		if ( currentRequest < Food::TOTAL) {
			currentFood = m_store.getFoodByType(currentRequest);
			// If store doesn't have any more food of the requested type
			if (currentFood == NULL) {
				// Return all the food in the order back to the store if partial is not accepted
				if (!currentOrder->acceptPartial()) {
					currentFood = currentOrder->popFoodFromOrder();
					while (currentFood != NULL) {
						m_store.addFood(currentFood);
						currentFood = currentOrder->popFoodFromOrder();
					}
					m_orders.completeOrder();
					currentOrder = m_orders.getCurrentOrder();
					//printStatus(fileStream);
				}
				else {
		//			m_totalSales+=currentFood->getCost();
					unfilledRequests.push(currentRequest);
					currentOrder->removeCurrentRequest();
				}
			}
			else {
				currentOrder->addFoodToOrder(currentFood);
				m_totalSales += currentFood->getCost();
			}
		}
		else {
			while (!unfilledRequests.empty()) {
				currentRequest = unfilledRequests.front();
				unfilledRequests.pop();
				currentOrder->addRequestToOrder(currentRequest);
			}
			m_orders.completeOrder();
			currentOrder = m_orders.getCurrentOrder();
			//printStatus(fileStream);
		}
	}
}

void Manager::printStatus(std::ofstream& fileStream) {
	m_store.printStore(fileStream);
	m_orders.printOrders(fileStream);
}

double Manager::getTotalSales()
{
	return m_totalSales;
}
