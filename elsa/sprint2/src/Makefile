
CXXFLAGS += --std=c++17
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

all: elsa run

elsa: main.o mainwin.o entrydialog.o store.o customer.o options.o desktop.o order.o
	$(CXX) $(CXXFLAGS) main.o mainwin.o entrydialog.o store.o customer.o options.o desktop.o order.o $(GTKFLAGS) -o elsa

main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp $(GTKFLAGS) -o main.o

entrydialog.o: entrydialog.cpp *.h
	$(CXX) $(CXXFLAGS) -c entrydialog.cpp $(GTKFLAGS) -o entrydialog.o

mainwin.o: mainwin.cpp *.h
	$(CXX) $(CXXFLAGS) -c mainwin.cpp $(GTKFLAGS) -o mainwin.o

store.o: store.cpp *.h
	$(CXX) $(CXXFLAGS) -c store.cpp -o store.o

customer.o: customer.cpp *.h
	$(CXX) $(CXXFLAGS) -c customer.cpp -o customer.o

options.o: options.cpp *.h
	$(CXX) $(CXXFLAGS) -c options.cpp -o options.o

desktop.o: desktop.cpp *.h
	$(CXX) $(CXXFLAGS) -c desktop.cpp -o desktop.o

order.o: order.cpp *.h
	$(CXX) $(CXXFLAGS) -c order.cpp -o order.o

run:
	./elsa
	
clean:
	rm -f *.o *.gch elsa
