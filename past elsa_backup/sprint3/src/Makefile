
CXXFLAGS += --std=c++17
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

elsa: main.o mainwin.o entrydialog.o store.o customer.o options.o desktop.o order.o
	$(CXX) $(CXXFLAGS) main.o mainwin.o entrydialog.o store.o customer.o options.o desktop.o order.o $(GTKFLAGS) -g -o elsa

main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp $(GTKFLAGS) -g -o main.o

entrydialog.o: entrydialog.cpp *.h
	$(CXX) $(CXXFLAGS) -c entrydialog.cpp $(GTKFLAGS) -g -o entrydialog.o

mainwin.o: mainwin.cpp *.h
	$(CXX) $(CXXFLAGS) -c mainwin.cpp $(GTKFLAGS) -g -o mainwin.o

store.o: store.cpp *.h
	$(CXX) $(CXXFLAGS) -c store.cpp -g -o store.o

customer.o: customer.cpp *.h
	$(CXX) $(CXXFLAGS) -c customer.cpp -g -o customer.o

options.o: options.cpp *.h
	$(CXX) $(CXXFLAGS) -c options.cpp -g -o options.o

desktop.o: desktop.cpp *.h
	$(CXX) $(CXXFLAGS) -c desktop.cpp -g -o desktop.o

order.o: order.cpp *.h
	$(CXX) $(CXXFLAGS) -c order.cpp -g -o order.o

clean:
	rm -f *.o *.gch elsa
