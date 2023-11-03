#ifndef SRC_REMOTENETWORKCHANGESLOG_H_
#define SRC_REMOTENETWORKCHANGESLOG_H_

#include <string>
#include <vector>

#include "Account.h"

class ReferenceValidationMechanism;

class RemoteNetworkChangesLogEvent{

	public:

		//public static method
		static std::vector<RemoteNetworkChangesLogEvent> readLogs(ReferenceValidationMechanism *r);

		//public method
		bool updateLogWithNewEvent(std::string event, ReferenceValidationMechanism *r);

	private:

		//private methods
		RemoteNetworkChangesLogEvent(std::string event, Account a, std::string networkCateory, int time);
		void encryptOutgoingLog();

		std::string logEvent;
		Account eventActor;
		std::string networkCateory;
		int time;

};



#endif /* SRC_REMOTENETWORKCHANGESLOG_H_ */