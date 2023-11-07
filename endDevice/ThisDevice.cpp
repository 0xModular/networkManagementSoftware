#include "ThisDevice.h"

#ifndef SRC_THISDEVICE_I_
#define SRC_THISDEVICE_I_

std::string ThisDevice::getDefaultAdapater(){

 std::vector<std::tuple<std::string, std::string, std::string>> devices;
    char buffer[256];

    FILE* pipe = _popen("ipconfig", "r"); // Execute "arp -a" and capture output

    if (!pipe) {
        std::cerr << "Error running arp -a command." << std::endl;
        return devices;
    }

    std::regex deviceRegex(R"([a-zA-Z]+\sadapter\s([a-zA-Z0-9]+):\n\n\s\s\sConnection-specific\sDNS\sSuffix)");

    while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
        std::string line(buffer);
        std::smatch match;

        if (std::regex_search(line, match, deviceRegex)) {
            if (match.size() == 2) {
            	std::string whole = match[0];
                std::string adapter = match[1];

                defaultAdapter = adapter;
                return defaultAdapter;
            }
        }
    }
}

void ThisDevice::getAllMembers(){

    std::string dhcp;
    std::string whole;

    std::vector<std::tuple<std::string, std::string, std::string>> devices;
    char buffer[256];

    FILE* pipe = _popen("ipconfig /all", "r"); // Execute "arp -a" and capture output

    if (!pipe) {
        std::cerr << "Error running arp -a command." << std::endl;
        return devices;
    }

    std::regex deviceRegex(R"(Windows\sIP\sConfiguration\n\n\s\s\sHost\sName[\s.]+:\s([a-zA-Z0-9\-.\(\)\#]+)[a-zA-Z0-9\s.:\(\)\-%,]+[a-zA-Z]+\sadapter\s[a-zA-Z0-9]+:\n\n\s\s\sConnection-specific\sDNS\sSuffix[a-zA-Z0-9\s.:\(\)\-%,]+Physical\sAddress[.\s]+:\s([a-fA-F0-9-]+)\n[a-zA-Z0-9\s.:\(\)\-%,]+DHCP\sEnabled[.\s]+:\s([YesNo]+)\n[a-zA-Z0-9\s.:\(\)\-%,]+IPv6\sAddress[.\s]+:\s([a-zA-Z0-9:%]+)[a-zA-Z0-9\s.:\(\)\-%,]+IPv4\sAddress[.\s]+:\s([0-9.]+)[a-zA-Z0-9\s.:\(\)\-%,]+Default\sGateway[.\s]+:\s([0-9.]+))");

    while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
        std::string line(buffer);
        std::smatch match;

        if (std::regex_search(line, match, deviceRegex)) {
            if (match.size() == 7) {
            	whole = match[0];
                name = match[1];
                macAddress = match[2];
                dhcp = match[3];
                localIpv6 = match[4];
                localIpv4 = match[5];
                defaultGateway = match[6];

                if(dhcp.compare("Yes") == 0)
                    staticIp = false;
                else
                    staticIp = true;

                return;
            }
        }
    }
}


std::vector<Connection> ThisDevice::getConnections(){

ports.clear();

std::string whole;
int localPort;
std::string remoteAddress;
int remotePort;
std::string state;
int pid;

 std::vector<std::tuple<std::string, std::string, std::string>> devices;
    char buffer[256];

    FILE* pipe = _popen("netstat -aon", "r"); // Execute "arp -a" and capture output

    if (!pipe) {
        std::cerr << "Error running arp -a command." << std::endl;
        return devices;
    }

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

                ports.push_back(Connection(localPort, remoteAddress, remotePort, state, pid));


            }
        }
    }

    return ports;

}



#endif