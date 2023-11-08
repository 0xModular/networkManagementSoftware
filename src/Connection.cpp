/*
 * Connection.cpp
 * Created on Oct 24, 2023
 *
 * Author: 
 */

#include "Connection.h"


Connection::Connection(int lPort, std::string rAddress, int rPort, std::string connectionState, int pid){

	this->localPort = lPort;
	this->remotePort = rPort;
	this->remoteIp = rAddress;
	this->status = connectionState;
	this->PID = pid;

}
