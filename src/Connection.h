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
		
		bool terminateConnection(ReferenceValidationMechanism *r);
	
		Connection(int lPort, int rPort, std::string rAddress, std::string connectionState, int pid); //Constructor
	    ~Connection(); //Destructor

		int localPort;
		int remotePort;
		std::string remoteIp;
		std::string status;
		int PID;

	private:
		
		//members
		
};
