#include <iostream>
using namespace std;

#include "Server.h"

int main() {
    Server s(8005);
    try {
        s.start();
    } catch (const char* msg) {
        cout<<msg;
    }
}