/*
 * Device.cpp
 * Created on: Oct 24, 2023
 *
 * Author:
 */


#include "Device.h"

Device::Device(std::string mac, std::string IPv4, bool wiredConnection, std::string deviceName){

	this->name = deviceName;
	this->localIpv4 = IPv4;
	this->wired = wiredConnection;
	this->macAddress = mac;
	this->limitedMembers = true; 

}

std::string Device::GetIpv4(ReferenceValidationMechanism *r){

	if(r->CheckAuthorization(1)){

		return this->localIpv4;

	}

}

std::string Device::GetMac(ReferenceValidationMechanism *r){

	if(r->CheckAuthorization(1)){

		return this->macAddress;

	}

}

bool Device::GetWired(ReferenceValidationMechanism *r){


	if(r->CheckAuthorization(1)){

		return this->wired;
	}

}

std::string Device::GetName(ReferenceValidationMechanism *r){

	if(r->CheckAuthorization(1)){
	
		return this->name;
	
	}

}

Device::~Device(){



}

std::vector<std::string> Device::SetPrivacyFlags(std::vector<std::string> newFlags){



}

void Device::ResetPrivacyFlags(){


}

bool Device::ConnectToUpdateDeviceDetails(){

    std::string *s = new std::string("init");
    std::string wow = SendMessageToDeviceAndGetResponse(this->localIpv4, s);

    std::cout << wow << "\n";
    std::stringstream ss(wow.c_str());
    std::string temp;

    if (s == nullptr){
        return false;
    }
    else{
        ss >> temp;
        this->macAddress = temp;
        ss >> temp;
        this->localIpv4 = temp;
        ss >> temp;
        this->localIpv6 = temp;
        ss >> temp;
        this->name = temp;
        ss >> temp;
        if (temp.compare("true") == 0)
            this->staticIp = true;
        else 
            this->staticIp = false;
        ss >> temp;
        if (temp.compare("true") == 0)
            this->wired = true;
        else
            this->wired = true;
        this->limitedMembers = false;
        std::cout << name << "\n";
        return true;
    }  
        
    return false;

}

bool Device::GetDeviceConnections(){




}

std::string Device::SendMessageToDeviceAndGetResponse(std::string address, std::string *message){

    //message = new std::string(ReferenceValidationMechanism::encryptString(*message, 3));
	const int port = 12345;

	 // Create a socket
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        std::cerr << "Error creating socket" << std::endl;
        return nullptr;
    }

	std::cerr << address;
    // Set up server address and port
    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);  // Use the same port as the server
    serverAddr.sin_addr.s_addr = inet_addr(address.c_str());  // Use the server's IP address

    // Connect to the server
    if (connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == -1) {
        std::cerr << "Error connecting to the server" << std::endl;
        close(clientSocket);
        return nullptr;
    }

    std::cerr << "Connected to the server" << std::endl;

    // Send data to the server
    send(clientSocket, message->c_str(), strlen(message->c_str()), 0);

    // Receive and display the echoed data
    char buffer[10000];
    ssize_t bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0);
    std::string response;
    if (bytesRead > 0) {
    	response.assign(buffer, bytesRead);
        //message = new std::string(buffer, bytesRead);
       
        //message = new std::string(ReferenceValidationMechanism::decryptString(*new std::string(buffer, bytesRead), 3));
    }
    close(clientSocket);
    // Close the socket
    
    return response;
}

	
