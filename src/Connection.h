#pragma once
#include <string>
#include <vector>

#include "Device.h"

class Connection{
	
	public:
		
		static bool testConnection(Device d1, Device d2);
		static bool testConnection(Device d1, Device d2, std::string *details);
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






