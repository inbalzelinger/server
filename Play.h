//
// Created by inbal on 26/12/17.
//

#ifndef SERVER_PLAY_H
#define SERVER_PLAY_H


#include "Command.h"

class Play: public Command{


public:
	Play();
	virtual void execute(vector<string> args);

};


#endif //SERVER_PLAY_H
