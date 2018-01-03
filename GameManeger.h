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

	/**
* finction name: GameManeger
* construct game manager.
*/
	GameManeger();

	/**
* finction name: inList
* get string name and checks if it in the list of the games.
*@param string - the name of the game
* @return bool.
*/

	bool inList(string game);

	/**
* finction name: addGame
* get two clients game and add it to the list of games.
*@param game.
*/

	void addGame(TwoClientsGame game);

	/**
* finction name: removeGame
* get game name and remove is from the list.
*@param game.
*/

	void removeGame(string name);

	/**
* finction name: TwoClientsGame
* get name of a game and return the twoClientsGame which is called that way.
*@param string - name.
*/

	TwoClientsGame* getGame(string name);

	/**
* finction name: getAvailableGams
* get the list of the avaleble games.
*/

	vector<string>getAvailableGams();

	void SendStopToEveryOne();

};


#endif //SERVER_SERVERREVERSILOGIC_H
