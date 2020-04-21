CXXFLAGS = --std=c++17

all: main

main: main.o Customer.o Options.o Desktop.o Order.o Store.o *.h
	$(CXX) $(CXXFLAGS) main.o Customer.o Options.o Desktop.o Order.o Store.o -o product

main.o: main.cpp *.h
		$(CXX) $(CXXFLAGS) main.cpp -c -o main.o
Customer.o: Customer.cpp *.h
	$(CXX) $(CXXFLAGS) Customer.cpp -c -o Customer.o

Option.o: Options.cpp *.h
	$(CXX) $(CXXFLAGS) Options.cpp -c -o Options.o

Desktop.o: Desktop.cpp *.h
	$(CXX) $(CXXFLAGS) Desktop.cpp -c -o Desktop.o

Order.o: Order.cpp *.h
	$(CXX) $(CXXFLAGS) Order.cpp -c -o Order.o

Store.o: Store.cpp *.h
	$(CXX) $(CXXFLAGS) Store.cpp -c -o Store.o

clean:
	rm -f *.o *.gch a.out product
