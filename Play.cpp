//
// Created by inbal on 26/12/17.
//

#include <unistd.h>
#include <cstdlib>
#include "Play.h"

#define MSGSIZE 20


Play::Play(TwoClientsGame &twoClientsGame):currentPlay(twoClientsGame) {}


void Play::execute(vector<string> args) {

	char msg[MSGSIZE];

	msg[0] = atoi(args[1].c_str());
	msg[1] = atoi(args[2].c_str());

	bool x = false;
	//	int n = read(this->currentPlay.getPlayerOne(), &msg, sizeof(msg));
	//		if (n == -1) {
	//		cout << "Error reading x" << endl;
	//		return;
	//	}


	int n = write(this->currentPlay.getClientTwo(), &msg, sizeof(msg));
	if (n == -1) {
		cout << "Error writing y" << endl;
		return;
	}

	if (x == true) {
		n = read(this->currentPlay.getClientTwo(), &msg, sizeof(msg));
	}
	n = read(this->currentPlay.getClientTwo(), &msg, sizeof(msg));
	if (n == -1) {
		cout << "Error reading x" << endl;
		return;
	}
	if (n == 0) {
		cout << "client disconnected" << endl;
		return;
	}
	n = write(this->currentPlay.getClientOne(), &msg, sizeof(msg));

	if (n == -1) {
		cout << "Error writing y" << endl;
		return;
	}
}
//		if (msg[0] != 'N' && msg[1] != 'o') {

//			x = true;
//			n = read(clientSocket1, &msg, sizeof(msg));
//		} else {
//			x = false;
//		}
//	}









	//	while (true) {
     //   n = write(clientSocket2, &msg, sizeof(msg));
      //  if (n == -1) {
       //     cout << "Error writing y" << endl;
          //  return false;
      //  }
//        if (x == true) {
//            n = read(clientSocket2, &msg, sizeof(msg));
//        }
//
//         n = read(clientSocket2, &msg, sizeof(msg));
//
//        if (n == -1) {
//            cout << "Error reading x" << endl;
//            return false;
//        }
//        if (n == 0) {
//            cout << "client disconnected" << endl;
//            return false;
//        }
//        n = write(clientSocket1, &msg, sizeof(msg));
//
//        if (n == -1) {
//            cout << "Error writing y" << endl;
//            return false;
//        }
//
//
//        if (msg[0] != 'N' && msg[1] != 'o') {
//
//            x = true;
//            n = read(clientSocket1, &msg, sizeof(msg));
//        } else {
//            x = false;
//        }
//    }







//
//
//(int clientSocket1,int clientSocket2) {
//

//

