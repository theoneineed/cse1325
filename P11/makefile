CXXFLAGS = --std=c++17

cart: cart.o item.o main.o
	$(CXX) $(CXXFLAGS) cart.o item.o main.o -o cart

cart.gch: cart.h
	$(CXX) $(CXXFLAGS) -c cart.h -o cart.gch

cart.o: cart.cpp
	$(CXX) $(CXXFLAGS) -c cart.cpp -o cart.o

item.gch: item.h
	$(CXX) $(CXXFLAGS) -c item.h -o item.gch

item.o: item.cpp
	$(CXX) $(CXXFLAGS) -c item.cpp -o item.o

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

clean:
	rm -f *.o *.gch ~* cart item
