#include<iostream>
#include "../include/RedisServer.h"
#include <thread>
#include<chrono>

using namespace std;

int main(int argc , char* argv[]){
    int port = 6379;
    if(argc > 1){
        port =stoi(argv[1]);
    }

    RedisServer server(port);

    thread persistanceThread([](){
        while(true){
            this_thread::sleep_for(chrono::seconds(300));
            // TODO::dump to database;
        }
    });

    persistanceThread.detach();

    server.run();
    return 0;
}