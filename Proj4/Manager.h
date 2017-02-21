

#include <fstream>
#include <string>

#include "IntervalHeap.h"
#include "Store.h"
#include "Orders.h"

class Manager
{
public:
	Manager();
	Manager(std::string storeFile, std::string orderFile);
	~Manager();

	void createStore(std::string filename);
	void createOrders(std::string filename);
	void fillOrders(std::ofstream& fileStream);
	void printStatus(std::ofstream& fileStream);
	double getTotalSales();
private:
	Store m_store;
	Orders m_orders;
	double m_totalSales;
};

