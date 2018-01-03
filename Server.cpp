
#include "Server.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <unistd.h>
#include <sstream>


static void* handleClient(void *clientSocketAndMeneger);
static void* acceptClients(void* serverSocket);


#define MSGSIZE 20
using  namespace std;
#define MAX_CONNECTED_CLIENTS 10


Server::Server(int port , CommandManager &comandMng): port(port),serverSocket(0), commandMannager(&comandMng)
, serverThreadId(0) {}


struct SocketAndManager {
	int socket;
	CommandManager* cmd;
};



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
	struct SocketAndManager* data = new struct SocketAndManager;
	data->socket = serverSocket;
	data->cmd = commandMannager;
	cout<<"Enter exit to stop the server"<<endl;

	pthread_create(&serverThreadId, NULL, &acceptClients, (void*)data);
	string str;
	cin>>str;
	if (str == "exit") {
		this->stop();
		return;
	}
	pthread_join(serverThreadId , NULL);
	pthread_exit(NULL);
}



void Server::stop() {
	pthread_cancel(serverThreadId);
	pthread_join(serverThreadId , NULL);




    close(serverSocket);
	cout<<"server Stoped"<<endl;
}




void*acceptClients(void* serverSocket) {
	vector<pthread_t> threads;
		struct sockaddr_in clientAddress;
		socklen_t clientAddressLen = {};
	while (true) {
	cout << "waiting for clients connections.." << endl;
		struct SocketAndManager* serverData = (struct SocketAndManager*)serverSocket;
		int clientSocket1 = accept(serverData->socket, (struct sockaddr*) &clientAddress, &clientAddressLen);
		if (clientSocket1 == -1) {
			throw "ERROR ON ACCEPT";
		}
		cout << "client connected" << endl;
		struct SocketAndManager* clientData = new SocketAndManager;
		clientData->socket = clientSocket1;
		clientData->cmd = serverData->cmd;
		pthread_t tread;
        cout<<clientData->socket<<endl;

		pthread_create(&tread, NULL, &handleClient, (void*)clientData);
		threads.push_back(tread);
        for (int i = 0; i < threads.size(); i++) {
            pthread_join(threads[i], NULL);
         }
	}
}




void* handleClient(void *clientSocketAndMeneger) {
    char msg[MSGSIZE];
	struct SocketAndManager* clientData = (struct SocketAndManager*)clientSocketAndMeneger;
    cout<<clientData->socket;
	int n = read(clientData->socket, &msg, MSGSIZE);
        if (n == -1) {
            cout << "handle: Error reading x" << endl;
            return false;
        }
        if (n == 0) {
            cout << "client disconnected" << endl;
            return false;
        }
        cout<<msg<<endl;
        istringstream str(msg);
        string commandName;
        string tmp;
        stringstream ss;
        ss<<clientData->socket;
        string socket = ss.str();
        vector<string> commandArgs;
        commandArgs.push_back(socket);
        getline(str , commandName ,' ');
        while (getline(str , tmp ,' ')) {
            commandArgs.push_back(tmp);
        }
	clientData->cmd->executeCommand(commandName , commandArgs);
    return NULL;
}





