/*
 * RemoteNetworkChangesLogEvent.h
 * Created on: Oct 26, 2023
 *
 * Author: Layne
 */

#pragma once
#include <string>
#include <vector>
#include "Account.h"

class ReferenceValidationMechanism;

class RemoteNetworkChangesLogEvent{

	public:

		//public static method
		static std::vector<RemoteNetworkChangesLogEvent> ReadLogs(ReferenceValidationMechanism *r);

		//public method
		bool UpdateLogWithNewEvent(std::string event, ReferenceValidationMechanism *r);

	private:

		//private methods
		RemoteNetworkChangesLogEvent(std::string event, Account a, std::string networkCateory, int time); //Contructor
		void EncryptOutgoingLog();

		std::string logEvent;
		Account eventActor;
		std::string networkCateory;
		int time;

};



