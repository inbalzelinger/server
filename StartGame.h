//
// Created by inbal on 26/12/17.
//

#ifndef SERVER_STARTGAME_H
#define SERVER_STARTGAME_H

#include "Command.h"


class StartGame: public Command{
private:
	string name;

public:
	StartGame(string gameName);
	virtual void execute(vector<string> args);
	virtual ~Command(){}
};


#endif //SERVER_STARTGAME_H
