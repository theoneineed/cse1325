CXXFLAGS = --std=c++17

default: Color run

Color: main.o Color.o *.h
	$(CXX) $(CXXFLAGS) main.o Color.o -o Color

main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o
Color.o: Color.cpp *.h
	$(CXX) $(CXXFLAGS) -c Color.cpp -o Color.o

Color.gch: Color.h
	$(CXX) $(CXXFLAGS) -c Color.h -o Color.gch

run: Color
	./Color

clean:
	rm -f *.o *.gch ~* color
