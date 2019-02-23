//Stephen Fernandez
//clist class file			clist.cpp
//
//

#include "clist.h"

//-------Accessor--------------------------------------
//------------------------------------------------------
bool clist::noPlayer(){
	if (counter <=1){lacking=true;} 
	return lacking;						//detects forfeit situation
}
//------------------------------------------------------
//-------------------------------------------------------
void clist::removePlayer(){
	temp=current->next;
	finger=current;
	if (current->bHead){
		head=current->next;
	}
	for(int m=1; m<counter;++m){
		next();		// move current around circle.
	}
	current->next=temp;
	--counter;
	delete finger->info;
	delete finger;
}
//-------------------------------------------------------
//-----------------------------------------------------
void clist::next(){
	//cerr<<"Next item"<<endl;
	current=current->next;							//goes to next item in list
}

//------------------------------------------------------
//---------------------------------------------------------
void clist::print(){
	cout<<"There are " << counter << " players playing at the moment."<<endl;
	
}
//---------------------------------------------------------
//------------------------------------------------------
void clist::setName(){
	cout<< "What is your name?  ";
	cin >> ws;
	cin.get(name,30);
	cout<<endl;	
}
//-------------------------------------------------------
//-----------------------------------------------------------
playerColor clist::setColor(){
	playerColor temp=white;
	int colorNum=0;
	bool valid = false;
	
	cout << "And from what country do you hail?"<<endl;
	for(int h=1; h<=6; ++h){
		//cout << h <<"  ";
		if(aColor[h]==true){
			cout<<"Press " << h << " for " << toString((playerColor)h) <<endl;
			//toString is throwing an exception with being passed an int rather than a playercolor enum
			//could casting work? no...need exception handling of some sort
			//need to thing of alternatives to have means of display
		} 
	}		
	//cerr<< "outside "<< temp << " "<< colorNum <<endl;
	do{
		cin	>> colorNum;	
		//cerr<< endl;
		//cerr<<colorNum<<" set?"<<endl;
		if(!cin.good()){
			//cerr<<"tester"<<endl;
			cin.clear();
			cin.ignore(255,'\n');
		}
		//cerr<< "number input is "<< colorNum<< endl;
		switch(colorNum) {
				/*case 0:
				 cerr <<"!!!!data error!!!!"<<endl;
				 cerr <<"re-enter a color"<<endl;
				 break;*/
			case 1:
				if(aColor[1]){
					temp=Red;
					valid=true;
					cerr<<"The country of the Fiery flame, you tell Fate."<< endl;
					aColor[1]=false;
				}
				else{
				    cout<< "Someone is already from that country. Please reselect." << endl;
				}		
				break;
				
				case 2:
				if(aColor[2]){
					temp=Blue;
					valid=true;
					cerr<<"The country of the Ocean's blue, you tell Fate."<< endl;
					aColor[2]=false;
				}
				else{
					cout<< "Someone is already from that country. Please reselect." << endl;
				}
				break;
				
				case 3:
				if(aColor[3]){
					temp=Yellow;
					valid=true;
					cerr<<"The country of the Yellow sun, you tell Fate."<< endl;
					aColor[3]=false;
				}
				else{
					cout<< "Someone is already from that country. Please reselect." << endl;
				}
				break;
				
				case 4:
				if(aColor[4]){
					temp=Green;
					valid=true;
					cerr<<"The country of the Verdant Forest, you tell Fate."<< endl;
					aColor[4]=false;
				}
				else{
					cout<< "Someone is already from that country. Please reselect." << endl;
				}
				break;
				
				case 5:
				if(aColor[5]){
					temp=Orange;
					valid=true;
					cerr<<"The country of the Orange plains, you tell Fate."<< endl;
					aColor[5]=false;
				}
				else{
					cout<< "Someone is already from that country. Please reselect." << endl;
				}
				break;
				
				case 6:
				if(aColor[6]){
					temp=Purple;
					valid=true;
					cerr<<"The country of the Indigo skies, you tell Fate."<< endl;
					aColor[6]=false;
				}
				else{
					cout<< "Someone is already from that country. Please reselect." << endl;
				}
				break;
				
				default: cout<< "That is not a country I recognize, Fate tells you. ";
				cout<<"Please try again."<<endl;
				valid=false;
				//need to clear buffer
				break;
		}
	} while(valid != true);
	return temp;
}


//---------------------------------------------
//--------------------------------------------
cstring clist::toString(playerColor pc){
    static cstring CNames[7] = {"white", "Red", "Blue", "Yellow", "Green", "Orange", "Purple"};
	return CNames[ pc ];
}
