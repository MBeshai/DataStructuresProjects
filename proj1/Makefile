CC	= g++
all: driver.o Node341.o List341.o Queue341.o Stack341.o
	$(CC) -Wall driver.o Node341.o List341.o Queue341.o Stack341.o -o Driver.out

driver.o: driver.cpp
	$(CC) -Wall -c driver.cpp
Node341.o: Node341.cpp
	$(CC) -Wall -c Node341.cpp
List341.o: List341.cpp
	$(CC) -Wall -c List341.cpp
Queue341.o: Queue341.cpp
	$(CC) -Wall -c Queue341.cpp
Stack341.o: Stack341.cpp
	$(CC) -Wall -c Stack341.cpp
run:
	./Driver.out
clean:
	rm -rf *.o
	rm -f Driver.out
	rm -f *~.h.gch *#