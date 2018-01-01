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
int TwoClientsGame::getClientOne() {
	return this->playerOne;
}
int TwoClientsGame::getClientTwo() {
	return this->playerTwo;
}
void TwoClientsGame::setPlayerOne(int clientOne) {
	this->playerOne=clientOne;
}
void TwoClientsGame::setPlayertwo(int clientTwo) {
	this->playerTwo=clientTwo;
}