//
// Created by inbal on 05/12/17.
//
//
// Created by hadar on 05/12/17.
//

#include "Server.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <unistd.h>
#include "netinet/in.h"


using  namespace std;
#define MAX_CONNECTED_CLIENTS 2

Server::Server(int port): port(port),serverSocket(0) {
}
void Server::start() {

    int X = 1;
    int O = 2;

    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        throw "ERROR OPENNING SOCKET";
    }
    struct sockaddr_in serverAddress;
    bzero((void*)&serverAddress, sizeof(serverAddress));
    serverAddress.sin_family=AF_INET;
    serverAddress.sin_addr.s_addr=INADDR_ANY;
    serverAddress.sin_port=htons(port);



    if (bind(serverSocket,(struct sockaddr*)&serverAddress, sizeof(serverAddress))==-1) {
        throw "ERROR ON BINDING";
    }

    listen(serverSocket,MAX_CONNECTED_CLIENTS);

    struct  sockaddr_in clientAddress;
    socklen_t  clientAddressLen;
    while (true){
        cout<<"waiting for clients connections.."<<endl;
        int clientSocket1 = accept(serverSocket,(struct sockaddr*)&clientAddress,&clientAddressLen);
        if(clientSocket1 == -1) {
            throw "ERROR ON ACCEPT";
        }
        cout<<"client connected"<<endl;

        cout<<"waiting for another player to join"<<endl;

        int clientSocket2 = accept(serverSocket,(struct sockaddr*)&clientAddress,&clientAddressLen);

        if(clientSocket2 == -1) {
            throw "ERROR ON ACCEPT";
        }
        cout<<"client connected"<<endl;


        int n = write(clientSocket1 , &X , sizeof(X));
        if (n == -1) {
            cout<<"error writing to socket"<<endl;
        }
        handleClient(clientSocket1 , clientSocket2);
        close(clientSocket1);

        n = write(clientSocket2 , &O , sizeof(O));
        if (n == -1) {
            cout<<"error writing to socket"<<endl;
        }
        handleClient(clientSocket2 , clientSocket1);
        close(clientSocket2);
    }
}



void Server::stop() {
    close(serverSocket);
}
void Server::handleClient(int clientSocket1,int clientSocket2) {

    int x , y;

    while (true) {
        int n = read(clientSocket1 , &x , sizeof(x));
        if (n == -1) {
            cout<<"Error reading x"<<endl;
            return;
        }
        if (n == 0) {
            cout<<"client disconnected"<<endl;
            return;;
        }

        n = read(clientSocket1 , &y , sizeof(y));
        if (n == -1) {
            cout<<"Error reading y"<<endl;
            return;
        }
        if (n == 0) {
            cout<<"client disconnected"<<endl;
            return;
        }

        n = write(clientSocket2 , &x , sizeof(x));

        if (n == -1) {
            cout<<"Error reading y"<<endl;
            return;
        }

        n = write(clientSocket2 , &y , sizeof(y));

        if (n == -1) {
            cout<<"Error reading y"<<endl;
            return;
        }
    }
}




