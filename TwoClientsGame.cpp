//
// Created by inbal on 26/12/17.
//

#include "TwoClientsGame.h"

TwoClientsGame::TwoClientsGame(string name , int clientOne , int clientTwo):gameName(name),
																			playerOne(clientOne) ,
																			playerTwo(clientTwo)  {}
string TwoClientsGame::getName() {
	return this->gameName;
}

int TwoClientsGame::getPlayerOne() {
	return this->playerOne;
}
int TwoClientsGame::getPlayerTwo() {
	return this->playerTwo;
}
