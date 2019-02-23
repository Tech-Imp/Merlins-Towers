//Stephen Fernandez								Main.cpp
//Column n Board module
//

#include "tools.hpp"
#include "clist.h"

int main(void){
	int players=0;
	banner();
	cout << "Welcome to the cirular linked list module." << endl;
	cout<< "Please enter the number of players that will be playing:"<<endl;
	cin >> players;
	
	clist myClist(players);
	
	
	
	myClist.print();
	
	return 0;
	
}

