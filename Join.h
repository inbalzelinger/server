//
// Created by inbal on 26/12/17.
//

#ifndef SERVER_JOIN_H
#define SERVER_JOIN_H


#include "Command.h"
#include "GameManeger.h"

class Join: public Command {
private:
    GameManeger *gameManeger;
public:
    Join(GameManeger *gameManager1);
    void execute(vector<string> args,int joiningClientSocket);

};


#endif //SERVER_JOIN_H
