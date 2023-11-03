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
		std::vector<Device> getConnectionDevices();
		Connection(Device d1, Device d2);
        ~Connection();

	private:
		
		//members
		Device device1;
		Device device2;
	
};





#endif /* SRC_CONNECTION_H_ */