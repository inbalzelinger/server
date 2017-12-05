#include <iostream>
using namespace std;

#include "Server.h"

int main() {
    Server s(6154);
    try {
        s.start();
    } catch (const char* msg) {
        cout<<msg;
    }
}