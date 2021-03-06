//
// Created by hadar on 26/12/17.
//

#include "CommandManager.h"
#include "ListGames.h"
#include "StartGame.h"
#include "Join.h"

CommandManager::CommandManager(vector<pthread_t> *threadsVector) {

    this->gameManager = new GameManeger();
	commandsMap["start"] = new StartGame(this->gameManager);
    commandsMap["list_games"] = new ListGames(this->gameManager);
	commandsMap["join"] = new Join(this->gameManager ,  threadsVector);
}




void CommandManager::executeCommand(string command, vector<string> args) {
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


GameManeger* CommandManager::getGameManagar() {
	return this->gameManager;
}
