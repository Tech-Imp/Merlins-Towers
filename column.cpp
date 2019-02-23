//-------------------------------------
//Column class				column.cpp
//Stephen Fernadez
//-------------------------------------

#include "column.h"
int column::depth=0;

//-----------------------------------
void column::print(){
	
	cout << "current state of "<< whoami <<" is " << cstate <<endl;
} 
//------------------------------------------------
//------------------------------------------------
void column::quickUpdate(int player){
	//cerr<<"A quick update has been called"<<endl;
	cstate=pending;
	cout<<"Tower "<< whoami <<" is close to being captured."<<endl;
}
//-----------------------------------------------
//-----------------------------------------------
void column::bust(){
	//cerr<<"Player has gone bust"<< endl;
	
	data[0]=0;	
	if (cstate==pending){ 
		cstate = available;
		cout<<"You were poised to capture Tower "<< whoami;
		cout<<"but you pushed your luck."<<endl;
	}
	
}

//----------------------------------------------
//----------------------------------------------
bool column::stop(int player){
	data[player]=data[0];
		//cerr<<"in stop"<<endl;
	if (cstate==pending){ 
	cstate=captured;
	cout<<"Tower "<< whoami <<" has been captured!"<<endl;
	return true;
	}
	return false;
}
//----------------------------------------------
//----------------------------------------------
void column::playerMove(int player){

	if(data[player]>data[0]){	
		data[0]=data[player]+1;
	}
	else{data[0] +=1;}
	
}	

//---------------------------------------------
//---------------------------------------------
//used for debug purposes only
void column::setState(){
	if (cstate==pending){
		cout<<"state changed"<<endl;
		cstate = captured;
	}
}

//--------------------------------------------
//--------------------------------------------
void column::setCap(int player){
capturer=player;
//remove other players from consideration from capped tower
	for(int x=1;x<=mPlayers;++x){
		if(x!=player){
			data[x]=0;
		} 
	}
}
//---------------------------------------------
//---------------------------------------------
void column::quitter(int player){
	if(capturer==player){
		cstate=available;
		data[player]=0;
	}
	
}