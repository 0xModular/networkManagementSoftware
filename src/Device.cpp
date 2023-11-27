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
    this->connections = *new std::vector<Connection>;

}

std::string Device::GetIpv4(){

	return this->localIpv4;

}

int Device::GetX(){

	return this->posX;

}

int Device::GetY(){

	return this->posY;

}

void Device::SetX(int x){

	this->posX = x;

}

void Device::SetY(int y){

	this->posY = y;

}

std::vector<Connection> Device::GetConnectionVector(){

    return this->connections;

}

std::string Device::GetMac(){

	return this->macAddress;

}

bool Device::GetWired(){

	return this->wired;

}

std::string Device::GetName(){

	return this->name;
	
}

std::string Device::GetIpv6(){

    if(!limitedMembers)
        return this->localIpv6;

}

std::string Device::GetDefaultGateway(){

    if(!limitedMembers)
        return this->defaultGateway;

}

bool Device::GetIsStaticIp(){

    if(!limitedMembers)
        return this->staticIp;

}

Device::~Device(){

}

std::vector<std::string> Device::SetPrivacyFlags(std::vector<std::string> newFlags){



}

void Device::ResetPrivacyFlags(){


}

bool Device::ConnectToUpdateDeviceDetails(ReferenceValidationMechanism *r){

    std::string response = SendMessageToDeviceAndGetResponse("init", r->GetAccount().GetAccountCat());
    
    std::stringstream ss(response.c_str());
    std::string temp;

    if (response.compare("error") == 0){  // Correcting the condition
        
        //log failure
        std::stringstream logMessage;
        logMessage << "contacted device with MAC " << this->macAddress << " using Ip " << this->localIpv4 << " and failed to get it's network connections";
        Log::CreateNewEventLogInDB(logMessage, r);
         
        return false;
    } 
    else{

        //make log for success
        std::stringstream logMessage;
        logMessage << "contacted device with MAC " << this->macAddress << " using Ip " << this->localIpv4 << " and succesfully got it's network details";
        if (!Log::CreateNewEventLogInDB(logMessage, r))
            return false; //if log fails then this function fails

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

bool Device::GetDeviceConnections(ReferenceValidationMechanism *r){

    std::string response = SendMessageToDeviceAndGetResponse("connection", r->GetAccount().GetAccountCat());

    std::stringstream ss(response);
    std::string temp;

    if (response.compare("error") == 0){  // Correcting the condition
        
        //log failure
        std::stringstream logMessage;
        logMessage << "contacted device with MAC " << this->macAddress << " using Ip " << this->localIpv4 << " and failed to get it's network connections";
        Log::CreateNewEventLogInDB(logMessage, r);
         
        return false;
    }


    //make log for success
    std::stringstream logMessage;
    logMessage << "contacted device with MAC " << this->macAddress << " using Ip " << this->localIpv4 << " and succesfully updated got it's network connections";
    if (!Log::CreateNewEventLogInDB(logMessage, r))
        return false; //if log fails then this function fails

    int localPort;
    int remotePort;
    std::string remoteIp;
    std::string status;
    int PID;

    while(ss >> temp){
        
        localPort = stoi(temp);
        ss >> temp;
        remotePort = stoi(temp);
        ss >> temp;
        remoteIp = temp;
        ss >> temp;
        status = temp;
        ss >> temp;
        PID = stoi(temp);

        this->connections.push_back(Connection(localPort, remotePort, remoteIp, status, PID));
        
    }  

    return true;

}

bool Device::ChangeStaticIp(std::string newIP, ReferenceValidationMechanism *r){

    std::string message;
    message = "static " + newIP;
    std::string response = SendMessageToDeviceAndGetResponse(message, r->GetAccount().GetAccountCat());
    
    std::stringstream ss(response.c_str());
    std::string temp;

    if (response.compare("error") == 0){  // Correcting the condition
        
        //log failure
        std::stringstream logMessage;
        logMessage << "contacted device with MAC " << this->macAddress << " using Ip " << this->localIpv4 << " and failed to update it's static IP";
        Log::CreateNewEventLogInDB(logMessage, r);
         
        return false;
    } 
    else{

        //make log for success
        std::stringstream logMessage;
        logMessage << "contacted device with MAC " << this->macAddress << " using Ip " << this->localIpv4 << " and succesfully updated it's static IP to " << newIP;

        this->ConnectToUpdateDeviceDetails(r);
        return true;
    }  
        
    return false;

}

bool Device::ChangeToDHCP(ReferenceValidationMechanism *r){

    std::string response = SendMessageToDeviceAndGetResponse("dhcp", r->GetAccount().GetAccountCat());
    
    std::stringstream ss(response.c_str());
    std::string temp;

    if (response.compare("error") == 0){  // Correcting the condition
        
        //log failure
        std::stringstream logMessage;
        logMessage << "contacted device with MAC " << this->macAddress << " using Ip " << this->localIpv4 << " and failed to set it to use DHCP";
        Log::CreateNewEventLogInDB(logMessage, r);
         
        return false;
    } 
    else{

        //make log for success
        std::stringstream logMessage;
        logMessage << "contacted device with MAC " << this->macAddress << " using Ip " << this->localIpv4 << " and succesfully set it to use DHCP";

        this->ConnectToUpdateDeviceDetails(r);
        return true;
    }  
        
    return false;

}

int Device::PingAnotherDevice(Device d, ReferenceValidationMechanism *r){

    return PingAnotherDevice(d.localIpv4, r);

}

int Device::PingAnotherDevice(std::string ip, ReferenceValidationMechanism *r){

    std::string message;
    message = "ping " + ip;
    std::string response = SendMessageToDeviceAndGetResponse(message, r->GetAccount().GetAccountCat());
    
    std::stringstream ss(response.c_str());
    std::string temp;

    if (response.compare("error") == 0){  // Correcting the condition
        
        //log failure
        std::stringstream logMessage;
        logMessage << "contacted device with MAC " << this->macAddress << " using Ip " << this->localIpv4 << " and failed ping ip " << ip;
        Log::CreateNewEventLogInDB(logMessage, r);
         
        return -1;
    } 
    else{

        //make log for success
        std::stringstream logMessage;
        logMessage << "contacted device with MAC " << this->macAddress << " using Ip " << this->localIpv4 << " and succesfully pinged " << ip;

        ss >> temp;
        ss >> temp;
        return std::stoi(temp);
    }  
        
    return -1;

}

bool Device::TerminateConnection(Connection c, ReferenceValidationMechanism *r){

    return TerminateConnection(c.PID, r);

}


bool Device::TerminateConnection(int pid, ReferenceValidationMechanism *r){

    std::string response = SendMessageToDeviceAndGetResponse("terminate " + std::to_string(pid), r->GetAccount().GetAccountCat());

    std::stringstream ss(response);
    std::string temp;

    if (response.compare("error") == 0){  // Correcting the condition
        
        //log failure
        std::stringstream logMessage;
        logMessage << "contacted device with MAC " << this->macAddress << " using Ip " << this->localIpv4 << " and failed to kill a connection";
        Log::CreateNewEventLogInDB(logMessage, r);
         
        return false;
    }


    //make log for success
    std::stringstream logMessage;
    logMessage << "contacted device with MAC " << this->macAddress << " using Ip " << this->localIpv4 << " and succesfully killed a connections";
    if (!Log::CreateNewEventLogInDB(logMessage, r))
        return false; //if log fails then this function fails

    int localPort;
    int remotePort;
    std::string remoteIp;
    std::string status;
    int PID;

    while(ss >> temp){
        
        localPort = stoi(temp);
        ss >> temp;
        remotePort = stoi(temp);
        ss >> temp;
        remoteIp = temp;
        ss >> temp;
        status = temp;
        ss >> temp;
        PID = stoi(temp);

        this->connections.push_back(Connection(localPort, remotePort, remoteIp, status, PID));
        
    }  

    return true;

}

int Device::NewRandomNumber(){

    static std::unordered_set<int> usedNumbers;
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    
    while(true){
        
        int newint = std::rand();
        if(usedNumbers.find(newint) == usedNumbers.end()){
            usedNumbers.insert(newint);
            return newint;
        }
    }      

}

std::string Device::SendMessageToDeviceAndGetResponse(std::string message, std::string networyCategory){

    //message = new std::string(ReferenceValidationMechanism::encryptString(*message, 3));
	const int port = 12345;

	 // Create a socket
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        return "error";
    }

	std::cerr << this->localIpv4;
    // Set up server address and port
    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);  // Use the same port as the server
    serverAddr.sin_addr.s_addr = inet_addr(this->localIpv4.c_str());  // Use the server's IP address

    // Connect to the server
    if (connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == -1) {
        //std::cerr << "Error connecting to the server" << std::endl;
        close(clientSocket);
        return "error";
    }

    std::cout << "Connected to the server" << std::endl;

    // Send data to the server
    std::string toSend = ReferenceValidationMechanism::EncryptString(std::to_string(NewRandomNumber()) + " " + networyCategory + " " + message, 29);
    send(clientSocket, toSend.c_str(), strlen(toSend.c_str()), 0);
    // Receive and display the echoed data
    char buffer[10000];
    ssize_t bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0);
    std::string response;
    std::cout << "bread " << bytesRead << "\n";
    if (bytesRead > 0) {
    	response.assign(buffer, bytesRead);
        response = ReferenceValidationMechanism::DecryptString(response, 29);
        close(clientSocket);
        std::cout << "m: " << response << "\n";
        return response;
    }
    else{
        close(clientSocket);
        return "error";
    }

    close(clientSocket);
    return "error";
 
}

	
