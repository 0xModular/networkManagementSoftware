/*
 * Network.h
 * Created on Oct 24, 2023
 *
 * Author: Layne
 */

#pragma once
#include <cstdio>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <regex>
#include <tuple>
#include "Device.h"
#include "Note.h"
#include "ReferenceValidationMechanism.h"
#include "Log.h"

//class Note;
class Device;
class Log;
class ReferenceValidationMechanism;

class Network{

	public:

		//constructor and deconstructor
		Network(ReferenceValidationMechanism *r); //Calls getDevices, getGeneralNetworkDetails, and getConnections to get information needed for  the current network.
		~Network();
		
		//get updated information for the network
		void Refresh(ReferenceValidationMechanism *r);

		//getters
		std::vector<Device> GetDeviceList();
		Device GetGatewayDevice(ReferenceValidationMechanism *r);

		//interact with database for devices
		bool UploadAllCurrentDevicesToDB(ReferenceValidationMechanism *r);
		bool AddNewDevice(std::string mac, std::string IPv4, bool wiredConnection, std::string deviceName, ReferenceValidationMechanism *r); //finish
		bool RemoveDevice(Device d, ReferenceValidationMechanism *r); //
		
		//interact with database for notes
		bool EnterNewNoteToList(Note n, ReferenceValidationMechanism *r);
		bool EnterNewNoteToList(std::string message, int x, int y, ReferenceValidationMechanism *r); //
		bool RemoveNote(Note n, ReferenceValidationMechanism *r); //
		bool RetrieveAllNotesFromDB(ReferenceValidationMechanism *r); //

		//used for login. Dont worry about it. Use the normal getter
		static std::string GatewayMac();

	private:

		//used in constructor and refresh
		void GetDevices();
		void GetGeneralNetworkDetails();
		bool RetrieveAllDevicesFromDB(ReferenceValidationMechanism *r);
		

		//interact with database
		bool UpdateDevicesFromDB(ReferenceValidationMechanism *r);
		bool UpdateNotesFromDB(ReferenceValidationMechanism *r);
		bool UploadAllCurrentNotesToDB(ReferenceValidationMechanism *r); //DO NOT USE! this functionality is moving to another function

		//members
		std::string defaultDNS;
		std::string subnetMask;
		std::vector<Device> deviceList;
		std::vector<Note> noteList;
		Device *gateway;
};




/*
Machine1 (10.0.2.4) at 08:00:27:ad:87:b3 [ether] om etho0
Machine2 (10.0.2.5) at 08:00:27:27:d6:b7 [ether] om etho0
_gateway (10.0.2.1) at 08:00:27:65:r5:89 [ether] om etho0

Machine ([a-zA-Z0-9]+)\s
Ip \(([0-9]+\.[0-9]+\.[0-9]+\.[0-9]+)\)
([_a-zA-Z0-9]+)\s\(([0-9]+\.[0-9]+\.[0-9]+\.[0-9]+)\)\sat\s([0-9a-fA-F]+:[0-9a-fA-F]+:[0-9a-fA-F]+:[0-9a-fA-F]+:[0-9a-fA-F]+:[0-9a-fA-F]+)\s\[([a-zA-Z0-9]+)\]\son\s([a-zA-Z0-9]+)\n

*/
