#include "Store.h"

void Store::addFood(Food * food)
{
}

Food * Store::getFoodByType(Food::FOOD_TYPE foodtype)
{
	

	if (foodtype == Food::STARCH) {
	//	cout << 1 << endl;
		if (m_bins[1].size() > 0) {
			return m_bins[1].top();
			m_bins[1].pop();
		}

	}
	if (foodtype == Food::MEAT) {
//		cout << 2 << endl;
		if (m_bins[2].size() > 0) {
			return m_bins[2].top();
			m_bins[2].pop();
		}
	}	if (foodtype == Food::SWEET) {
	//	cout << 3<< endl;
			if (m_bins[0].size() > 0) {
				return m_bins[0].top();
				m_bins[0].pop();
			}
		}
		if (foodtype == Food::VEGETABLE) {
		//	cout << 4 << endl;

			if (m_bins[3].size() > 0) {
				return m_bins[3].top();
				m_bins[3].pop();
			}
		}
		if (foodtype == Food::FRUIT) {
	//		cout << 5<< endl;
			if (m_bins[4].size() > 0) {
				return m_bins[4].top();
				m_bins[4].pop();
			}
		}
	
	return 0;
}
void Store::stockStore(string filename)
{
	stack<Food*> vegies;
	stack<Food*> fruits;
	stack<Food*> sweets;
	stack<Food*> meats;
	stack<Food*> starchs;
	string line;
	ifstream myfile(filename.c_str());
	string word;
	vector <string> words;
	vector <vector<string> > lines;
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

	string foodName;
	Food::FOOD_TYPE foodType;
	double price;

	for (int i = 0; i < lines.size(); i++) {
		for (int j = 0; j < lines[i].size(); j++) {

			//cout << "linelengthd::"<<lines[i].size() << endl;
			if (j == 0) {
				foodName = lines[i][j];
			}
			if (j == 1) {
				
				if (lines[i][j] == "starch") {
					foodType = Food::STARCH;
				
				}
				if (lines[i][j] == "sweet") {
					foodType = Food::SWEET;
				}
				if (lines[i][j] == "meat") {
					foodType = Food::MEAT;
					
				}
				if (lines[i][j] == "fruit") {
					foodType = Food::FRUIT;
				
				}
				if (lines[i][j] == "vegetable") {
					foodType = Food::VEGETABLE;
				
				}


			}
			if (j == 2) {
				//cout << lines[i][j] << endl;
			  price = atof(lines[i][j].c_str());
			}
		}
		for (int i = 0; i < 5; i++) {

		}
		if (foodType == Food::SWEET) {
			Food *food = new Food(foodName, foodType, price);
			//m_bins[0].push(food);
			sweets.push(food);
		}
		if (foodType == Food::STARCH) {
			Food *food = new Food(foodName, foodType, price);
			///	m_bins[1].push(food);
			starchs.push(food);
		}
		if (foodType == Food::MEAT) {
			Food *food = new Food(foodName, foodType, price);
			//	m_bins[2].push(food);
			meats.push(food);
		}
		if (foodType == Food::VEGETABLE) {

			Food *food = new Food(foodName, foodType, price);
			//	m_bins[3].push(food);
			vegies.push(food);

		}
		if (foodType == Food::FRUIT) {
			Food *food = new Food(foodName, foodType, price);
			//	m_bins[4].push(food);
			fruits.push(food);
		}

	}
	//cout << "Sweets: " << sweets.size() << "   Starchs:" << starchs.size() << "meats: :" << meats.size()<< endl;
	
		m_bins.push_back(sweets);
		m_bins.push_back(starchs);
		m_bins.push_back(meats);
		m_bins.push_back(vegies);
		m_bins.push_back(fruits);
	
}

void Store::printStore(ofstream& results)
{
	
	results << "---------- Store ----------" << endl;
	vector<Food*> reverseStackOfFood;
	queue<int> stackSizes;
	
	

	for (int g = 0; g < m_bins.size(); g++) {
		
		for (int j = 0; j < m_bins[g].size() ; j++) {
			
				if (g == 0) {
					if (j == 0) { results << "Sweets " << m_bins[g].size() << " ";  }
					Food n = *m_bins[g].top();
					results << n.getName()<<" ";
					reverseStackOfFood.push_back(m_bins[g].top());
					m_bins[g].pop();
				
				}

				if (g == 1) {
					if (j == 0) { results << "Starch " << m_bins[g].size() << " "; }
					Food n = *m_bins[g].top();
					results << n.getName()<<" ";
					reverseStackOfFood.push_back(m_bins[g].top());
					m_bins[g].pop();
				}
			if (g == 2) {
					if (j == 0) { results << "Meat " << m_bins[g].size() << " "; }
					Food n = *m_bins[g].top();
					results << n.getName()<<" ";
					reverseStackOfFood.push_back(m_bins[g].top());
					m_bins[g].pop();
				}
				if (g == 3) {
					if (j == 0) { results << "Vegetable " << m_bins[g].size() << " "; }
					Food n = *m_bins[g].top();
					results << n.getName()<<" ";
					reverseStackOfFood.push_back(m_bins[g].top());
					m_bins[g].pop();
				}
				if (g == 4) {
					if (j == 0) { results << "Fruit " << m_bins[g].size() << " "; }
					Food n = *m_bins[g].top();
					results << n.getName()<<" ";
					reverseStackOfFood.push_back(m_bins[g].top());
					m_bins[g].pop();
				}
		}
		results << endl;
		int e = reverseStackOfFood.size();
		
		for (int m = 0; m <  reverseStackOfFood.size(); m++) {
			m_bins[g].push(reverseStackOfFood[reverseStackOfFood.size() - (m +1)]);
			reverseStackOfFood.pop_back();
		}
		
	}
}
