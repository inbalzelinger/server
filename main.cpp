#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

#include "Server.h"
#include "GameManeger.h"

int main() {
    string port;
    ifstream inFile;
    /////take of the ../
    inFile.open("../settings.txt");
    getline(inFile, port);
    inFile.close();
    GameManeger *gameManeger = new GameManeger;


    vector<pthread_t> treadsVector;
    CommandManager commandManager(&treadsVector);

    Server s(atoi(port.c_str()) , commandManager , &treadsVector);
    try {
		s.start();

    } catch (const char* msg) {
        cout<<msg;
    }
}