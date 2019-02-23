//CantStopDice.hpp Dice class header file
//Stephen Fernandez
//
#pragma once
#include "tools.hpp"
#include "dice.hpp"

class CantStopDice : public dice
{
	//data members that can be accessed by all memebers of the class
protected:
	int* pair;			//pairs of rolls
	bool* avail;
	
	public:
	CantStopDice(int nS, int nD) : dice(nS, nD){
		nDice=nD;
		pair=new int[(nD/2)];				//2 pairs 
		avail=new bool[nD];						
		for(int a=0;a<nD;++a){
			avail[a]=true;					//set all dice availability to true
		}		
	}
	
	~CantStopDice(){
	   delete[] pair;
	}
	
	//next are all the prototypes
	int* rolldie();		//returns Pair array
	void print();
	int pairOne(){return pair[0];}
	int pairTwo(){return pair[1];}
};
