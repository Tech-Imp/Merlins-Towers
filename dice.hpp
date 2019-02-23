//Dice.hpp Dice class header file
//Stephen Fernandez
//Need to check on syntax
//
#pragma once
#include "tools.hpp"

class dice
{
protected:				//protected for derived classes and the base to share info
	int nSides;			//data members that can be accessed by all memebers of the class
	int nDice;
	int* rolls;			//need to create a way to connect the part to the class

public:
	dice(int nS, int nD){
		if (nS <= 3){nS=6;}
		if (nD <=0){nD=1;}
		nDice=nD;
		nSides=nS;
		rolls = new int[nDice];
		srand(time(NULL));
	}
	virtual ~dice(){delete[] rolls;}
	//next are all the prototypes
	virtual int* rolldie();
	virtual void print();
	//void Debug(int nSides, int nDice, int roll[]); removed due to redundancy
};