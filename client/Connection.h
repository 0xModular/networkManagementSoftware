#pragma once
#include <string>
#include <vector>
#include "Device.h"

class Connection{
	
	public:
		
		Connection(int lPort, std::string rAddress, int rPort, std::string connectionState, int pid);
        ~Connection();

	private:
		
		//members
		int localPort;
		int remotePort;
		std::string remoteIp;
		std::string status;
		int PID;
	
};
