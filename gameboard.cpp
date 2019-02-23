//-------------------------------------
//Gameboard class				Gameboard.cpp
//Stephen Fernadez
//-------------------------------------
#include "gameboard.hpp"
#include "column.h"

//-----------------------------------------------
//----------------Accessor-----------------------

//gets the state of a column, normally in header as an accessor
int gameboard::state(int col){return board[col]->getState();}


//-----------------------------------------------
//-----------------------------------------------
void gameboard::print(){
	cout << "Printing out location of all players in all columns (long)"<<endl;
	
	for(int q=1;q<=mPlay;++q){
		cout << "-----------------------------------"<< endl;
		cout << "Player "<< q<< " is in location:"<< endl; 
		for(int m=bStart; m <=max; ++m){
			cout << board[m]->getPos(q) <<" on Tower " << m << endl;
		}
	}
	cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
	for (int k=bStart; k<=max; ++k){
		cout << "Tower " << k << " has " << board[k]->getHeight() << " slots" << endl;
	}
	cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
	for (int k=bStart; k<=max; ++k){
		cout << "Tower " << k << " is " << board[k]->getState() << endl;
	}
}
//------------------------------------------------
//------------------------------------------------
bool gameboard::isCaptured(int col){
	//cerr<< "Checking for capture condition"<<endl; 
	
	int tempLoc = board[col]->getPos(0);
	int cap = board[col]->getHeight();
	if (tempLoc>=cap){return true;}
	else {return false;}
}
//----------------------------------------------
//----------------------------------------------
bool gameboard::move(int col){
	//cerr << "Calling move validity check"<<endl;
	//check number of towers
	int tower=0;
	bool bypass=false;			//used to ensure further movement allowed in already started column
	for (int n=bStart; n <=max; ++n){
		if(board[n]->getPos(0)!=0){
			++tower;
			if(n==col)bypass=true;
		}
	}
	if (board[col]->getState()==pending){
		cout<<"As much as your men wish, they cannot climb any higher on Tower ";
		cout<<col<<". "<<endl;
	return false;}
	
	if (bypass)return true;				//if you have men already on the tower, continue
	
	if (tower>=3){
		cerr<<"You cannot divide your troops to climb more than 3 distinct towers this round."<<endl;
		return false;
	}
	
	//check availability
	if (board[col]->getState()==captured){return false;}
	return true;
}
//-------------------------------------------
//-------------------------------------------
bool gameboard::startPlayer(int col, int player){
	//cerr<<"StartPlayer called"<<endl;
	//check validity then increment
	if (move(col)){
		board[col]->playerMove(player);
		//If the column is valid, update temp, if not print to screen and do nothing
		if(isCaptured(col)){
			//cerr<<"Capture successful"<<endl;
			board[col]->quickUpdate(player);
		}
	}
	else{
		//cerr << "Invalid column" <<endl;
		return false;
	}
	
	return true;
}
//-----------------------------------------
//-----------------------------------------
int gameboard::stop(int player){
	int addtower=0;
	//cerr<<"Stop called"<<endl;
	for(int q=bStart;q<=max;++q){
		if ((board[q]->getPos(player) <= board[q]->getPos(0)) && (board[q]->getPos(0)!=0)){
			bool colcap = false;
			//cerr<<"!!! Temp data  "<< board[q]->getPos(0) <<" for "<< player << " being stored!!!"<<endl;
			colcap=board[q]->stop(player);
			if(colcap){
				//cerr<<"a tower capture has occured at"<< q <<" for "<< player<<endl;
				++addtower;
				board[q]->setCap(player);
			}
			board[q]->bust();
		}
	}
	return addtower;
}
//-----------------------------------------
//-----------------------------------------
void gameboard::printINTEL(){
	cout<<"		Showing all relavent data on players:	"<<endl;
	for(int q=1;q<=mPlay;++q){
		int real=0;
		
		for(int z=bStart; z <=max; ++z){
			if (board[z]->getPos(q)!=0){
				++real;
			}
		}
		if	(real>=1){
			cout << "-----------------------------------"<< endl;
			cout << "Player "<< q<< "'s troops are in location:"<< endl; 
		}
		
		for(int m=bStart; m <=max; ++m){
			if (board[m]->getPos(q)!=0){
				cout << board[m]->getPos(q) <<" of "<< board[m]->getHeight() <<" on Tower " << m;
				if(board[m]->getPos(q)>=board[m]->getHeight()){
					if(board[m]->getState()==captured){
						//called only if this player has win conditions and is flagged for capture
						cout<<" and has captured it!";
					}
					if(board[m]->getState()==pending){
						//will only be called during a random print event...wont appear at an end of a turn.
						cout<<" and is close to capturing it!";
					}
				}
				cout << endl;
			}
		}
	}
	cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
	for (int k=bStart; k<=max; ++k){
		cout << "Tower " << k << " is "; 
		
		switch (board[k]->getState()){
				
			case available:
				cout<< "available." << endl;
				break;
			case pending:
				cout<< "pending capture."<<endl;
				break;
			case captured:
				cout<< "Captured!" << endl;
				break;
			default:
				cout<< "UNKNOWN" << endl;
		}
	}
	
}
//-------------------------------------------------------
//-------------------------------------------------------
void gameboard::bust(int player){
	//cerr<<"Bust called"<<endl;
	for(int q=bStart;q<=max;++q){
		board[q]->bust();
		//board[q]->print();
	}
}
//---------------------------------------------------------
//--------------------------------------------------------
void gameboard::currentT(int player){
	int pos=0;
	
	for(int n=bStart; n <=max; ++n){
		if(board[n]->getPos(0)>0){
			if(board[n]->getPos(0)>board[n]->getPos(player))pos=board[n]->getPos(0);
			else pos=board[n]->getPos(player);
			cout<<"Your men have scaled Tower "<< n <<" to the "<<pos;
			cout<<" out of "<<board[n]->getHeight()<<endl;
		}
	}
	cout<<endl;
}

//-----------------------------------------------------------
//-----------------------------------------------------------
//used to zero out all attacked columns and captured columns
void gameboard::pQuit(int player){
	for(int z=bStart; z<=max; ++z){
		board[z]->quitter(player);
	}
}



