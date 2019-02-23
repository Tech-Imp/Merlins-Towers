#Makefile for Merlins Towers
.SUFFIXES: .cpp
.cpp.o:
	g++ -c $(CXXFLAGS) $<

CXXFLAGS = -g -Wall -I../..

#object files- the meat and bones prior to creation
OBJ = gamemain.o clist.o player.o dice.o CantStopDice.o column.o gameboard.o gamemaster.o flavor.o tools.o

MerlinsTowers: $(OBJ)
	g++ $(CXXFLAGS) -o MerlinsTowers $(OBJ)

clean:
	rm -f $(OBJ) MerlinsTowers


#Dependencies to create objects
tools.o: 	tools.cpp tools.hpp
gamemain.o:	gamemain.cpp gamemaster.h tools.hpp
gamemaster.o:	gamemaster.cpp gamemaster.h  
clist.o:	clist.cpp clist.h cell.h
player.o:	player.cpp player.hpp
dice.o:		dice.cpp dice.hpp
CantStopDice.o: CantStopDice.cpp CantStopDice.h
column.o: 	column.cpp column.h
gameboard.o: 	gameboard.cpp gameboard.hpp
flavor.o: 	flavor.cpp flavor.h

