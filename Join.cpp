//
// Created by inbal on 26/12/17.
//

#include <unistd.h>
#include <cstdlib>
#include "Join.h"

Join::Join(GameManeger *gameManager1) {
    this->gameManeger=gameManager1;
}

 void Join::execute(vector<string> args) {
     TwoClientsGame *gameToJoin;
     if (gameManeger->inList(args[1])) {
         gameToJoin = gameManeger->getGame(args[1]);
     }
     int socket = atoi(args[0].c_str());
     gameToJoin->setPlayerTwo(socket);
     int clientSocket1=gameToJoin->getClientOne();
     int clientSocket2=gameToJoin->getClientTwo();
     char  X ='1';
     char O ='2';
    //send 1 or 2 again to both clients
     int n = write(clientSocket1 , &X , sizeof(X));
    if (n == -1) {
        cout<<"error writing to socket"<<endl;
    }
    n = write(clientSocket2 , &O , sizeof(O));
    if (n == -1) {
        cout<<"error writing to socket"<<endl;
    }
   close(clientSocket1);
   close(clientSocket2);
}







