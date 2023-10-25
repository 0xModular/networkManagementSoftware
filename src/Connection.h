/*
 * Connection.h
 *
 *  Created on: Oct 24, 2023
 *      Author: Light
 */

#ifndef SRC_CONNECTION_H_
#define SRC_CONNECTION_H_

class Connection{
	
	public:
	
		static std::vector<Connection> displayConnections();
		
		static bool testConnection(Device d1, Device d2);
		static bool testConnection(Device d1, Device d2, string details);
		
	private:
		
		Connection::Connection();
		Connection::~Connection();
		
		Device device1;
		Device device2;
	
};





#endif /* SRC_CONNECTION_H_ */
