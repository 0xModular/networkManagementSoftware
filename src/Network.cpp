#ifndef SRC_NETWORK_H_
#define SRC_NETWORK_H_

#include "src/Device.h"
#include "src/Connection.h"
#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <cstdlib>
#include <cstdio>

Network(){

    this.timeSinceReset = 0;


}

void refresh(){

    this.getDevices();
    this.getGeneralNetworkDetails();
    this.getCoonections();
    this.timeSinceReset = 0;

}

void getDevices(){

    std::vector<std::tuple<std::string, std::string, std::string>> devices;
    char buffer[256];

    FILE* pipe = _popen("arp -a", "r"); // Execute "arp -a" and capture output

    if (!pipe) {
        std::cerr << "Error running arp -a command." << std::endl;
        return devices;
    }

    std::regex deviceRegex(R"((\d+\.\d+\.\d+\.\d+)\s+([0-9A-Fa-f]+-[0-9A-Fa-f]+-[0-9A-Fa-f]+-[0-9A-Fa-f]+-[0-9A-Fa-f]+-[0-9A-Fa-f]+)\s+(\w+))");

    while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
        std::string line(buffer);
        std::smatch match;

        if (std::regex_search(line, match, deviceRegex)) {
            if (match.size() == 4) {
            	std::string whole = match[0];
                std::string ipv4Address = match[1];
                std::string physicalAddress = match[2];
                std::string type = match[3];

                bool isStatic;
                if (strcmp(type) == "static")
                    isStatic = true;
                else 
                    issStatic = false;

                //ipv4, ipv6, gateway, wired/wireless, flags, ports, static/dynamic, mac
                Device d = new device(ipv4Address, !!!!, !!!!, !!!!, NULL, NULL, isStatic, physicalAddress);
                this.deviceList.add(d);
            }
        }
    }

    _pclose(pipe);
    return devices;
}


void getGeneralNetworkDetails(){


}

void getConnections(){

 while(/*?/*/){
        
        Connection c = new Connection(/*?*/);
        this.connectionList.add(c);

    }

}

void editDevices(Device d, std::string requestType, std::string AdditionalData){

    std::string message;

    //changes dynamic to static and static to dynamic. Additional data is the ip a device should be if its being changed to static.
    if (strcmp(requestType, "changeIpType"){
        message = requestType + " " + AdditionalData;
    }

    //change static ip to a new static ip value
    else if (strcmp(requestType, "changeStaticIP"){
        
        message = requestType + " 0";
    }


    else if (strcmp(requestType, "changeIpType"){

        
    }
    else if (strcmp(requestType, "changeIpType"){

        
    }

	
    // Create a socket
    int netManagerSocket = socket(AF_INET, SOCK_STREAM, 0);

    if (netManagerSocket == -1) {
        std::cerr << "Error creating socket" << std::endl;
        //handle
    }
    
    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(12345);  // Use the same port as the client
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    
    if (connect(netManagerSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == -1) {
    	std::cerr << "Error connecting to network device" << std::endl;
    	close(clientSocket);
    	//handle error;
    }
    
   
   send(clientSocket, message, strlen(message), 0);

        // Receive and display the echoed data
        char buffer[1024];
        std::string bytesRead = recv(netManagerSocket, buffer, sizeof(buffer), 0);
        if (sizeof(bytesRead) > 0) {
            return bytesRead;
        }
        else{}
        	//invalide response
}

void editGeneralNetworkDetails(){


}

void editConnections(){


}
