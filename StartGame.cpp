//
// Created by inbal on 26/12/17.
//

#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include "StartGame.h"


StartGame::StartGame(GameManeger* gameManeger) {
this->gameManeger = gameManeger;
}



 void* StartGame::addNewGame(void* game) {
	TwoClientsGame *twoClientsGame=(TwoClientsGame*)game;
	gameManeger->addGame(*twoClientsGame);
}



void StartGame::execute(vector<string> args) {
	int n;
	char X='1';
	char O='0';
	TwoClientsGame *twoClientsGame = new TwoClientsGame(args[1],atoi(args[0].c_str()), 0);
	cout<<"start :"<<twoClientsGame->getClientOne()<<endl;
	if(gameManeger->inList(args[1])) {
		n = write(atoi(args[0].c_str()) , &O , 1);
		if (n == -1) {
			cout<<"error writing to socket"<<endl;
		}
	}
	addNewGame(twoClientsGame);
	n = write(atoi(args[0].c_str()) , &X , 1);
//	n = write(atoi(args[0].c_str()) , "1" , 1);
}





