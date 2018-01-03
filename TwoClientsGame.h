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
	bool isAvailable;

public:

	/**
* function name: TwoClientsGame
* constructor.
* @param name - gameName
* @param clientOne - client one socket.
* @param clientTwo - client two socket.
*/

	TwoClientsGame(string name , int clientOne , int clientTwo);
	string getName();
	void setPlayerOne(int clientOne);
	void setPlayerTwo(int clientTwo);
	int getClientOne();
	int getClientTwo();
	void setIsAvailable(bool status);
	bool getIsAvailable();

};


#endif //SERVER_TWOCLIENTSGAME_H
