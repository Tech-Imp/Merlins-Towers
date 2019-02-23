//-------------------------------------------------------------------------
//column.hpp column class header file
//Stephen Fernandez
//
#pragma once
#include "tools.hpp"
#include "main.h"

class column
	{
		static int depth;				// number of players + 1 

		int whoami;						// ID of column
		int max;						// column length
		state cstate;					// column state 
		int* data;						// column positional data temp/p1/p2/p3/p4
		int capturer;					//who captured column?
		bool checked;					//has this column already been accounted for?
		int mPlayers;					//max players playing
		
	public:
		column(int d, int leng, int who){
			if (depth==0) {depth=d;}
			data = new int[depth];
			whoami=who;
			mPlayers=depth-1;
			max=leng;	
			for(int j=0; j <= depth; ++j){
				data[j]=0;
				
			}
			cstate=available;
			capturer=0;
			checked=false;
		}
		~column(){delete[] data;}
		int getPos(int n) {return data[n];}			//one-line get fn. (accessor)
		int getHeight(){return max;}
		int getColumnID(){return whoami;}
		int getState(){return cstate;}
		void setState();							//!!! Backdoor function
		//next are all the prototypes
		void print();								//Print all columns and all player locations within columns
		void quickUpdate(int player);
		void bust();
		bool stop(int player);
		void playerMove(int player);
		//Getters and setters- Used for cross class transfer of info
		void setCap(int player);			
		int getCap(){return capturer;}
		void setChecked(){checked=true;}
		bool getChecked(){return checked;}
		void quitter(int player);						
	};

