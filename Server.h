//
// Created by inbal on 05/12/17.
//

#ifndef SERVER_SERVER_H
#define SERVER_SERVER_H

#include "GameManeger.h"
#include "CommandManager.h"
#include "ThreadPool.h"
class Server {

public:

    /**
 * finction name: Server
 * construct server by getting port and command meneger.
 * @param port
 * @param commandManager
 */

    Server(int port ,  CommandManager &commandManager , vector<pthread_t> *threadsVector);

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
    void  stop(ThreadPool &pool);



private:
    int port;
    int serverSocket;
    pthread_t serverThreadId;
    CommandManager* commandMannager;
    vector<pthread_t>*  threadsVector;

};

#endif //SERVER_SERVER_H
