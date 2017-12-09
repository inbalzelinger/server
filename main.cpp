#include <iostream>
using namespace std;

#include "Server.h"

int main() {
    Server s(8014);
    try {
        s.start();
    } catch (const char* msg) {
        cout<<msg;
    }
}