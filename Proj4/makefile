#DIR1 = /afs/umbc.edu/users/k/h/khirsc1/home/cs341proj/proj2/src/
CXX = g++
CXXFLAGS = -ansi -Wall -g #-I . -I $(DIR1)
OBJS = Driver.o Manager.o Orders.o Order.o Store.o Food.o Fruit.o Meat.o Starch.o Sweet.o Vegetable.o IntervalHeap.o Node.o

all: $(OBJS) 
	$(CXX) $(CXXFLAGS) $(OBJS) -o Driver.out
	
Driver.o: Driver.cpp Store.h Orders.h Food.h
	$(CXX) $(CXXFLAGS) -c Driver.cpp	
	
Manager.o: Manager.h Manager.cpp Food.h
	$(CXX) $(CXXFLAGS) -c Manager.cpp
	
Orders.o: Orders.h Orders.cpp 
	$(CXX) $(CXXFLAGS) -c Orders.cpp

Order.o: Order.h Order.cpp 
	$(CXX) $(CXXFLAGS) -c Order.cpp

Store.o: Store.h Store.cpp 
	$(CXX) $(CXXFLAGS) -c Store.cpp
	
Food.o: Food.h Food.cpp 
	$(CXX) $(CXXFLAGS) -c Food.cpp
	
Fruit.o: Fruit.h Fruit.cpp
	$(CXX) $(CXXFLAGS) -c Fruit.cpp

Meat.o: Meat.h Meat.cpp 
	$(CXX) $(CXXFLAGS) -c Meat.cpp
	
Starch.o: Starch.h Starch.cpp 
	$(CXX) $(CXXFLAGS) -c Starch.cpp
	
Sweet.o: Sweet.h Sweet.cpp 
	$(CXX) $(CXXFLAGS) -c Sweet.cpp
	
Vegetable.o: Vegetable.h Vegetable.cpp 
	$(CXX) $(CXXFLAGS) -c Vegetable.cpp
	
IntervalHeap.o: IntervalHeap.cpp
	$(CXX) $(CXXFLAGS) -c IntervalHeap.cpp
Node.o: Node.cpp
	$(CXX) $(CXXFLAGS) -c Node.cpp 
clean:
	rm *.o* results.txt
	
run:
	./Driver.out $(STORE) $(ORDERS)
