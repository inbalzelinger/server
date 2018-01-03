//
// Created by inbal on 26/12/17.
//

#ifndef SERVER_STARTGAME_H
#define SERVER_STARTGAME_H

#include "Command.h"
#include "GameManeger.h"


class StartGame: public Command{
private:
	string name;
	GameManeger *gameManeger;

public:

	/**
* function name: StartGame
* constructor
* @param gameManeger - holds the list of the games.
*/

	StartGame(GameManeger *gameManeger);

	/**
* function name: execute
* treat the command join. -if the game exist so join it
* @param args - hold clients socket and the name of the game to join to.
*/

	void execute(vector<string> args);

	/**
* function name: addNewGame
* tread of game between two clients.
* @param game - the two clients game (the sockets of the clients and the game name.
*/
	void* addNewGame(void* game);

};


#endif //SERVER_STARTGAME_H
