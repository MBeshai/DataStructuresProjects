CC = g++
CFLAGS = -g -ansi -Wall
TARGET = Driver
TARGET1 = Manager
TARGET2 = Store
TARGET3 = Orders
TARGET4 = Order
TARGET5 = Food
TARGET6 = Meat
TARGET7 = Vegetable
TARGET8 = Starch
TARGET9 = Sweet
TARGET10 = Fruit

all: Driver
Driver: Driver.cpp
        $(CC) $(CFLAGS) $(TARGET).cpp $(TARGET1).cpp $(TARGET2).cpp $(TARGET3).\
cpp $(TARGET4).cpp $(TARGET5).cpp $(TARGET6).h $(TARGET7).h $(TARGET8).h $(TARG\
ET9).h $(TARGET10).h -o $(TARGET).out

run:
        ./Driver

clean:
        rm -rf *.o
        rm -f Driver.out
        rm -f *~ *.h.gch #*#