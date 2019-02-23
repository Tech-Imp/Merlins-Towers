//Flavor.cpp       Stephen Fernandez
//Cpp file containing alternate dialogue
//

#include "flavor.h"

//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
void flavor::nextPlayer(){
	int temp=(rand() % 4)+1;
	switch (temp){
	case 1:
		cout<<"Death chuckles as he moves onto the next victim."<<endl;
		break;
	case 2:
		cout<<"Death, having finished his earl grey, points at the next person."<<endl;
		break;
	case 3:
		cout<<"Death moves menacingly to the next fool."<<endl;
		break;
	case 4:
		cout<<"Death gazes over at his next prey."<<endl;
		break;
	default:
		cout<<"Death is greatly confused!"<<endl;
	}
	
}
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
void flavor::rollSuccess(){
	int temp=(rand() % 10)+1;
	switch (temp){
	case 1:
		cout<<"Death stares vacantly at the rolls, apparently in disbelief."<<endl;
		break;
	case 2:
		cout<<"Death smacks Fate in the back of the head for aiding his victims."<<endl;
		break;
	case 3:
		cout<<"Fate smiles in defiance of Death."<<endl;
		break;
	case 4:
		cout<<"Death is not amused by the outcome of the roll."<<endl;
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		break;
	case 8:
		break;
	case 9:
		cout<<"Fate does a little dance at your good fortune."<<endl;
		break;
	case 10:
		cout<<"Death leers at you and Fate. He shakes his scythe as if to say \"Next time...\" "<<endl;
		break;
	default:
		cout<<"Death is greatly confused!"<<endl;
	}
	
}
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
void flavor::rollFail(){
	int temp=(rand() % 6)+1;
	switch (temp){
	case 1:
		cout<<"Death gives a wicked smile. He knows the end is in sight."<<endl;
		break;
	case 2:
		cout<<"Fate is solemn as Death throws his head back in cruel laughter."<<endl;
		break;
	case 3:
		cout<<"Fate watches helplessly as Death sharpens his scythe."<<endl;
		break;
	case 4:
		cout<<"Death prepares to move in for a killing blow."<<endl;
		break;
	case 5:
		break;
	case 6:
		break;
	default:
		cout<<"Death is greatly confused!"<<endl;
	}
	
}
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
void flavor::pStop(){
	int temp=(rand() % 4)+1;
	switch (temp){
	case 1:
		cout<<"Death smirks. He reminds you that it only delays the inevitable."<<endl;
		break;
	case 2:
		cout<<"Fate gives a sigh of relief. The next roll surely would have been your last."<<endl;
		break;
	case 3:
		cout<<"Death observes the scene quietly. He looks pissed."<<endl;
		break;
	case 4:
		cout<<"Fate flashes a bright and cheery smile to which Death responds with a scowl."<<endl;
		break;
	default:
		cout<<"Death is greatly confused!"<<endl;
	}
	cout<<endl;
}
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
void flavor::win(){
	int temp=(rand() % 4)+1;
	switch (temp){
	case 1:
		cout<<"Death looks at you, cuts his eyes to a slit, and walks away."<<endl;
		break;
	case 2:
		cout<<"Death and Fate exchange a glance. Death sulks away."<<endl;
		break;
	case 3:
		cout<<"Fate cheers for you."<<endl;
		break;
	case 4:
		cout<<"Death holds his scythe at you threateningly. Fate intercedes and forces him away."<<endl;
		break;
	default:
		cout<<"Death is greatly confused!"<<endl;
	}
	cout<<endl;
}
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
void flavor::quit(){
	int temp=(rand() % 5)+1;
	switch (temp){
	case 1:
		cout<<"Death looks at you briefly, takes two steps back and swings his scythe. You are dead."<<endl;
		break;
	case 2:
		cout<<"Fate looks at you with pleading eyes, but Death finishes you off before you can respond."<<endl;
		break;
	case 3:
		cout<<"You look down on your men. No one will know the true story of what happened, for you are dead."<<endl;
		break;
	case 4:
		cout<<"Death bows his head as he walks toward you slowly. A flash of steel is all you see. You are dead."<<endl;
		break;
	case 5:
		cout<<"Death points to something over your shoulder. When you attempt to turn and look, Death aids you in the ";
		cout<<"head turning process. You are dead."<<endl;
		break;
	default:
		cout<<"Death is greatly confused!"<<endl;
	}
	cout<<endl;
}
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
void flavor::bust(){
	int temp=(rand() % 8)+1;
	switch (temp){
	case 1:
		cout<<endl;
		cout<<"Death hurries off to dispatch of your men still on the towers."<<endl;
		break;
	case 2:
		cout<<endl;
		cout<<"You gambled the life of your men. Luck was not with you this time."<<endl;
		break;
	case 3:
		cout<<endl;
		cout<<"Fate looks away as Death \"tends\" to your men."<<endl;
		break;
	case 4:
		cout<<endl;
		cout<<"Death asks you what time is it. Before you can respond, he drops his scythe picks up a rather large ";
		cout<<"mallet and responds \"Hammer Time\". Lets just say your men were not prepared for what happened next. "<<endl;
		break;
	case 5:
		cout<<endl;
		cout<<"Death summons a skeletal violinist, snaps his fingers, and then heads off to the towers. He dispatches your ";
		cout<<"men with cold efficiency while keeping time with the violinist's maddeningly quick tempo."<<endl;
		break;
	case 6:
		cout<<endl;
		cout<<"Death yells as he slowly draws his scythe arm back \"IMMA CHARGIN MAH RAZOR!\" "<<endl;
		cout<<"Your men were ill prepared for the giant flying sythe that dispatched them."<<endl;
		break;
	case 7:
		cout<<endl;
		cout<<"Death points to an odd cat sitting in front of a piano that you did not notice before."<<endl;
		cout<<"As the cat plays its simple jingle, your men fall off the towers. You are quite disturded by ";
		cout<<"the sight."<<endl;
		break;
	case 8:
		cout<<endl;
		cout<<"Death goes to your men and calls for their attention. He waves his hands vehemently until ";
		cout<<"all eyes are on him. He then begins singing into his scythe as cheesy music plays out of nowhere. ";
		cout<<"\"We're no strangers to love, you know the rules and so do I....\" "<<endl;
		cout<<endl;
		cout<<"The following scene was too gruesome to describe...."<<endl;
		break;
	default:
		cout<<"Death is greatly confused!"<<endl;
	}
	cout<<endl;
}
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
void flavor::start(){
	cout<<"In a race to conquer all the land around your kingdom, you run across";
	cout<<" the mythical towers of Merlin. Legend holds that if one is able to capture";
	cout<<" three of the towers, they would gain unimaginable power. However, you are not";
	cout<<" the only one who seems to have come across them. The other rulers of neighboring";
	cout<<" kingdoms have come and also have tried to lay claim."; 
	cout<<endl;
	cout<<endl;
	cout<<"Magical spells guarding the";
	cout<<" towers have knocked you unconscious and separated you from your troops, same as ";
	cout<<"other rulers. When you come to, you see Death, Fate, and the other rulers standing"; 
	cout<<" before you. Death motions to a set of dice which lie before a small pool of water";
	cout<<" in which you see your men and the men of the other nations in conflict before the towers.";
	cout<<" Death motions a second time at the dice, but Fate intercedes and asks....";
	cout<<endl;
	cout<<endl;
	
}
//-------------------------------------------------------------------------
//-------------------------------------------------------------------------
void flavor::exit(){
	cout<<"Death smirks and allows you to wallk away... this time."<<endl;
	cout<<endl;
	cout<<endl;
	cout<<"    However, next time you might not be so lucky...    "<<endl;
	cout<<endl;
	
}