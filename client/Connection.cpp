#include "Connection.h"

Connection::Connection(int lPort, std::string rAddress, int rPort, std::string connectionState, int pid){

		localPort = lPort;
		remotePort = rPort;
		remoteIp = rAddress;
		status = connectionState;
		PID = pid;

}



