//----------------------------------------
// Stephen Fernandez            Dice.cpp
// Program 2: dice
//----------------------------------------
// a cpp file is for longer function definitions.
// include only the matching .hpp header

#include "dice.hpp"
//----------------------------------------
int* dice::rolldie() {					//pointer to a dynamic int array
	
	for (int n=0; n<nDice; ){
		rolls[n]=(rand() % nSides)+1;
		++n;
		}
	return rolls;						//useful for later
}

//--------------------------------------------------------------

void dice::print(){
	cout << "The rolls were:"<<endl;
	for (int j=0; j<nDice; ){
		cout << rolls[j] <<"  ";
		++j;
	}
}


