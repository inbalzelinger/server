
#include "Server.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <unistd.h>



#include "netinet/in.h"
#define MSGSIZE 7
using  namespace std;
#define MAX_CONNECTED_CLIENTS 10


Server::Server(int port): port(port),serverSocket(0) {}



void Server::start() {
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        throw "ERROR OPENING SOCKET";
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

    socklen_t  clientAddressLen = sizeof((struct sockaddr*)&clientAddress);
    while (true){

        cout<<"waiting for clients connections.."<<endl;
        int clientSocket1 = accept(serverSocket,(struct sockaddr*)&clientAddress,&clientAddressLen);
        if(clientSocket1 == -1) {
            throw "ERROR ON ACCEPT";
        }
        cout<<"client connected"<<endl;

        char  X ='1';
        char O ='2';
        //send 1 to first client
        int n = write(clientSocket1 , &X , sizeof(X));
        if (n == -1) {
        cout<<"error writing to socket"<<endl;
        }
        cout<<"waiting for another player to join"<<endl;

        int clientSocket2 = accept(serverSocket,(struct sockaddr*)&clientAddress,&clientAddressLen);
        if(clientSocket2 == -1) {
            throw "ERROR ON ACCEPT";
        }

		//create tread after the 2ed client had connect


        //send 2 to second client
        cout<<"client connected"<<endl;
        n = write(clientSocket2 , &O , sizeof(X));
        if (n == -1) {
            cout<<"error writing to socket"<<endl;
        }
        //send 1 or 2 again to both clients
		 n = write(clientSocket1 , &X , sizeof(X));
        if (n == -1) {
            cout<<"error writing to socket"<<endl;
        }
        n = write(clientSocket2 , &O , sizeof(O));
        if (n == -1) {
            cout<<"error writing to socket"<<endl;
        }
        bool p1 = true;

        p1 = handleClient(clientSocket1, clientSocket2);

        close(clientSocket1);
        close(clientSocket2);
    }
}



void Server::stop() {
    close(serverSocket);
}



bool Server::handleClient(int clientSocket1,int clientSocket2) {
    char msg[MSGSIZE];
    bool x = false;


	while (true) {

		int n = read(clientSocket1, &msg, sizeof(msg));
        if (n == -1) {
            cout << "Error reading x" << endl;
            return false;
        }
        if (n == 0) {
            cout << "client disconnected" << endl;
            return false;
        }
        n = write(clientSocket2, &msg, sizeof(msg));

        if (n == -1) {
            cout << "Error writing y" << endl;
            return false;
        }

        if (x == true) {
            n = read(clientSocket2, &msg, sizeof(msg));
        }

         n = read(clientSocket2, &msg, sizeof(msg));

        if (n == -1) {
            cout << "Error reading x" << endl;
            return false;
        }
        if (n == 0) {
            cout << "client disconnected" << endl;
            return false;
        }
        n = write(clientSocket1, &msg, sizeof(msg));

        if (n == -1) {
            cout << "Error writing y" << endl;
            return false;
        }


        if (msg[0] != 'N' && msg[1] != 'o') {

            x = true;
            n = read(clientSocket1, &msg, sizeof(msg));
        } else {
            x = false;
        }
    }
}









