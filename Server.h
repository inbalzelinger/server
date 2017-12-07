//
// Created by inbal on 05/12/17.
//

#ifndef SERVER_SERVER_H
#define SERVER_SERVER_H

class Server {

public:
    Server(int port);
    void start();
    void  stop();

private:
    int port;
    int serverSocket;

    bool handleClient(int clientSocket1, int clientSocket2);
    int getSocket();
};

#endif //SERVER_SERVER_H
