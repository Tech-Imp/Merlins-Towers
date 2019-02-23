//clist header file			clist.h
//Stephen Fernandez
//
#pragma once
#include "tools.hpp"
#include "cell.h"
#include "main.h"

class clist
	{
		int counter;
		cell* head;
		bool lacking;
		cell* finger;						//holds onto cell for deletion
		cell* temp;							//holds onto cell pointer
		cell* current;
		bool* aColor;						//array to store color availablity
		char name[30];
		
	public:
		clist(int players){
			counter=players;
			lacking=false;
			aColor = new bool[7];
			int who=1;
			
			for (int t=0; t<=6; ++t){
				aColor[t]=true;
				//cout << t << endl; 
			}
			setName();
			playerColor color= setColor();
			head=new cell(true,name,who,color);			//creates head pointer
			head->next=head;				// sets tail pointer to self
			
			for (int j=1; j<players; ++j){
				setName();
				playerColor color=setColor();
				++who;
				head->next = new cell(false, name,who,color, head->next); //create next object
				//point at head and point tail at new obj
			}
			current=head;
		}
		
		~clist(){ 
		    cout<<" List destructor called. "<<endl;
			for (int x=0; x<counter; ++x){
				///the error lies somewhere within the pointers
				cout<<"!!player removed"<<endl;
				delete current->info;
				temp=current->next;
				delete current;
				cout<<"!!cell removed"<<endl;
				current=temp;
			}
		} 
		
		//next are all the prototypes
		bool noPlayer();				//useful for getting LACKING_PLAYER state
		void setName();
		playerColor setColor();
		void removePlayer();
		void next();
		void print();
		cstring toString(playerColor pc);
		int whois(){return current->who();}
		string activePlayer(){return current->name();}
		//passing tower cap below
		bool towcap(int tower){
		//cerr<<"made it to clist.h with "<< tower <<endl;
		return current->cap(tower);}
	};

// Need to take care of the infinite loop that occurs from invalid input in
// the choice of player color
