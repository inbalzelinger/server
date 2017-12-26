//
// Created by inbal on 26/12/17.
//

#include <iostream>
#include "StartGame.h"




StartGame::StartGame(string gameName) {
	this->name = gameName;
}


void StartGame::execute(vector<string> args) {

	//args[0] the tread name
	//the args[1] will be the thread num


	int n;


	pthread_t identify[5];

	n = pthread_create(args[1] , NULL , newGame, (void*)0);


	if(n) {
		cout<<"Error unable to create thread, "<< n <<endl;
	}

}

void StartGame::~Command(){
	;
}