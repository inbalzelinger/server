#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

#include "Server.h"

int main() {
    string port;

    ifstream inFile;
    /////take of the ../
    inFile.open("settings.txt");
    getline(inFile, port);
    inFile.close();

    Server s(atoi(port.c_str()));

    try {
        s.start();
    } catch (const char* msg) {
        cout<<msg;
    }
}