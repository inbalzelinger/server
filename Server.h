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

    void handleClient(int clientSocket);
};

#endif //SERVER_SERVER_H
