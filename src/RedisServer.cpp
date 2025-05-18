#include "../include/RedisServer.h"
#include<iostream>
#include<signal.h>
#include<sys/socket.h>
#include<unistd.h>
#include <netinet/in.h>

using namespace std;

static RedisServer* globalServer = nullptr;

void terminatesignalHandler(int signum){
    if(globalServer){
        cout << "\n Signal Caught" << signum << ", Shutting Down....\n";
        globalServer->shutdown();
    }
    exit(signum);
}

RedisServer::RedisServer(int port) : port(port), server_socket(-1), running(false){
    globalServer = this;
    setupSignalHandler();
}

void RedisServer:: setupSignalHandler(){
    signal(SIGINT , terminatesignalHandler);
}

void RedisServer :: run(){
    server_socket = socket(AF_INET , SOCK_STREAM , 0);

    if(!server_socket){
        cerr << "Error Creating Server Socket \n";
        return;
    }
    //setup for reusing without time delay
    int opt = 1;
    setsockopt(server_socket , SOL_SOCKET , SO_REUSEADDR , &opt , sizeof(opt));

    sockaddr_in serverAddr{};
    // can use memset but legacy way error prone 

    serverAddr.sin_port = htons(port);
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    int bindSoc = bind(server_socket , (struct sockaddr *) &serverAddr , sizeof(serverAddr));
    if( bindSoc <0){
        cerr << "Error Binding Socket \n";
        return ;
    }
    int SocListen = listen(server_socket , 10);
    if(SocListen <0){
        cerr << "Unable to listen on Server Socket" ;
        return ;
    }

    cout << "Redis Server Listening on Port" << port << "\n";

}

void RedisServer::shutdown(){
    running = false;
    if(server_socket != -1){
        close(server_socket); //after saving db to disk
    }
    cout << "Server Shutdown Done \n";
}