CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g

OBJS = main.o board.o rook.o bishop.o queen.o piece.o

EXEC = chess

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJS)

main.o: main.cc board.h rook.h bishop.h queen.h piece.h
	$(CXX) $(CXXFLAGS) -c main.cc

board.o: board.cc board.h piece.h
	$(CXX) $(CXXFLAGS) -c board.cc

piece.o: piece.cc piece.h
	$(CXX) $(CXXFLAGS) -c piece.cc

rook.o: rook.cc rook.h piece.h board.h
	$(CXX) $(CXXFLAGS) -c rook.cc

bishop.o: bishop.cc bishop.h piece.h board.h
	$(CXX) $(CXXFLAGS) -c bishop.cc

queen.o: queen.cc queen.h piece.h board.h
	$(CXX) $(CXXFLAGS) -c queen.cc

clean:
	rm -f *.o $(EXEC)