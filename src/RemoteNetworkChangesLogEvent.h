
#ifndef SRC_REMOTENETWORKCHANGESLOG_H_
#define SRC_REMOTENETWORKCHANGESLOG_H_

#include <vector>
#include <string>
#include "src/ReferenceValidationMechanism.h"

class RemoteNetworkChangesLogEvent{

	public:

		//public static method
		static std::vector<RemoteNetworkChangesLogEvent> readLogs(ReferenceValidationMechanism *r);

		//public method
		bool updateLogWithNewEvent(std::string event, ReferenceValidationMechanism *r);

	private:

		//private static methods
		RemoteNetworkChangesLogEvent(std::string event, Account a, std::string networkCateory, int time)
		void encryptOutgoingLog();

};



#endif /* SRC_REMOTENETWORKCHANGESLOG_H_ */
