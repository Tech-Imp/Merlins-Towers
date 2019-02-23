// Flavor.h       Stephen Fernandez
//Flavor file for cant stop alteration
//Use: provide a variety of alternate lines
//to make the game more interesting

#pragma once
#include "tools.hpp"

class flavor {
	public:
	flavor(){
		srand(time(NULL));
		}
	~flavor(){}
		
	//next are all the prototypes
	void nextPlayer();
	void rollSuccess();
	void rollFail();
	void pStop();
	void win();
	void quit();
	void bust();
	void start();
	void exit();
};
