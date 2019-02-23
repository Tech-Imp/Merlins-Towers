//debugdice.cpp
//Stephen Fernandez
//Part of Polymorphic dice (derivation) example


#include "debugdice.h"
//---------------------------------------------------------------
//---------------------------------------------------------------

int* debugdice::rolldie(){
	int first, second, third, fourth;	
	
	//cerr<<"outside loop"<<endl;
	first=second=third=fourth=0;
	pair[0]=pair[1]=0;
		in >> first >> second >> third >> fourth; 
		cerr << first <<"  "<< second << "  ";
		cerr << third <<"  "<< fourth << "  "<<endl;
	if(!in.eof()){
		temp[0]=first;
		temp[1]=second;
		temp[2]=third;
		temp[3]=fourth;
		
		pair[0]=temp[0]+temp[1];
		pair[1]=temp[2]+temp[3];
		
		cout<<"Pair one "<< pair[0]<< " Pair two " << pair[1]<<endl;
	}
	else{
		cerr <<"No more Dice values, auto values assigned"<<endl;
		pair[0]=2;
		pair[1]=12;
	}
	//cerr<<"end of roll reached"<<endl;
	return pair;
}

//--------------------------------------------------------------
//--------------------------------------------------------------
void debugdice::print(){
	cout << "You request a list of the current rolls and pairs"<<endl;
	
	for(int d=0;d<nDice;++d){
		cout<<"Dice "<< d << " had rolled "<<temp[d]<<endl;
	}
				
	for(int p=0;p<(nDice/2);++p){
		cout<<"Dice pair "<< p <<" was "<< pair[p] <<endl;
	}
	
}
