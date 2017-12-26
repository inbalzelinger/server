//
// Created by inbal on 26/12/17.
//

#ifndef SERVER_SERVERREVERSILOGIC_H
#define SERVER_SERVERREVERSILOGIC_H


#include "TwoClientsGame.h"
#include "CommandManager.h"

#include <vector>

#include <iostream>

using  namespace std;

class ServerReversiLogic {
private:
	vector<TwoClientsGame> gamesList;
	CommandManager commandMannager;
public:
	ServerReversiLogic();
};


#endif //SERVER_SERVERREVERSILOGIC_H
