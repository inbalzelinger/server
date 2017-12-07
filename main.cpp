#include <iostream>
using namespace std;

#include "Server.h"

int main() {
    Server s(8013);
    try {
        s.start();
    } catch (const char* msg) {
        cout<<msg;
    }
}