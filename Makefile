CXX = g++
CXXFLAGS = -Wall -std=c++14

all: test

test: main.o board.o piece.o rook.o gamestate.o player.o
	$(CXX) $(CXXFLAGS) -o test main.o board.o piece.o rook.o gamestate.o player.o

main.o: main.cc board.h piece.h rook.h gamestate.h player.h
	$(CXX) $(CXXFLAGS) -c main.cc

board.o: board.cc board.h piece.h
	$(CXX) $(CXXFLAGS) -c board.cc

piece.o: piece.cc piece.h
	$(CXX) $(CXXFLAGS) -c piece.cc

rook.o: rook.cc rook.h piece.h
	$(CXX) $(CXXFLAGS) -c rook.cc

gamestate.o: gamestate.cc gamestate.h board.h player.h
	$(CXX) $(CXXFLAGS) -c gamestate.cc

player.o: player.cc player.h
	$(CXX) $(CXXFLAGS) -c player.cc

clean:
	rm -f *.o test