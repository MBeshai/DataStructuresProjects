all: Driver.o HashTable.o HashLibrary.o
	g++ -Wall Driver.cpp HashTable.cpp HashLibrary.cpp -o Driver.out



HashLibrary.o: HashLibrary.cpp
	g++ -Wall -c HashLibrary.cpp



HashTable.o: HashTable.cpp
	g++ -Wall -c HashTable.cpp



Driver.o: Driver.cpp
	g++ -Wall -c Driver.cpp



run: ./Driver.out $(INPUT) $(MIN_SIZE) $(MAX_SIZE) $(MIN_BASE) $(MAX_BASE)



clean:
	rm -rf *.o
	rm -f Driver.out
	rm -f *~ *.gch *#