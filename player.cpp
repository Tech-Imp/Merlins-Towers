//-------------------------------------
//Player class				player.cpp
//Stephen Fernadez
//-------------------------------------
#include "player.hpp"

//-----------------------------------------------
//----------------Accessor-----------------------

int player::pScore(){return score;}

//------------------------------------------------
//-----------------Accessor-----------------------

cstring player::color(){
    static cstring CNames[7] = {"white", "Red", "Blue", "Yellow", "Green", "Orange", "Purple"};
	return CNames[ pColor ];
}


//-------------------------------------------------
//-------------------------------------------------

void player::print(){
	cout << pName <<" the "<< color() <<" has captured "<< score <<" Tower(s)."<<endl;
	if(score>0){
		cout << pName <<"'s "<< "columns are:";
		for(int m=0; m<score;++m)
			cout << "  "<< captured[m];
		
	}
	cout<<endl;
	if(score>=rtWin){
		cout<< pName <<" the "<< color() << " has won!"<<endl;
	}
}

//-----------------------------------------------
//-----------------------------------------------

bool player::towerCaptured(int tower){
	captured[score]=tower;
	++score;
	//cerr<<"made it to player"<<endl;
	if(score>=rtWin){
	print();
	//cerr<<"returning true for win"<<endl;
	return true;
	}
	//cerr<<"returning false for win"<<endl;
	return false;
}

//-------------------------------------------------
//-------------------------------------------------
//------------------------------------------------
//------------------------------------------------
string player::naming(){
string PLAYERNAME = pName +" the "+color();

return PLAYERNAME;
}
