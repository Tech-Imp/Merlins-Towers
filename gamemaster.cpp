//Gamemaster.cpp Class file
//Stephen Fernandez
//

#include "gamemaster.h"

void gamemaster::play(){
	int option;
	int towercap;
	bool exit=false;										//means of quickly exiting
	//continue game
	//cout<<"start program"<<endl;
	for(;;){
		//continue player
		//cout<<"inside play loop"<<endl;
		for(;;){
			//cout<<"inside player loop"<<endl;
			cout<<endl;
			cout<<endl;
			option=selection();
			bool playertime=true;							//continue on this player?
			bool vmove=true;								//valid move?
			towercap=0;
			cout<<endl;
			switch(option){
				case 1: //call bust
					myBoard->bust(cplayers->whois());		//clear temp loc
					myBoard->pQuit(cplayers->whois());		//clear all positional data/captures
					cplayers->removePlayer();				//remove player
					game->quit();							//call flavor
					playertime=false;						//show turn done
					break;
					
				case 2: //call stop
					towercap=myBoard->stop(cplayers->whois());
					game->pStop();
					playertime=false;
					break;
					
				case 3: //roll then start player
					vmove=checker();
					break;
					
				case 4: //show game stats
					myBoard->printINTEL();
					cout<<endl;
					break;	
					
				case 5:
					myBoard->currentT(cplayers->whois());
					break;
					
				case 6:
					exit=true;
					break;
					
				default:
					cout<< "!!!!Internal error!!!!"<<endl;
			}
			if(playertime==false){
				//cerr<<"!!play has ended, new player starting!!"<<endl;
				break; //go to next player if anything other than roll selected
			}
			if(exit) break;						//quick exit called
			
			if(vmove==false){
				game->bust();
				cout<<"Your men are unable to make any progress."<<endl;
				myBoard->bust(cplayers->whois());
				break;
			}    //go to next player if no moves were valid
			
			//!!!!need to check for win condition and save to variable so that exit status can occur!!!!
		}
		if(exit){
			game->exit();
			break;
		}
		if (towercap>0){
			bool PLAYERWIN=false;
			//add number of columns to player class
			//perform a check to see if the number there is what is needed to end game
			//if so call win and then break
			//cerr<<"something has been capt'd this players turn"<<endl;
			for(int x=bStart;x<=bLength;++x){
				//cerr<<"starting search "<< x <<" the max is"<<bLength<<endl;
				if (myBoard->whoCap(x)!=0){
					if (myBoard->getViewed(x)==false){				//check to make sure tower has not been written
						//cerr<<"player "<<myBoard->whoCap(x)<<endl;//off as captured already
						PLAYERWIN=cplayers->towcap(x);
						myBoard->setViewed(x);
						//cerr<<"DATA FOUND! "<<endl;
					}
				}
			}
			if (PLAYERWIN){
				cout<<endl;
				game->win();
				break;
			}
		}
		//cerr<<"end half-preparing to switch players"<<endl;
		if( cplayers->noPlayer()) break;
		game->nextPlayer();
		cplayers->next();
	}
	myBoard->printINTEL();
	cout<<endl;
	cout<<"The game has ended!"<<endl;
	//!!!!! Need to specify a wait time after print so data is seen !!!!
}
//----------------------------------------------------------------
//----------------------------------------------------------------
int gamemaster::selection(){
	int option=0;
	char choice;
	//options of resign, stay, or roll
	//roll can bust
	//stay saves and changes player
	
	cout<<"What would you like to do "<< cplayers->activePlayer() <<"?"<<endl;
	cout<<"(R) Roll the dice of chance, (S) Stop and stay at current position, "<<endl;;
	cout<<"(X) See current score, (C) See current towers your men are on, "<<endl; 
	cout<<"(G) Give up, (E) Exit Merlin's Towers"<<endl;
	bool valid;
	do{
		valid=false;
		cout<<endl;
		cin >> choice;
		switch(tolower(choice)){
			case 'g':
				valid=true;
				option=1;
				break;
				
			case 's':
				valid=true;
				option=2;
				break;
				
			case 'r':
				valid=true;
				option=3;
				break;
				
			case 'x':	
				valid=true;
				option=4;
				break;
				
			case 'c':
				valid=true;
				option=5;
				break;
				
			case 'e':
				valid=true;
				option=6;
				break;
				
			default:
				cout<< "Death points out your options are limited and that you will have to play on his terms."<<endl;
		}
	}while(valid!=true);
	return option;
}
//-----------------------------------------------------------------
//-----------------------------------------------------------------
bool gamemaster::checker(){
	int fail=0;
	bool invalid;
	int* dpair = gamedice->rolldie();
	cout<<endl;
	for(int x=0;x<2;++x){
		//cout<<dpair[0]<<"  "<<dpair[1]<<endl;
		invalid=false;
		invalid = myBoard->startPlayer(dpair[x],cplayers->whois());
		//cout<<invalid<<endl;
		if(invalid==false){
			++fail;
			game->rollFail();
		}
		else game->rollSuccess();
	}
	//delete[] dpair;
	if(fail>=2){
		return false;
	}
	return true;
}