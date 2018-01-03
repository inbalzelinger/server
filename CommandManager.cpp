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
    this->gameManager = new GameManeger();
	commandsMap["start"] = new StartGame(this->gameManager);
    commandsMap["list_games"] = new ListGames(this->gameManager);
	commandsMap["join"] = new Join(this->gameManager);
}



void CommandManager::executeCommand(string command, vector<string> args) {
    cout<<command<<endl;
    Command* commandObj = commandsMap[command];
    commandObj->execute(args);
}



CommandManager::~CommandManager() {
    map<string,Command*>::iterator it;
    for(it=commandsMap.begin();it!=commandsMap.end();it++){
  //      delete it->second;
    }
  //  delete gameManeger;
}