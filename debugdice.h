//Debugdice.hpp Dice class header file
//Stephen Fernandez
//
#pragma once
#include "tools.hpp"
#include "CantStopDice.h"
#define roller "roller.txt" 

class debugdice: public CantStopDice
	{
		//data members that can be accessed by all memebers of the class
		ifstream in;
		int* temp;				//used for temporary storage btw file & pair
	public:
		debugdice(int nS=6, int nD=4):CantStopDice(nS, nD){
			temp=new int[nD];
			cout<<"!Test Dice being used!"<<endl;
			in.open(roller);				
			if(!in){
				cout<<"Unable to open file!"<<endl;
				fatal("exiting...");
			}
			cout<<"file exists!"<<endl;
		}
		~debugdice(){}
		//next are all the prototypes
		int* rolldie();
		void print();
	};
