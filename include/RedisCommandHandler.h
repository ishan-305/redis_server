#ifndef REDIS_COMMAND_HANDLER_H
#define REDIS_COMMAND_HANDLER_H

#include<string>
class RedisCommandHandler{
	public:
		RedisCommandHandler();
		// Has to parse the command from client and send a RESP-formatted response
		std:: string processCommand(const std::string& commandLine);
	};

#endif
