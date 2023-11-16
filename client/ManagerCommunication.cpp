/*
 * ManagerCommunication.cpp
 * Created on: Oct 31, 2023
 *
 * Author: Layne
 */

#pragma once
#include "ManagerCommunication.h"
#include <iostream>
#include <vector>
#include <cstring>
#include <sstream>
#include <unistd.h>
#include <winsock2.h>
#include "ThisDevice.h"

int ManagerCommunication::ConnectToManager(ThisDevice *d) {

		const int port = 12345;

	// Create a socket
	    WSADATA wsaData;
	    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
	        std::cerr << "Failed to initialize Winsock." << std::endl;
	        return 1;
	    }

	    SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, 0);
	    if (serverSocket == INVALID_SOCKET) {
	        std::cerr << "Failed to create server socket." << std::endl;
	        WSACleanup();
	        return 1;
	    }

	    sockaddr_in serverAddress;
	    serverAddress.sin_family = AF_INET;
	    serverAddress.sin_addr.s_addr = INADDR_ANY;
	    serverAddress.sin_port = htons(port);

	    if (bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == SOCKET_ERROR) {
	        std::cerr << "Binding failed." << std::endl;
	        closesocket(serverSocket);
	        WSACleanup();
	        return 1;
	    }

	    if (listen(serverSocket, 5) == SOCKET_ERROR) {
	        std::cerr << "Listening failed." << std::endl;
	        closesocket(serverSocket);
	        WSACleanup();
	        return 1;
	    }

	    std::cout << "Server is listening for incoming connections..." << std::endl;

	    SOCKET clientSocket;
	    sockaddr_in clientAddress;
	    int addrLen = sizeof(clientAddress);

	    clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddress, &addrLen);
	    if (clientSocket == INVALID_SOCKET) {
	        std::cerr << "Accepting client connection failed." << std::endl;
	        closesocket(serverSocket);
	        WSACleanup();
	        return 1;
	    }

	    char buffer[10000];
	    int bytesReceived;

	    while (true) {
	        bytesReceived = recv(clientSocket, buffer, sizeof(buffer), 0);
	        if (bytesReceived <= 0) {
	            std::cerr << "Connection closed by client." << std::endl;
	            break;
	        }
	        buffer[bytesReceived] = '\0';
	        std::cout << "Received: " << buffer << std::endl;



	        std::stringstream input(buffer);
	        std::string temp;
	        input >> temp;

	        if (temp.compare("init") == 0){

	        	int bytesSent = send(clientSocket, d->GetAllMembers().c_str(), strlen(d->GetAllMembers().c_str()), 0);
	        	if (bytesSent == SOCKET_ERROR) {
	        	    std::cerr << "Failed to send data to the client." << std::endl;
	        	    break;
	        	}
	        }
	    }

	    closesocket(clientSocket);
	    closesocket(serverSocket);
	    WSACleanup();
	    return 0;
	

}



