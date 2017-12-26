//
// Created by hadar on 26/12/17.
//

#include "CommandManager.h"
#include "ListGames.h"
#include "StartGame.h"
#include "Play.h"
#include "Close.h"
#include "Join.h"

CommandManager::CommandManager() {

	commandsMap["start"] = new StartGame("kkk");

	commandsMap["listGames"] = new ListGames();

	commandsMap["join"] = new Join;

	commandsMap["play"] = new Play;

	commandsMap["close"] = new Close;

}



void CommandManager::executeCommand(string command, vector<string> args) {

    Command* commandObj = commandsMap[command];

    commandObj->execute(args);
}



CommandManager::~CommandManager() {
    map<string,Command*>::iterator it;
    for(it=commandsMap.begin();it!=commandsMap.end();it++){
        delete it->second;
    }
}