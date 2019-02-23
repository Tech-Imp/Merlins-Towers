//Gamemaster.h Header file
//Stephen Fernandez
//


#pragma once
#include "clist.h"
#include "gameboard.hpp"
#include "CantStopDice.h"
#include "flavor.h"
#include "tools.hpp"
#include "debugdice.h"
#include "TCDice.h"

class gamemaster
{
    private:
	    gameboard* myBoard;
		dice* gamedice;
		clist* cplayers;
		flavor* game; 
		int bLength;
		int bStart;
		//data members that can be accessed by all memebers of the class
	public:
		gamemaster(int nSide,int nDice,int players){
			game=new flavor();
			game->start();
			myBoard= new gameboard(nSide, nDice, players);
			gamedice= new CantStopDice(nSide, nDice);
			cplayers= new clist(players);
			bLength=(nSide*nDice)/2;
			bStart=nDice/2;
		}
		~gamemaster(){}
		//next are all the prototypes
		void play();
		int selection();		//any time a player must make a choice that is meta to the game
								//selection is called
		bool checker();
};