#pragma once

#include <fstream>
#include <string>

class Food {

	public: 
		enum FOOD_TYPE {
			MEAT,
			FRUIT,
			VEGETABLE,
			STARCH,
			SWEET,
			TOTAL
		};

		// Public Functions

		// Constructors
		Food();
		Food(std::string name, double cost);

		// Member Functions
		void printFood(std::ofstream& fileStream) const;
		Food::FOOD_TYPE getType() const;
		static std::string getTypeName( Food::FOOD_TYPE type );
		std::string getName() const { return m_sName; }
		double getCost() const { return m_dCost;  }
	
	protected: 
		void setType( Food::FOOD_TYPE type );

	private:
		// Members
		std::string	m_sName;
		FOOD_TYPE	m_eType;
		double		m_dCost;
};