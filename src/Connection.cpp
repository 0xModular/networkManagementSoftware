/*
 * Connection.cpp
 * Created on Oct 24, 2023
 *
 * Author: Layne
 */

#include "Connection.h"


Connection::Connection(int lPort, int rPort, std::string rAddress, std::string connectionState, int pid){ //Constructor{

	this->localPort = lPort;
	this->remotePort = rPort;
	this->remoteIp = rAddress;
	this->status = connectionState;
	this->PID = pid;

}

Connection::~Connection(){
	
}
