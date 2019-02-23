//Stephen Fernandez
//Cell header file cell.hpp
//
#pragma once
#include "tools.hpp"
#include "player.hpp"
#include "main.h"


class cell {
	friend class clist;		//Friend for indirectly related info sharing
		player* info;		//connects the Player to the class
		cell* next; 
		bool bHead;
		int whoami;
	public:
		cell(bool isHead=false, string n=" ", int w=0 ,playerColor c=white, cell* p=NULL){
			//cout<<"cell called"<<endl;
			/*cout<< "Please enter a name:"<<endl;
			cin >> ws;
			cin.get(pName,30);
			
			cout << "Now enter a color:"<<endl;
			cin >> ws;
			cin.get(color, 10);*/
			
			info = new player(n, c);
			whoami=w;
			next=p;
		}
		
		~cell(){}
		
		//next are all the prototypes
		int who(){return whoami;}
		string name(){return info->naming();}
		bool cap(int towerN){
		//cerr<<"made it to cell with "<<towerN<<endl;
		return info->towerCaptured(towerN);}
};

