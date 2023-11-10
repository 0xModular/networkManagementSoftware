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
		bool UpdateLogWithNewEvent(ReferenceValidationMechanism *r);
		RemoteNetworkChangesLogEvent();
		~RemoteNetworkChangesLogEvent();

	private:

		//private methods
		RemoteNetworkChangesLogEvent(std::string event, Account a, std::string networkCateory); //Contructor

		std::string logEvent;
		Account eventActor;
		std::string networkCateory;
		int time;

};



