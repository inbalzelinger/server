//
// Created by inbal on 05/12/17.
//

#ifndef SERVER_SERVER_H
#define SERVER_SERVER_H

#include "GameManeger.h"
#include "CommandManager.h"

class Server {

public:
    Server(int port);
    void start();
    void  stop();

/**
 * read massage from client 1 and write it to client 2
 * @param clientSocket1
 * @param clientSocket2
 * @return true if game should continue. else-return false.
 */
    bool handleClient(int clientSocket1, int clientSocket2);


private:
    int port;
    int serverSocket;
    CommandManager* commandMannager;





};

#endif //SERVER_SERVER_H
