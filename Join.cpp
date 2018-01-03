//
// Created by inbal on 26/12/17.
//

#include <unistd.h>
#include <cstdlib>
#include "Join.h"
#include "Play.h"

pthread_mutex_t joinMutex;

void* playGame(void* gameToJoin);

Join::Join(GameManeger *gameManager1 , vector<pthread_t> *threadsVector) {
    this->gameManeger = gameManager1;
    this->threadsVector = threadsVector;
}

 void Join::execute(vector<string> args) {
     TwoClientsGame *gameToJoin;
     int socket = atoi(args[0].c_str());
     if (gameManeger->inList(args[1])) {
         gameToJoin = gameManeger->getGame(args[1]);
     }
     else{
         char x='0';
         int n = write(socket , &x , sizeof(x));
         return;
     }
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
     pthread_t playTread;
     vector<pthread_t> games;
     n = pthread_create(&playTread, NULL, &playGame, (void*)gameToJoin);
     this->threadsVector->push_back(playTread);

     pthread_mutex_lock(&joinMutex);
     games.push_back(playTread);
     pthread_mutex_unlock(&joinMutex);

     if (n) {
         throw "Error creating client accept thread";
     }
}


void* playGame(void* gameToJoin) {
    Play play;
    TwoClientsGame* twoClientsGame=(TwoClientsGame*)gameToJoin;
    play.playGame(*twoClientsGame);
}





