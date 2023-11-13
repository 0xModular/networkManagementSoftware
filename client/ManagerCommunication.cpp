/*
 * ManagerCommunication.cpp
 * Created on: Oct 31, 2023
 *
 * Author: Layne
 */

#pragma once
#include <iostream>
#include <vector>
#include <cstring>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "ThisDevice.h"
#include "ManagerCommunication.h"

int ConnectToManager(ThisDevice *d) {

	// Create a socket
	int endDeviceSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (endDeviceSocket == -1) {
		
	std::cerr << "Error creating socket" << std::endl;
        
		//Handle error
	
	}
		


	//Set socket details
    	struct sockaddr_in serverAddr;
    	serverAddr.sin_family = AF_INET;
    	serverAddr.sin_port = htons(12345);  // Choose a port
    	serverAddr.sin_addr.s_addr = INADDR_ANY;



    	//Bind the socket to an IP address and port
    	if (bind(endDeviceSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == -1) {
        
		std::cerr << "Error binding socket" << std::endl;
        	close(endDeviceSocket);
        
		//Handle
    	
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

    	while (bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0)) {
        
			std::stringstream s(buffer); 

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
    	close(endDeviceSocket);

    	return 0;

}



