//
// Created by inbal on 05/12/17.
//

#ifndef SERVER_SERVER_H
#define SERVER_SERVER_H

#include "GameManeger.h"
#include "CommandManager.h"

class Server {

public:

    /**
 * finction name: Server
 * construct server by getting port and command meneger.
 * @param port
 * @param commandManager
 */

    Server(int port ,  CommandManager &commandManager);

    /**
* finction name: start
* open socket to the server, listaning to clients and create the main thread
     * of which accept clients.
*/
    void start();

    /**
* finction name: stop
* close the main server thread, closed the handle clients threads
     * and close the server socket thread.
*/
    void  stop();



private:
    int port;
    int serverSocket;
    pthread_t serverThreadId;
    CommandManager* commandMannager;


};

#endif //SERVER_SERVER_H
