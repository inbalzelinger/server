//
// Created by inbal on 26/12/17.
//

#ifndef SERVER_PLAY_H
#define SERVER_PLAY_H


#include "Command.h"
#include "TwoClientsGame.h"
#include <iostream>
using namespace std;

class Play{

public:
	/**
* function name: playGame
* manage the game itself.
* @param twoClientsGame - the game to play in.
*
*/
	bool playGame(TwoClientsGame &twoClientsGame);


private:
	TwoClientsGame *twoClientsGame;


};


#endif //SERVER_PLAY_H
