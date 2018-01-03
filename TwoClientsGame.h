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

	/**
* function name: getName
* return the name of the game.
* @return string.
*/

	string getName();
	/**
* function name: setPlayerOne
* set the client socket of player one.
* @param clientOne.
*/

	void setPlayerOne(int clientOne);

	/**
* function name: setPlayerTwo
* set the client socket of player two.
* @param clientTwo.
*/
	void setPlayerTwo(int clientTwo);

	/**
* function name: getClientOne
* return the socket of player one
* @return int.
*/
	int getClientOne();

	/**
* function name: getClientTwo
* return the socket of player two.
* @return int.
*/
	int getClientTwo();

	/**
* function name: setIsAvailable
* set the availble field of the game.
* @param status.
*/
	void setIsAvailable(bool status);

	/**
* function name: getIsAvailable
* return true if the game is avalble.
* @return bool.
*/
	bool getIsAvailable();

};


#endif //SERVER_TWOCLIENTSGAME_H
