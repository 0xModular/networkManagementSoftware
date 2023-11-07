#include "Connection.h"

#ifndef SRC_CONNECTION_I_
#define SRC_CONNECTION_I_

Connection::Connection(int lPort, std::string rAddress, int rPort, std::string connectionState, int pid){

		localPort = lPort;
		remotePort = rPort;
		remoteIp = rAddress;
		status = connectionState;
		PID = pid;

}



#endif