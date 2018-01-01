//
// Created by inbal on 26/12/17.
//

#ifndef SERVER_TWOCLIENTSGAME_H
#define SERVER_TWOCLIENTSGAME_H


#include <vector>
#include <string>
#include <iostream>

using  namespace std;


class TwoClientsGame {
private:
	string gameName;
	int playerOne;
	int playerTwo;

public:
	TwoClientsGame(string name , int clientOne , int clientTwo);
	string getName();
	void setPlayerOne(int clientOne);
	void setPlayertwo(int clientTwo);
	int getClientOne();
	int getClientTwo();

};


#endif //SERVER_TWOCLIENTSGAME_H
