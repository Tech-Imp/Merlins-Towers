//player.hpp --Player class header file
//Stephen Fernadez
//
#pragma once
#include "tools.hpp"
#include "main.h"

class player
	{
		string pName;
		playerColor pColor;
		int score;
		int* captured;
		int rtWin;
	public:
		player(string n="Player", playerColor c=white, int toWin=3){
		// measusre length of n.
		// allocate new array of characters of right length.
		// copy string from n into pname.
			/*int q=strlen(n)+1;
			pName=(char*)malloc(q);
			strcpy(pName,n);*/
		//!!CHANGE 4/27 playerColor is now = to white 	
			pColor=c;
		//pname and pcolor show the difference in string and cstring(no longer the case)
			pName=n;
			score=0;
			captured = new int[toWin];
			rtWin=toWin;
		}
		~player(){ delete[] captured;
			//cout<<"Destroying "<< pName <<endl;
		}
		//Below are prototypes of player
		int pScore();					//accessor
		cstring color();				//accessor		
		void print();					//typical print function
		bool towerCaptured(int tower);	//declares tower capture and gives the tower	
		string naming();				//returns the proper name of player
	};
