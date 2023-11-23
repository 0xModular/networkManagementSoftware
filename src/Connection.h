/*
 * Connection.h
 * Created on: Oct 24, 2023
 *
 * Author:
 */

#pragma once
#include <string>
#include <vector>
#include "Device.h"

class Device;

class Connection{
	
	public:
		
		static bool testConnection(Device d1, Device d2);
		static bool testConnection(Device d1, Device d2, std::string *details);
	
		Connection(int lPort, int rPort, std::string rAddress, std::string connectionState, int pid); //Constructor
	    ~Connection(); //Destructor

	private:
		
		//members
		int localPort;
		int remotePort;
		std::string remoteIp;
		std::string status;
		int PID;
	
};
