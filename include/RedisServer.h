#ifndef REDIS_SERVER_H
#define REDI_SERVER_H
using namespace std;

#include<string>
#include<atomic>

class RedisServer{
	public:
		RedisServer(int port);
		void run();
		void shutdown();
		
	private:
		int port;
		int server_socket;
		atomic<bool> running;

		void setupSignalHandler();
};

#endif
