#include<iostream>
#include "../include/RedisServer.h"

using namespace std;

int main(int argc , char* argv[]){
    int port = 6379;
    if(argc > 1){
        port =stoi(argv[1]);
    }

    RedisServer server(port);

    return 0;
}