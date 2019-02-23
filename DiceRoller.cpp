//DiceRoller.cpp by Stephen Fernandez
#include "tools.hpp"
#include "dice.hpp"


int main(void){
	int nRolls=0;
	int nSide=0;
	
	banner();
	cout << "Welcome to the dice roller module" <<endl; 
	cout << "Please enter the number of dice to be used" <<endl; 
	cin >> nRolls;
	cout << "How many sides does the dice have?" <<endl; 
	cin >> nSide;
	//cout << nRolls << "dice with" << nSide <<endl; Debug comment
	dice myDice(nSide, nRolls);

    myDice.rolldie();
	myDice.print();
	return 0;
}