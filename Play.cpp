//
// Created by inbal on 26/12/17.
//

#include <unistd.h>
#include <cstdlib>
#include <sstream>
#include "Play.h"

#define MSGSIZE 20


bool Play::playGame(TwoClientsGame &twoClientsGame1) {
	char msg[7];
	bool x = false;
	int clientSocket1=twoClientsGame1.getClientOne();
	int clientSocket2=twoClientsGame1.getClientTwo();
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









