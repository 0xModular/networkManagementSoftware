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
#include "ReferenceValidationMechanism.h"
#include "DatabaseConnection.h"
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>


class ReferenceValidationMechanism;
class DatabaseConnection;
class Account;

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



