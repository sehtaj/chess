CXX = g++
CXXFLAGS = -Wall -std=c++14

all: test

test: main.o board.o
	$(CXX) $(CXXFLAGS) -o test main.o board.o

main.o: main.cc board.h
	$(CXX) $(CXXFLAGS) -c main.cc

board.o: board.cc board.h
	$(CXX) $(CXXFLAGS) -c board.cc

clean:
	rm -f *.o test

