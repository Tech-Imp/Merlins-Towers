//CantStopDice.cpp
//Stephen Fernandez
//Part of Polymorphic dice (derivation) example

#include "CantStopDice.h"
//----------------------------------------------------------
//----------------------------------------------------------
int* CantStopDice::rolldie(){
	char options='a';
	char choice='a';
	bool valid;
	dice::rolldie();							//!!Important for using base class fns!!
	
	cout<<"You have thrown in your luck with Fate."<<endl;
	cout<<"It has netted you:"<<endl;
	cout<< '(' << options << ") "<< rolls[0] << "  ";
	avail[0]=true;
	for(int q=1;q<nDice;++q){
		cout<< '(' << ++options << ") "<< rolls[q] << "  ";
		avail[q]=true;
	}
	
	pair[0]=0;
	pair[1]=0;
	for(int c=0;c<2;){
		do{
			valid=false;
			cout<<endl;
			if(c==0)cout<<"Choose one:";
			else cout<<"Now choose another:";
			cin >> choice;
			switch(tolower(choice)){
				case 'a':
					if(avail[0]){
						pair[0]+=rolls[0];
						avail[0]=false;
						valid=true;
						break;
					}
					else{
						cout<<"You cannot choose "<< rolls[0]<< " as it has already been chosen"<<endl;
						break;
					}
					case 'b':
					if(avail[1]){
						pair[0]+=rolls[1];
						avail[1]=false;
						valid=true;
						break;
					}
					else{
						cout<<"You cannot choose "<< rolls[1]<< " as it has already been chosen"<<endl;
						break;
					}
					case 'c':
					if(avail[2]){
						pair[0]+=rolls[2];
						avail[2]=false;
						valid=true;
						break;
					}
					else{
						cout<<"You cannot choose "<< rolls[2]<< " as it has already been chosen"<<endl;
						break;
					}
					case 'd':
					if(avail[3]){
						pair[0]+=rolls[3];
						avail[3]=false;
						valid=true;
						break;
					}
					else{
						cout<<"You cannot choose "<< rolls[3]<< " as it has already been chosen"<<endl;
						break;
					}
					default:
					cout<< "Death reminds you that you can only choose what Fate has alloted you"<<endl;
					
			}
		}while(valid!=true);
		++c;
	}
	for(int z=0;z<nDice;++z){
		if(avail[z]){
			pair[1]+=rolls[z];
		}
	}
	if(pair[0]!=pair[1]){
		cout<<"Your men attempt to advance on Towers "<< pair[0]<< " and " << pair[1]<<endl;
	}
	else{
		cout<<"Your men attempt to focus on Tower "<<pair[0]<<endl;
	}
	return pair;
}

//--------------------------------------------------------
//--------------------------------------------------------
void CantStopDice::print(){
	cout << "You request a list of the current rolls and pairs"<<endl;
	
	for(int d=0;d<nDice;++d){
		cout<<"Dice "<< d <<" had rolled "<<rolls[d]<<endl;
	}
	for(int p=0;p<(nDice/2);++p){
		cout<<"Dice pair "<< p <<" was "<< pair[p] <<endl;
	}
	
}