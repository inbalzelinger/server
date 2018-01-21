//
// Created by inbal on 26/12/17.
//

#include <unistd.h>
#include <cstring>
#include "GameManeger.h"
#define MSGSIZE 20


GameManeger::GameManeger() {
}


void GameManeger::addGame(TwoClientsGame game) {
	if (!this->inList(game.getName())) {
		gamesList.push_back(game);
	}

}

bool GameManeger::inList(string game) {
	for (int i=0;i<gamesList.size();i++) {
		if(gamesList[i].getName()== game) {
			return true;
		}
	}
	return false;
}


void GameManeger::removeGame(string name) {
	for (int i = 0; i < this->gamesList.size(); i++) {
		if (name.compare(gamesList[i].getName()) == 0) {
			gamesList.erase(gamesList.begin() + i );
		}
	}
}

TwoClientsGame *GameManeger::getGame(string name) {
    for (int i = 0; i < this->gamesList.size(); i++) {
        if (name.compare(gamesList[i].getName()) == 0) {
            TwoClientsGame *game = &gamesList[i];
            return game;
        }
    }
}

vector<string> GameManeger::getAvailableGams() {
	vector<string> availableGames;
	for (int i = 0; i < this->gamesList.size(); i++) {
		if (gamesList[i].getIsAvailable()) {
			availableGames.push_back(gamesList[i].getName());
		}
	}
	return availableGames;
}


void GameManeger::SendStopToEveryOne(){
	for (int i = 0; i < this->gamesList.size(); i++) {
		int clientOne=gamesList[i].getClientOne();
		int clientTwo=gamesList[i].getClientTwo();
		char msg[MSGSIZE];
			string exit = "exit";
			strcpy(msg,exit.c_str());
		int n = write(clientOne, &msg, sizeof(msg));

		if (n == -1) {
			cout << "Error writing y" << endl;
			return;
		}
		n = write(clientTwo, &msg, sizeof(msg));
		if (n == -1) {
			cout << "Error writing y" << endl;
			return;
		}
		close(clientOne);
		close(clientTwo);

	}
}

