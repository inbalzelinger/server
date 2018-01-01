//
// Created by inbal on 26/12/17.
//

#ifndef SERVER_PLAY_H
#define SERVER_PLAY_H


#include "Command.h"
#include "TwoClientsGame.h"
#include <iostream>
using namespace std;

class Play: public Command{


public:
	virtual void execute(vector<string> args);

private:

};


#endif //SERVER_PLAY_H
