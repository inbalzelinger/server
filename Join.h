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
    vector<pthread_t>*  threadsVector;

public:

	/**
* finction name: Join
* construct a join command , getting game managaer.
	 * @param gameManager1 - hold the list of the games.
*/
    Join(GameManeger *gameManager1 ,  vector<pthread_t> *threadsVector);

	/**
* function name: execute
* treat the command list_games. -send the list of the games.
 * @param args - hold client socket
*/

    void execute(vector<string> args);

};


#endif //SERVER_JOIN_H
