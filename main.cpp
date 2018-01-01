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

    CommandManager commandManager;
    GameManeger *gameManeger = new GameManeger;
    Server s(atoi(port.c_str()) , commandManager);

    try {
        s.start();
        cout<<"Ente exit to stop the server"<<endl;
        string str;
        cin>>str;
        if (str == "exit") {
            s.stop();
        }
    } catch (const char* msg) {
        cout<<msg;
    }
}