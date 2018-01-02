//
// Created by inbal on 26/12/17.
//

#include "TwoClientsGame.h"

TwoClientsGame::TwoClientsGame(string name , int clientOne , int clientTwo):gameName(name),
																			playerOne(clientOne) ,
																			playerTwo(clientTwo)  {
	this->isAvailable= true;
}
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
	if(this->playerTwo!=0||this->playerOne!=0){
		this->isAvailable= false;
	}
}
void TwoClientsGame::setPlayerTwo(int clientTwo) {
	this->playerTwo=clientTwo;
	if(this->playerTwo!=0||this->playerOne!=0){
		this->isAvailable= false;
	}
}

bool TwoClientsGame::getIsAvailable() {
	return this->isAvailable;
}
void TwoClientsGame::setIsAvailable(bool status) {
	this->isAvailable=status;
}