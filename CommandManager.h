//
// Created by hadar on 26/12/17.
//

#ifndef SERVER_COMMANDMANAGER_H
#define SERVER_COMMANDMANAGER_H


#include <map>
#include "Command.h"
#include "GameManeger.h"

class CommandManager {
public:

	/**
* finction name: CommandManager
* construct command meneger..
*/
    CommandManager();

	/**
* finction name: ~CommandManager
* dstructor.
*/
    ~CommandManager();

	/**
* finction name: executeCommand
* create an object regarding the command
	 * call to execute of the object its created.
*@param command - the command
*@param args - the args of the command (args[0] == client socket.
*/
    void executeCommand(string command,vector<string> args);


	/**
* finction name: getGameManagar
* return the game manager
* @return GameManeger
*/

	GameManeger* getGameManagar();



private:

	GameManeger* gameManager;

    map<string,Command*> commandsMap;

};


#endif //SERVER_COMMANDMANAGER_H
