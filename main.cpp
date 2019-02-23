//Stephen Fernandez								Main.cpp
//Column n Board module
//

#include "tools.hpp"
#include "gameboard.hpp"

int main(void){
	int nSides=0;
	int nDice=0;
	int players=0;

	banner();
	cout << "Welcome to the Gameboard module." << endl;
	cout<< "Please enter the number of sides the dice has:"<<endl;
	cin >> nSides;
	
	cout << "Now enter the number of dice to be used:"<<endl;
	cin >> nDice;

	cout << "Finally, enter the number of players playing:"<<endl;
	cin >> players;
	
	gameboard myBoard(nSides, nDice, players);
	myBoard.print();
	myBoard.startPlayer(2, 2);
	myBoard.startPlayer(2, 2);
	myBoard.startPlayer(2, 2);
	
	myBoard.stop(2);
	
	myBoard.startPlayer(2, 3);
	myBoard.startPlayer(7, 3);
	
	myBoard.stop(3);
	
	myBoard.startPlayer(7, 1);
	myBoard.startPlayer(7, 1);
	myBoard.startPlayer(6, 1);
	
	myBoard.stop(1);
	
	myBoard.startPlayer(12,4);
	myBoard.startPlayer(6,4);
	myBoard.startPlayer(12,4);
	myBoard.startPlayer(12,4);
	
	myBoard.bust(4);
	
	myBoard.printINTEL();
					
	return 0;
	
}