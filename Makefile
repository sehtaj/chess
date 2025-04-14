CXX = g++
CXXFLAGS = -Wall -std=c++14

all: test

test: main.o board.o piece.o rook.o
	$(CXX) $(CXXFLAGS) -o test main.o board.o piece.o rook.o

main.o: main.cc board.h piece.h rook.h
	$(CXX) $(CXXFLAGS) -c main.cc

board.o: board.cc board.h piece.h
	$(CXX) $(CXXFLAGS) -c board.cc

piece.o: piece.cc piece.h
	$(CXX) $(CXXFLAGS) -c piece.cc

rook.o: rook.cc rook.h piece.h
	$(CXX) $(CXXFLAGS) -c rook.cc

clean:
	rm -f *.o test