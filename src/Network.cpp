/*
 * Network.cpp
 * Created on Oct 24, 2023
 *
 * Author:
 */


#include "Network.h"

Network::Network(ReferenceValidationMechanism *r) {

	if (!r->CheckAuthorization(1))
    		return;

	if(!Log::CreateNewEventLogInDB("Created new network and obtained it's details", r))
		return;

	GetDevices();
    GetGeneralNetworkDetails();
    timeSinceRefresh = 0;

}

void Network::Refresh(ReferenceValidationMechanism *r){

	if (!r->CheckAuthorization(1))
		return;

	if(!Log::CreateNewEventLogInDB("Refreshed network details", r))
		return;
    		
	GetDevices();
    GetGeneralNetworkDetails();
    timeSinceRefresh = 0;
	
	

}

std::vector<Device> Network::GetDeviceList(){

	return deviceList;

}

void Network::GetDevices(){

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
        
		if (wiredString.compare("ether") == 0) {
            
			wired = true;
			
		} else {
            
			wired = false;

		}

        	Device d(macAddress, ipv4Address, wired, name);

        	if (name.compare("_gateway") == 0) {
            
			gateway = &d;

		}

        	deviceList.push_back(d);

        	it = match[0].second;
    
	}

}

Device Network::GetGatewayDevice(ReferenceValidationMechanism *r){
         
	return *gateway;

}

void Network::GetGeneralNetworkDetails(){



}

bool Network::UploadAllCurrentDevicesToDB(ReferenceValidationMechanism *r){

	auto con = DatabaseConnection::GetSecureConnection("login", "login");

    if (con == nullptr || !r->CheckAuthorization(1)){
		delete con;
		Log::CreateNewEventLogInDB("Attempt to upload all devices from current network failed", r);
	    return false; 
	}

	try{

	    for (Device d: this->deviceList) {
            // Check if the object with the given ID already exists
            sql::PreparedStatement *pstmt;
			pstmt = con->prepareStatement("SELECT * FROM Devices WHERE MacAddress = ?");
            pstmt->setString(1, d.GetMac());
            sql::ResultSet *res = pstmt->executeQuery();

            if (res->next()) {
                // If the object exists, update its values
                pstmt = con->prepareStatement("UPDATE Devices SET PositionX = ?, PositionY = ?, Ipv4 = ?, DeviceName = ?, Wired = ? WHERE id = ?");
                pstmt->setInt(1, d.GetX());
                pstmt->setInt(2, d.GetY());
				pstmt->setString(3, d.GetIpv4());
				pstmt->setString(4, d.GetName());
				pstmt->setBoolean(5, d.GetWired());
                pstmt->executeUpdate();
            } else {
                // If the object doesn't exist, insert a new row
                pstmt = con->prepareStatement("INSERT INTO Devices (MacAddress, PositionX, PositionY, Ipv4, DeviceName, Wired, Network) VALUES (?, ?, ?, ?, ?, ?, ?)");
                pstmt->setString(1, d.GetMac());
				pstmt->setInt(2, d.GetX());
				pstmt->setInt(3, d.GetY());
				pstmt->setString(4, d.GetIpv4());
				pstmt->setString(5, d.GetName());
				pstmt->setBoolean(6, d.GetWired());
				pstmt->setString(7, r->GetAccount().GetAccountCat());
                pstmt->executeUpdate();
            }
			delete pstmt;
        }

        
        delete con;
    } 
	catch (sql::SQLException &e) {
		delete con;
	    Log::CreateNewEventLogInDB("Attempt to upload all devices from current network failed", r);
		return false; 
    
	}

	Log::CreateNewEventLogInDB("Uploaded all devices from current network to database", r);
	return true;

}

/*
bool Network::UploadAllCurrentDevicesToDB(ReferenceValidationMechanism *r){

    	auto con = DatabaseConnection::GetSecureConnection("login", "login");

    if (con == nullptr || !r->CheckAuthorization(1)){
		delete con;
		Log::CreateNewEventLogInDB("Attempt to get all devices from the database for the network failed", r);
	    return false; 
	}

	try{
	
	 // Retrieve entries that match the column value
        sql::PreparedStatement *pstmt;
		pstmt = con->prepareStatement("SELECT * FROM Devices WHERE Network = ?");
        pstmt->setString(1, r->GetAccount().GetAccountCat());
        sql::ResultSet *res = pstmt->executeQuery();

        // Store retrieved objects in a vector
        while (res->next()) {

			std::string mac = res->getString("MacAddress");
			int x = res->getInt("PositionX");
			int y = res->getInt("PositionY");
			bool exists = false;

			for(Device &d: this->deviceList){
				if(d.GetMac().compare(mac) == 0){
					d.SetX(x);
					d.SetY(y);
					exists = true;
				}

			}

			if(exists == false){
            	int x = res->getInt("PositionX");
				int y = res->getInt("PositionY");
				std::string ip = res->getString("Ipv4");
				std::string name = res->getString("DeviceName");
				bool wired = res->getBoolean("Wired");
            	// Assign other members accordingly
				Device device(mac, ip, wired, name, x, y);
				this->deviceList.push_back(device);
			}
		}

        delete pstmt;
        delete con;
    } 
	catch (sql::SQLException &e) {
        delete con;
	    Log::CreateNewEventLogInDB("Attempt to get all devices from the database for the network failed", r);
		return false; 
	}

	Log::CreateNewEventLogInDB("All devices from the current network were retrieved from the database", r);
    return true;

}



void Network::EditDevices(Device d, std::string requestType, std::string AdditionalData){

	std::string message;
    
	//changes dynamic to static and static to dynamic. Additional data is the ip a device should be if its being changed to static.
    	if (requestType.compare("changeIpType") == 0){
        
		message = requestType + " " + AdditionalData;
    
	} else if (requestType.compare("changeStaticIp") == 0){

		//change static ip to a new static ip value
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
    */

