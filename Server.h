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


    bool handleClient(int clientSocket1, int clientSocket2);
    int getSocket();
    void sendMove(int clientSocket);

private:
    int port;
    int serverSocket;





};

#endif //SERVER_SERVER_H
