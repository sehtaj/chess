CXX = g++

CXXFLAGS = -std=c++17 -Wall -Wextra -g -I.
OBJS = main.o board.o pieces/rook.o pieces/bishop.o pieces/queen.o pieces/knight.o pieces/pawn.o pieces/king.o pieces/piece.o gamestate.o player.o human.o

EXEC = chess

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJS)

main.o: main.cc board.h gamestate.h player.h human.h
	$(CXX) $(CXXFLAGS) -c main.cc

board.o: board.cc board.h pieces/piece.h pieces/rook.h pieces/bishop.h pieces/queen.h pieces/knight.h pieces/pawn.h pieces/king.h
	$(CXX) $(CXXFLAGS) -c board.cc

pieces/piece.o: pieces/piece.cc pieces/piece.h
	$(CXX) $(CXXFLAGS) -c pieces/piece.cc -o pieces/piece.o

pieces/rook.o: pieces/rook.cc pieces/rook.h pieces/piece.h board.h
	$(CXX) $(CXXFLAGS) -c pieces/rook.cc -o pieces/rook.o

pieces/bishop.o: pieces/bishop.cc pieces/bishop.h pieces/piece.h board.h
	$(CXX) $(CXXFLAGS) -c pieces/bishop.cc -o pieces/bishop.o

pieces/queen.o: pieces/queen.cc pieces/queen.h pieces/piece.h board.h
	$(CXX) $(CXXFLAGS) -c pieces/queen.cc -o pieces/queen.o

pieces/knight.o: pieces/knight.cc pieces/knight.h pieces/piece.h board.h
	$(CXX) $(CXXFLAGS) -c pieces/knight.cc -o pieces/knight.o

pieces/pawn.o: pieces/pawn.cc pieces/pawn.h pieces/piece.h board.h
	$(CXX) $(CXXFLAGS) -c pieces/pawn.cc -o pieces/pawn.o

pieces/king.o: pieces/king.cc pieces/king.h pieces/piece.h board.h
	$(CXX) $(CXXFLAGS) -c pieces/king.cc -o pieces/king.o

gamestate.o: gamestate.cc gamestate.h board.h player.h
	$(CXX) $(CXXFLAGS) -c gamestate.cc

player.o: player.cc player.h
	$(CXX) $(CXXFLAGS) -c player.cc

human.o: human.cc human.h player.h
	$(CXX) $(CXXFLAGS) -c human.cc

clean:
	rm -f *.o pieces/*.o $(EXEC)