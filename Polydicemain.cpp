//Polydicemain.cpp by Stephen Fernandez
#include "tools.hpp"
#include "debugdice.h"

int main(void){
	int nRolls=4;
	int nSide=6;
	
	banner();
	cout << "Welcome to the polydice roller module" <<endl; 
	cout << "Please enter the number of dice to be used" <<endl; 
	cout << nRolls<<endl;
	cout << "How many sides does the dice have?" <<endl; 
	cout << nSide<<endl;
	
	//cout << nRolls << "dice with" << nSide <<endl; Debug comment
	debugdice myDice(nSide, nRolls);
	//cout<<"before the roller"<<endl;
    myDice.rolldie();
	//cout<<"after the roller"<<endl;
	myDice.print();
	return 0;
}

