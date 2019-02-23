//Gamemain.cpp -the main file for Cant stop
//Stephen Fernandez
//

#include "tools.hpp"
#include "gamemaster.h"

	int main(void){
    int nRolls=4;
	int nSide=6;
	int players=0;
	bool validSTART=false;
	const double version = 1.00;

	banner();
	
	cout << "Welcome to Merlin's Towers, version ";
	cout <<  setprecision(2) << version <<". "<<endl;
	//cout << "Please enter the number of dice to be used" <<endl; 
	//cin >> nRolls;
	//cout << "How many sides does the dice have?" <<endl; 
	//cin >> nSide;
	cout << "How many players will be playing?"<< endl;
	
	do{
		cin >> players;
		if(players>=2 && players<=4){
			gamemaster myGame(nSide, nRolls, players);
			myGame.play();
			validSTART=true;
		}
		else{
			cin.clear();
			cin.ignore(255,'\n');
			cout<<"Merlin's Towers (a version of Cant Stop) can only be played with ";
			cout<<"2 to 4 players. Please re-enter the number of players."<<endl;
		}
	}while(validSTART != true);
		//cout << "Begin!"<<endl;
		
		return 0;
}
