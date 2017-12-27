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
	StartGame(GameManeger *gameManeger);
	virtual void execute(vector<string> args);
	void* addNewGame(void* game);

};


#endif //SERVER_STARTGAME_H
