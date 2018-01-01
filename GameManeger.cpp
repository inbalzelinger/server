//
// Created by inbal on 26/12/17.
//

#include "GameManeger.h"

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