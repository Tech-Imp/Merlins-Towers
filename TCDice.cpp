//TCDice.cpp
//Stephen Fernandez
//Part of Polymorphic dice (derivation) example


#include "TCDice.h"
//---------------------------------------------------------------
//---------------------------------------------------------------

int* TCDice::rolldie(){
	int buffer=0;
	for(int x=0;x<=1;){
		cout<<"Enter Dice pair "<< x << " value "<<endl;
		cin>>buffer;
		if(buffer>=2 && buffer<=12){
			pair[x]=buffer;
			++x;
		}
	}
	cout<<"Pair one was "<<pair[0]<< "   Pair two was "<<pair[1]<<endl;
	return pair;
}

//--------------------------------------------------------------
//--------------------------------------------------------------
void TCDice::print(){
	cout << "You request a list of the current rolls and pairs"<<endl;
	
	for(int d=0;d<nDice;++d){
		cout<<"Dice "<< d << " had rolled "<<temp[d]<<endl;
	}
				
	for(int p=0;p<(nDice/2);++p){
		cout<<"Dice pair "<< p <<" was "<< pair[p] <<endl;
	}
	
}
