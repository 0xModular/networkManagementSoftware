#ifndef SRC_CONNECTION_H_
#define SRC_CONNECTION_H_

#include <string>
#include <vector>

#include "Device.h"

class Connection{
	
	public:
		
		//public static methods
		static bool testConnection(Device d1, Device d2);
		static bool testConnection(Device d1, Device d2, std::string *details);
	
		//public methods
		
		Connection(Device d1, Device d2);
        ~Connection();

	private:
		
		//members
		int localPort;
		int remotePort;
		std::string remoteIp;
		std::string status;
		int PID;
	
};





#endif /* SRC_CONNECTION_H_ */