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
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        throw "ERROR OPENNING SOCKET";
    }
    struct sockaddr_in serverAddress;
    bzero((void*)&serverAddress, sizeof(serverAddress));
    serverAddress.sin_family=AF_INET;
    serverAddress.sin_addr.s_addr=INADDR_ANY;
    serverAddress.sin_port=htons(port);



    if (bind(serverSocket,(struct sockaddr*)&serverAddress, sizeof(serverAddress)==-1)) {
        throw "ERROR ON BINDING";
    }

    listen(serverSocket,MAX_CONNECTED_CLIENTS);

    struct  sockaddr_in clientAddress;
    socklen_t  clientAddressLen;
    while (true){
        cout<<"waiting for clients connections.."<<endl;
        int clientSocket=accept(serverSocket,(struct sockaddr*)&clientAddress,&clientAddressLen);
        cout<<"client connected"<<endl;
        if(clientSocket==-1) {
            throw "ERROR ON ACCEPT";
        }
        handleClient(clientSocket);
        close(clientSocket);
    }
}
void Server::stop() {
    close(serverSocket);
}
void Server::handleClient(int clientSocket) {
    cout<<"handleClient"<<endl;
}




