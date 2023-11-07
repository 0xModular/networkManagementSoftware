#ifndef SRC_MANAGERCOMMUNICATION_I_
#define SRC_MANAGERCOMMUNICATION_I_


#include <iostream>
#include <vector>
#include <cstring>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

int connectToManager() {

    // Create a socket
    int endDeviceSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (endDeviceSocket == -1) {
        std::cerr << "Error creating socket" << std::endl;
        //handle error
    }

    //set socket details
    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(12345);  // Choose a port
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket to an IP address and port
    if (bind(endDeviceSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == -1) {
        std::cerr << "Error binding socket" << std::endl;
        close(endDeviceSocket);
        //handle
    }

    // Listen for incoming connections
    if (listen(endDeviceSocket, 5) == -1) {
        std::cerr << "Error listening for connections" << std::endl;
        close(endDeviceSocket);
        //handle
    }

    std::cout << "Listening for incoming requests..." << std::endl;

    // Accept incoming connections
    struct sockaddr_in clientAddr;
    socklen_t clientAddrLen = sizeof(clientAddr);
    int clientSocket = accept(endDeviceSocket, (struct sockaddr*)&clientAddr, &clientAddrLen);

    if (clientSocket == -1) {
        std::cerr << "Error accepting connection" << std::endl;
        close(endDeviceSocket);
        //handle
    }

    std::cout << "Manager connected" << std::endl;

    // Receive data
    char buffer[1024];
    ssize_t bytesRead;

    while ((bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0)) {
        if (bytesRead > 0) {
            // Echo the received data back to the client


            if(strcmp(bytesRead, "changeStaticIP") == 0){

            }


            send(clientSocket, buffer, bytesRead, 0);
        }
    }

    std::cout << "Connection closed" << std::endl;

    // Close the sockets
    close(clientSocket);
    close(serverSocket);

    return 0;
}




void setStaticIP(){

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






#endif