#ifndef SRC_DEVICE_I_
#define SRC_DEVICE_I_

#include "Device.h"
#include <string>
#include <iostream>

Device::Device(std::string IPv4, std::string IPv6, std::string deafaultGatway, std::string connectionType, std::vector<std::string> flags, std::vector<int> openPorts, bool staticIP, std::string mac){

localIpv4 = IPv4;
staticIp = staticIP;
macAddress = mac;
limitedMembers = false; 

std::cout << macAddress << "\n";

}

Device::Device(std::string mac, std::string IPv4, bool wiredConnection, std::string deviceName){

name = deviceName;
localIpv4 = IPv4;
wired = wiredConnection;
macAddress = mac;
limitedMembers = true; 


}

std::string Device::getIpv4(ReferenceValidationMechanism *r){

	if(r->checkAuthorization(1)){
		return localIpv4;
	}
}

std::string Device::getMac(ReferenceValidationMechanism *r){

	if(r->checkAuthorization(1)){
		return macAddress;
	}
}

bool Device::getWired(ReferenceValidationMechanism *r){

	if(r->checkAuthorization(1)){
		return wired;
	}
}

std::string Device::getName(ReferenceValidationMechanism *r){

	if(r->checkAuthorization(1)){
		return name;
	}
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