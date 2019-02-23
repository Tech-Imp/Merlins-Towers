//TCdice.hpp Dice class header file
//Stephen Fernandez
//
#pragma once
#include "tools.hpp"
#include "CantStopDice.h"


class TCDice: public CantStopDice
	{
		//data members that can be accessed by all memebers of the class
		int* pair;			//pairs of rolls
		int* temp;			//temp storage of roll array (whole)
		int nDice;
		int nSides;
		
	public:
		TCDice(int nS=6, int nD=4):CantStopDice(nS, nD){
			
			cout<<"!Specialized Test Dice being used!"<<endl;
			nDice=nD;
			nSides=nS;
			pair=new int[(nD/2)];				//2 pairs 
			temp=new int[nD];					//four dice total typically
			
			
		}
		~TCDice(){}
		//next are all the prototypes
		int* rolldie();
		void print();
	};
