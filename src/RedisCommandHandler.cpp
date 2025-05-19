#include"../include/RedisCommandHandler.h"
#include <vector>
#include<string>
#include<iostream>
#include<sstream>
using namespace std;

//Need to parse command using RESP Protocol
//has to write handler functions for different command 

vector<string> parseRESPCommand(const string& input ){
    vector<string> tokens;
    if(input.empty()) return tokens;
    
    if(input[0] != '*'){
        //check and separate based on whitespaces
        istringstream iss(input);
        string token;

        while(iss >> token){
            tokens.push_back(token);
        }

        return tokens;
    }

    
}
