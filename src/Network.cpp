#ifndef SRC_NETWORK_I_
#define SRC_NETWORK_I_

#include "Network.h"

#include <windef.h>
#include <winsock.h>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <regex>
#include <string>
#include <tuple>
#include <vector>

class ReferenceValidationMechanism;

Network::Network(){

    timeSinceRefresh = 0;

}

void Network::refresh(ReferenceValidationMechanism *r){

    getDevices();
    getGeneralNetworkDetails();
    getConnections();
    timeSinceRefresh = 0;

}

void Network::getDevices(){

    std::vector<std::tuple<std::string, std::string, std::string>> devices;
    char buffer[256];

    FILE* pipe = _popen("arp -a", "r"); // Execute "arp -a" and capture output

    if (!pipe) {
        std::cerr << "Error running arp -a command." << std::endl;
        //manage error
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
                if (type.compare("static") == 0)
                    isStatic = true;
                else 
                    isStatic = false;

                //ipv4, ipv6, gateway, wired/wireless, flags, ports, static/dynamic, mac
                //Device d = new Device(ipv4Address, NULL, NULL, NULL, NULL, NULL, isStatic, physicalAddress);
                //deviceList.push_back(d);
            }
        }
    }

    _pclose(pipe);

}


void Network::getGeneralNetworkDetails(){


}

void Network::getConnections(){

 //while(/*?/*/){
        
        //Connection c = new Connection();
        //connectionList.push_back(c);

    //}

}

void Network::editDevices(Device d, std::string requestType, std::string AdditionalData){

    std::string message;

    //changes dynamic to static and static to dynamic. Additional data is the ip a device should be if its being changed to static.
    if (requestType.compare("changeIpType") == 0){
        message = requestType + " " + AdditionalData;
    }

    //change static ip to a new static ip value
    else if (requestType.compare("changeStaticIp") == 0){
        
        message = requestType + " 0";
    }

	
	char cStringMessage[message.length() + 1]; 
	strcpy(cStringMessage, message.c_str());
	
	
	
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "Failed to initialize Winsock." << std::endl;
        //handle error
    }

    SOCKET clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == INVALID_SOCKET) {
        std::cerr << "Failed to create client socket." << std::endl;
        WSACleanup();
        //handle error
    }

    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1"); // Server IP address
    serverAddress.sin_port = htons(12345); // Server port

    if (connect(clientSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == SOCKET_ERROR) {
        std::cerr << "Connection to the server failed." << std::endl;
        closesocket(clientSocket);
        WSACleanup();
        //handle error
    }

    std::cout << "Connected to the server." << std::endl;

    send(clientSocket, cStringMessage, sizeof(cStringMessage), 0);

    // In a real application, you can have a loop for sending/receiving data.

    closesocket(clientSocket);
    WSACleanup();
}


void Network::editGeneralNetworkDetails(ReferenceValidationMechanism *r){


}

void Network::editConnections(ReferenceValidationMechanism *r){


}

#endif
