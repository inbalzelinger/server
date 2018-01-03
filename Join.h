//
// Created by inbal on 26/12/17.
//

#ifndef SERVER_JOIN_H
#define SERVER_JOIN_H


#include "Command.h"
#include "GameManeger.h"
#include "Play.h"

class Join: public Command {
private:
    GameManeger *gameManeger;
public:

	/**
* finction name: Join
* construct a join command , getting game managaer.
	 * @param gameManager1 - hold the list of the games.
*/
    Join(GameManeger *gameManager1);

	/**
* finction name: execute
* treat the command join. -if the game exist so join it
 * @param args - hold clients socket and the name of the game to join to.
*/
    void execute(vector<string> args);

};


#endif //SERVER_JOIN_H
