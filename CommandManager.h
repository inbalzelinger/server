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
    CommandManager();
    ~CommandManager();
    void executeCommand(string command,vector<string> args);

private:
	GameManeger* gameManeger;
    map<string,Command*> commandsMap;

};


#endif //SERVER_COMMANDMANAGER_H
