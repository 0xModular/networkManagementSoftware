/*
 * ThisDevice.cpp
 * Created on: Nov 7, 2023
 *
 * Author: Layne
 */

#include "ThisDevice.h"
#include "Connection.h"
#include <regex>
#include <iostream>

ThisDevice::ThisDevice(){

	UpdateAllMembers(GetDefaultAdapater());

}



std::string ThisDevice::GetDefaultAdapater(){


    	char buffer[10000];
    	std::string temp;

    	FILE* pipe = _popen("ipconfig", "r"); //Execute "arp -a" and capture output

    	if (!pipe) {
        	
		//std::cerr << "Error running arp -a command." << std::endl;
    	//handle
    	std::cout << "error ";
		}



    	std::regex deviceRegex(R"([a-zA-Z0-9\-\#\,\%\.\:\s\*\(\)]+\sadapter\s([a-zA-Z0-9\-]+):\s\s\s\s\sConnection\-specific\sDNS\sSuffix[\s\.]+:\s[a-zA-Z0-9\.\-]+\s)");
    	while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
    	    temp += buffer;
    	}
        	
        std::smatch match;

        if (std::regex_search(temp, match, deviceRegex)) {
        	if (match.size() == 2) {
            		
        		std::string whole = match[0];
        		std::string adapter = match[1];

            	std::cout << adapter << "\n";
            	this->defaultAdapter = adapter;
            	return defaultAdapter;
            	
        	}
        	else
        		return "error";

        
		}
        else
        	return "error";
    


}


bool ThisDevice::UpdateAllMembers(std::string adapter){

    	std::string dhcp;
    	std::string whole;
    	std::string temp;

    	std::vector<std::tuple<std::string, std::string, std::string>> devices;
    	char buffer[256];

    	FILE* pipe = _popen("ipconfig /all", "r"); // Execute "arp -a" and capture output
    
	if (!pipe) {
        
		//std::cerr << "Error running arp -a command." << std::endl;
    
	}

    	std::regex deviceRegex(R"(Windows\sIP\sConfiguration\s\s\s\s\sHost\sName[\s\.]+:\s([a-zA-Z0-9\.\(\)\#\-]+)[a-zA-Z0-9\s\.\:\(\)\%\,\-]+[a-zA-Z]+\sadapter\s[a-zA-Z0-9\s\.\:\%\*\#\(\)\,\-]+Connection-specific\sDNS\sSuffix[a-zA-Z0-9\s\.\:\(\)\%\,\-]+Physical\sAddress[\.\s]+:\s([a-fA-F0-9\-]+)\n[a-zA-Z0-9\s\.\:\(\)\%\,\-]+DHCP\sEnabled[\.\s]+:\s([YesNo]+)\n[a-zA-Z0-9\s\.\:\(\)\%\,\-]+IPv6\sAddress[\.\s]+:\s([a-zA-Z0-9\:\%\-]+)[a-zA-Z0-9\s.:\(\)\%\,\-]+IPv4\sAddress[.\s]+:\s([0-9.]+)[a-zA-Z0-9\s.:\(\)\%\,\-]+Default\sGateway[\.\s]+:\s([0-9a-fA-F\%\:\.]+)\s)");
    	while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
    		temp += buffer;
    	}

    	std::cout << "temp" << temp;

        	std::smatch match;

        	if (std::regex_search(temp, match, deviceRegex)) {

			if (match.size() == 7) {
            	
				whole = match[0];
                name = match[1];
                macAddress = match[2];
                dhcp = match[3];
                localIpv6 = match[4];
                localIpv4 = match[5];
                defaultGateway = match[6];

                std::cout << "\n" << name << "\n" << macAddress << "\n" << dhcp << "\n" << localIpv6 << "\n" << localIpv4 << "\n" << defaultGateway << "\n";

                if(dhcp.compare("Yes") == 0) 
					staticIp = false;
				else  
					staticIp = true;

                return true;
			}
        
		}

	return false;

}


std::vector<Connection> ThisDevice::GetConnections(){

	ports.clear();

	std::string whole;
	int localPort;
	std::string remoteAddress;
	int remotePort;
	std::string state;
	int pid;

    char buffer[256];

    FILE* pipe = _popen("netstat -aon", "r"); // Execute "arp -a" and capture output

    if (!pipe) {
        
	//std::cerr << "Error running arp -a command." << std::endl;
	//handle
	}

    std::cout << "wow1";
    std::regex deviceRegex(R"(TCP[\s]+[0-9.]+:([0-9]+)[\s]+([0-9.]+):([0-9])+[\s]+([A-Z_]+)[\s]+([0-9]+))");

    while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
        
		std::string line(buffer);
       	std::smatch match;

        if (std::regex_search(line, match, deviceRegex)) {
            
			if (match.size() == 5) {
                
				whole = match[0];
                localPort = std::stoi(match[1]);
                remoteAddress = match[2];
                remotePort = std::stoi(match[3]);
                state = match[4];
                pid = std::stoi(match[5]);

                Connection *c = new Connection(localPort, remoteAddress, remotePort, state, pid);

                ports.push_back(*c);

                delete c;

			}
        
		}
    
	}

    return ports;

}

bool ThisDevice::setStaticIP(std::string newIp){

    	char buffer[256];

		std::stringstream s;
		s << "netsh interface ipv4 set address name=\"" << this->defaultAdapter << "\" static " << newIp << " " << "255.255.255.0" << " " << this->defaultGateway;

    	FILE* pipe = _popen(s.str().c_str(), "r"); // Execute "arp -a" and capture output

    	if (!pipe) {
			return false;

    	std::regex deviceRegex(R"((\d+\.\d+\.\d+\.\d+)\s+([0-9A-Fa-f]+-[0-9A-Fa-f]+-[0-9A-Fa-f]+-[0-9A-Fa-f]+-[0-9A-Fa-f]+-[0-9A-Fa-f]+)\s+(\w+))");

    	while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
        	
		std::string line(buffer);
        	std::smatch match;

        	if (std::regex_search(line, match, deviceRegex)) {
            		
			if (match.size() == 4) {
            	
				std::string whole = match[0];
                std::string status = match[1];

				if(status.compare("y") == 0){
					if(UpdateAllMember())
						return true;
					else 
						return false
				}
				else
					return false;
				
            		
			}
        	
		}
    	
	}

    _pclose(pipe);
	return false;

}

std::string ThisDevice::GetAllMembers(){

	std::string all = macAddress;
	all += " ";
	all += localIpv4;
	all += " ";
	all += localIpv6;
	all += " ";
	all += name;
	all += " ";

	if(staticIp == true)
		all += "true";
	else
		all += "false";

	all += " ";

	if(defaultAdapter.compare("Ethernet") == 0)
		all += "true";
	else
		all += "false";

	return all;

}

std::string ConnectionVectorToString(){

	int i;
	for(i = 0; i < this->ports.size() - 1; i++){

		

	}



}