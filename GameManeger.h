//
// Created by inbal on 26/12/17.
//

#ifndef SERVER_SERVERREVERSILOGIC_H
#define SERVER_SERVERREVERSILOGIC_H


#include "TwoClientsGame.h"
//#include "CommandManager.h"

#include <vector>

#include <iostream>

using  namespace std;

class GameManeger {
private:
	vector<TwoClientsGame> gamesList;

public:
	GameManeger();
	bool inList(string game);
	void addGame(TwoClientsGame game);
	void removeGame(string name);
	TwoClientsGame* getGame(string name);
	vector<string>getAvailableGams();
};


#endif //SERVER_SERVERREVERSILOGIC_H
