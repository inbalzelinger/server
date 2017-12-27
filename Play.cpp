//
// Created by inbal on 26/12/17.
//

#include "Play.h"


void Play::execute(vector<string> args) {
;
}


//
//
//(int clientSocket1,int clientSocket2) {
//
//	char msg[MSGSIZE];
//	bool x = false;
//
//
//
//	while (true) {
//
//		int n = read(clientSocket1, &msg, sizeof(msg));
//		if (n == -1) {
//			cout << "Error reading x" << endl;
//			return false;
//		}
//		if (n == 0) {
//			cout << "client disconnected" << endl;
//			return false;
//		}
//
//
//
//
//		n = write(clientSocket2, &msg, sizeof(msg));
//
//		if (n == -1) {
//			cout << "Error writing y" << endl;
//			return false;
//		}
//
//		if (x == true) {
//			n = read(clientSocket2, &msg, sizeof(msg));
//		}
//
//		n = read(clientSocket2, &msg, sizeof(msg));
//
//		if (n == -1) {
//			cout << "Error reading x" << endl;
//			return false;
//		}
//		if (n == 0) {
//			cout << "client disconnected" << endl;
//			return false;
//		}
//		n = write(clientSocket1, &msg, sizeof(msg));
//
//		if (n == -1) {
//			cout << "Error writing y" << endl;
//			return false;
//		}
//
//
//		if (msg[0] != 'N' && msg[1] != 'o') {
//
//			x = true;
//			n = read(clientSocket1, &msg, sizeof(msg));
//		} else {
//			x = false;
//		}
//	}
//}
//
