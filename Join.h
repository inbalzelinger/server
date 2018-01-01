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
    int joiningClientSocket;
public:
    Join(GameManeger *gameManager1, int joiningClientSocket);
    virtual void execute(vector<string> args);

};


#endif //SERVER_JOIN_H
