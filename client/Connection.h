/*
 * Connection.h
 * Created on: Nov 7, 2023
 *
 * Author: Layne
 */

#pragma once
#include <string>
#include <vector>

class Connection{
	
	public:
		
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
