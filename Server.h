//
// Created by inbal on 05/12/17.
//

#ifndef SERVER_SERVER_H
#define SERVER_SERVER_H

#include "ServerReversiLogic.h"

class Server {

public:
    Server(int port , ServerReversiLogic logic);
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
    ServerReversiLogic logic




};

#endif //SERVER_SERVER_H
