//
// Created by inbal on 26/12/17.
//

#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include "StartGame.h"


StartGame::StartGame(GameManeger* gameManeger) {
this->gameManeger=gameManeger;
}



 void* StartGame::addNewGame(void* game) {
	TwoClientsGame *twoClientsGame=(TwoClientsGame*)game;
	gameManeger->addGame(*twoClientsGame);
}



void StartGame::execute(vector<string> args) {
	int n;
	TwoClientsGame *twoClientsGame = new TwoClientsGame(args[1],atoi(args[0].c_str()),0);
	if(gameManeger->inList(args[1])) {
		int x = -1;
		n = write(atoi(args[0].c_str()) , &x , sizeof(x));
		if (n == -1) {
			cout<<"error writing to socket"<<endl;
		}
	}

	pthread_t tread;

	n = pthread_create(&tread , NULL , addNewGame, (void*)twoClientsGame);
	if(n) {
		cout<<"Error unable to create thread, "<< n <<endl;
		exit(-1);
	}
	pthread_exit(NULL);
}




