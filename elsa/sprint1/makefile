CXXFLAGS = --std=c++17

all: product

product: Customer.o Options.o Desktop.o Order.o Store.o *.h
	$(CXX) $(CXXFLAGS) Customer.o Options.o Desktop.o Order.o Store.o -o product

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
