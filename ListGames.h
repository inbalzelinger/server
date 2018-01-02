//
// Created by inbal on 26/12/17.
//

#ifndef SERVER_LISTGAMES_H
#define SERVER_LISTGAMES_H


#include <cstdlib>
#include "Command.h"
#include "GameManeger.h"

class ListGames: public Command {
private:
    GameManeger *gameManager;
public:
    ListGames(GameManeger *gameManager1);
    void execute(vector<string> args);

};


#endif //SERVER_LISTGAMES_H
