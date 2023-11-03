#ifndef SRC_NETWORK_I_
#define SRC_NETWORK_I_

#include "Network.h"

#include <cstdio>
#include <memory>
#include <stdexcept>
#include <string>
#include <cstring>
#include <iostream>
#include <regex>
#include <tuple>

#include "ReferenceValidationMechanism.h"

class ReferenceValidationMechanism;

Network::Network(){

	getDevices();
	getGeneralNetworkDetails();
	getConnections();
    timeSinceRefresh = 0;

}

void Network::refresh(ReferenceValidationMechanism *r){

	if (r->checkAuthorization(1)){
    getDevices();
    getGeneralNetworkDetails();
    getConnections();
    timeSinceRefresh = 0;
	}
}

std::vector<Device> Network::getDeviceList(ReferenceValidationMechanism *r){

	if(r->checkAuthorization(1)){
		return deviceList;
	}

}

void Network::getDevices(){

    deviceList.clear();

    char buffer[128];
    std::string result = "";
    FILE* pipe = popen("arp -a", "r");
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
        result += buffer;
    }
    pclose(pipe);

    std::string line(result);
    std::string regex;
    std::regex deviceRegex(R"(([_a-zA-Z0-9]+)\s\(([0-9]+\.[0-9]+\.[0-9]+\.[0-9]+)\)\sat\s([0-9a-fA-F]+:[0-9a-fA-F]+:[0-9a-fA-F]+:[0-9a-fA-F]+:[0-9a-fA-F]+:[0-9a-fA-F]+)\s\[([a-zA-Z0-9]+)\]\son\s([a-zA-Z0-9]+))");

    std::smatch match;
    auto it = line.cbegin();
    while (std::regex_search(it, line.cend(), match, deviceRegex)) {
        std::string name = match[1];
        std::string ipv4Address = match[2];
        std::string macAddress = match[3];
        std::string wiredString = match[4];

        bool wired;
        if (wiredString.compare("ether") == 0)
            wired = true;
        else
            wired = false;

        deviceList.push_back(Device(macAddress, ipv4Address, wired, name));

        it = match[0].second;
    }

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
	
	/*
	
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

    */
}


void Network::editGeneralNetworkDetails(ReferenceValidationMechanism *r){


}

void Network::editConnections(ReferenceValidationMechanism *r){


}

#endif