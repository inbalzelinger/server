//
// Created by inbal on 26/12/17.
//

#include <unistd.h>
#include <sys/socket.h>
#include "Join.h"

Join::Join(GameManeger *gameManager1,int joiningClientSocket) {
    this->gameManeger=gameManager1;
    this->joiningClientSocket=joiningClientSocket;
}

 void Join::execute(vector<string> args) {
     TwoClientsGame *gameToJoin;
     if (gameManeger->inList(args[1])) {
         gameToJoin = gameManeger->getGame(args[1]);
     }
     gameToJoin->setPlayertwo(this->joiningClientSocket);
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







