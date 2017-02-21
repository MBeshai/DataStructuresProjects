#include "Manager.h"


Manager::Manager() {
	m_header = 0;
}
Manager::Manager(char* store, char* orders) {

	createStore(store);
	createOrders(orders);
	m_header = 0;

}
void Manager::createStore(string filename) {
	m_store.stockStore(filename);
}
void Manager::createOrders(string filename) {
	m_orders.loadOrders(filename);
}
void Manager::fillOrders(ofstream &n) {
	n << "----------Orders-----------" << endl;
	int x = m_orders.getNumOfOrders();

	for (int i = 0; i < x; i++) {


		Order topO = *m_orders.getCurrentORder();



		if (topO.isAcceptPartial()) {
			n << topO.getCustomerName() << endl;
			n << "items: " << endl;
			vector<Food::FOOD_TYPE> foodRequests = topO.getRequests();
			double cost = 0;
			for (int v = 0; v < foodRequests.size(); v++) {


				if (m_store.getFoodByType(foodRequests[v]) !=0) {

					Food currentF = *m_store.getFoodByType(foodRequests[v]);
					cost += currentF.getCost();

					n << currentF.getName() << " " << currentF.getCost() << endl;

				}

			}n << "***Total: " << cost << endl;
			n << "-----" << endl;
		}
		if (!topO.isAcceptPartial()) {
			vector<Food::FOOD_TYPE> foodRequests = topO.getRequests();
			double cost = 0;
			bool foodcheck = false;
			for (int i = 0; i < foodRequests.size(); i++) {
				if (m_store.getFoodByType(foodRequests[i]) == 0) {
					foodcheck = true;
				}
			}

		
				if (foodcheck == false) {
					n << topO.getCustomerName() << endl;
					n << "items: " << endl;
					vector<Food::FOOD_TYPE> foodRequests = topO.getRequests();
					double cost = 0;
					for (int v = 0; v < foodRequests.size(); v++) {


						if (m_store.getFoodByType(foodRequests[v]) != 0) {

							Food currentF = *m_store.getFoodByType(foodRequests[v]);
							cost += currentF.getCost();

							n << currentF.getName() << " " << currentF.getCost() << endl;

						}

					}n << "***Total: " << cost << endl;
					n << "-----" << endl;
				}
			


			if (foodcheck == false) {

				n << topO.getCustomerName() << " Unable to complete order" << endl;
				n<<"------" << endl;
			}
		}
		m_orders.completeOrder();
	}
}

void Manager::printStatus(ofstream &n)
{
	if (m_header == 0) {
		n << "Mina Beshai, Section 7" << endl;
		m_header++;
	}
	m_store.printStore(n);
	m_orders.printOrders(n);
}


