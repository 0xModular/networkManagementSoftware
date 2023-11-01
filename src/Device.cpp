#ifndef SRC_DEVICE_I_
#define SRC_DEVICE_I_

#include "Device.h"
#include <string>

Device::Device(std::string IPv4, std::string IPv6, std::string deafaultGatway, std::string connectionType, std::vector<std::string> flags, std::vector<int> openPorts, bool staticIP, std::string mac){

localIpv4 = IPv4;
staticIp = staticIP;
macAddress = mac;
limitedMembers = false; 


}

Device::Device(std::string IPv4, bool staticIP, std::string mac){

localIpv4 = IPv4;
staticIp = staticIP;
macAddress = mac;
limitedMembers = true; 


}

Device::~Device(){



}

std::vector<std::string> Device::setPrivacyFlags(std::vector<std::string> newFlags){



}

void Device::resetPrivacyFlags(){


}

void Device::setDeviceDetails(std::string IPv4, std::string IPv6, std::string defaultGateway, std::vector<int> openPorts, bool staticIP){


}

void Device::validateDeviceDetailInputs(std::string *IPv4, std::string *IPv6, std::string *defaultGateway, std::vector<int> *openPorts, bool *staticIP){



}

#endif