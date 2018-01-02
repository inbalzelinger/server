//
// Created by inbal on 26/12/17.
//

#include <unistd.h>
#include <cstdlib>
#include <sstream>
#include "Play.h"

#define MSGSIZE 20



void Play::execute(vector<string> args) {
	char msg[MSGSIZE];



	//the x and y is in args[2]

	istringstream str(args[2]);
	string x;
	string y;

	string tmp;
	stringstream ss;

	getline(str, x, ' ');
	getline(str, y, ' ');

	const char *xchar = x.c_str();
	msg[0] = *xchar;

	cout << msg[0];

	const char *ychar = x.c_str();
	msg[1] = *ychar;
	cout << msg[1];

	int player1Socket = atoi(args[0].c_str());
	int player2Socket = atoi(args[1].c_str());
	bool check = false;

	int n = write(player2Socket, &msg, sizeof(msg));
	if (n == -1) {
		cout << "Error writing the move to player 2" << endl;
		return;
	}
	n = read(player2Socket, &msg, sizeof(msg));
	if (n == -1) {
		cout << "Error reading x" << endl;
		return;
	}
	if (n == 0) {
		cout << "client disconnected" << endl;
		return;
	}
}








