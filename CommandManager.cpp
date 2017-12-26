//
// Created by hadar on 26/12/17.
//

#include "CommandManager.h"
CommandManager::CommandManager() {
}
void CommandManager::executeCommand(string command, vector<string> args) {
    Command* commandObj=commandsMap[command];
    commandObj->execute(args);
}
CommandManager::~CommandManager() {
    map<string,Command*>::iterator it;
    for(it=commandsMap.begin();it!=commandsMap.end();it++){
        delete it->second;
    }
}