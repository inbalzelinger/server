//
// Created by inbal on 26/12/17.
//

#include <unistd.h>
#include "ListGames.h"
#define MSGSIZE 100
ListGames::ListGames(GameManeger *gameManager1):gameManager(gameManager1) {}
void ListGames::execute(vector<string> args) {
        int socket = atoi(args[0].c_str());
        vector<string>availableGames=this->gameManager->getAvailableGams();
        char message[MSGSIZE];
        int k=0;
        for (int i = 0; i < availableGames.size(); i++) {
            for (int j = 0; j <availableGames[i].size() ; ++j) {
                message[k]=availableGames[i][j];
                k++;
            }
            message[k]=',';
        }
        int n = static_cast<int>(write(socket, message, MSGSIZE));
        if (n == -1) {
            cout << "Error writing to socket" << endl;
            throw "Error writing to socket";
        }
        close(socket);
    }

