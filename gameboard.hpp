//-------------------------------------------------------------------------
//gameboard.hpp Gameboard class header file
//Stephen Fernandez
//
#pragma once
#include "tools.hpp"
#include "column.h"

class gameboard
	{
		//data members that can be accessed by all memebers of the class
		//int avail;		//Depreciated, look to cstate for availability  	
		int mPlay;			//max players this game (determines depth)
		//int temp;			//location in array of temp storage(!depreciated, Using array slot 0 instead)
		int bStart;			//location of board start
		int max;			//end of board
		column** board;		//connects the array to the class
	public:
		gameboard(int nS=6, int nD=4, int play=4){
			max=nD*nS/2;		//max Number of columns (the number of end column)
			//cout<< max <<" = "<< nD <<" * "<< nS <<endl;
			int tempmax=max+1;		//account for null terminator
			board = new column*[tempmax];
			int depth = play + 1;  //0=temp p1 p2 p3 p4
			mPlay=play;
			int leng=1;			//length of the towers themselves
			//temp=play+1;
			//avail=play+2;
			bStart=nD/2;		// total dice/pairs=location of first column
			int mid = (bStart+max)/2;

			//cerr<<"-----------end of assignments starting creation--------------"<<endl;
			//XXXXX--------------------Seeding the array----------------XXXXXXX
			//XXXXX---------------may need to think about edge cases---XXXXXXXX
			//xxxxx---------depth is length of the array----------------xxxxxxxx
			//xxxxx---------leng is the intial length of the column ----xxxxxxxx
			//xxxxx--------j also establishes column identity-------------xxxxxx  
			for(int j=bStart; j<=max; ++j){
				if(j<=mid){
					leng +=2;
					board[j] = new column(depth, leng, j);
					//cerr<< board[j]->getHeight() <<"col  "<< j <<endl;
					
				}	
				//cerr<<"-----------Intial seed and construct was called----------"<<endl;
				if(j>mid){
					//cerr<<"greater than mid"<<endl;	
					leng -=2;
					board[j] = new column(depth, leng, j);
					//cerr<< board[j]->getHeight() <<"col  "<< j <<endl;
				}
			}	
		}
		~gameboard(){delete[] board;}
		//next are all the prototypes
		void print();								//Print all columns and all player locations within columns
		int state(int col);							//State of column (accessor)
		bool move(int col);							//is tower availabe for capture?
		bool startPlayer(int col, int player);		//Called when ever player uses a combo, store in temp
		int stop(int player);						//Save all prgress and zero out the temp position
		bool isCaptured(int col);					//verify capture of tower
		void printINTEL();							//Intelligent Print prints only non zero data
		void bust(int player);						//Zeros all temp locations and resets tower state
		void currentT(int player);
		int whoCap(int z){return board[z]->getCap();}
		void setViewed(int x){board[x]->setChecked();}
		bool getViewed(int v){return board[v]->getChecked();}
		void pQuit(int player);
	
	};

