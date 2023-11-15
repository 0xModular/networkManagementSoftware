/*
 * RemoteNetworkChangesLogEvent.cpp
 * Created on: Nov 11, 2023
 *
 * Author: Layne
 */


#include "RemoteNetworkChangesLogEvent.h"

std::vector<RemoteNetworkChangesLogEvent> RemoteNetworkChangesLogEvent::ReadLogs(ReferenceValidationMechanism *r){


}

bool RemoteNetworkChangesLogEvent::UpdateLogWithNewEvent(ReferenceValidationMechanism *r){

    auto con = DatabaseConnection::GetSecureConnection("log", "log");


    sql::PreparedStatement* pstmt;
	pstmt = con->prepareStatement("INSERT INTO users (Category, Time, Account, Event) WHERE Category = ?, Time = ?, Account = ?, Event = ?");
	pstmt->setString(1, networkCateory);
    	pstmt->setString(2, std::to_string(time));
	pstmt->setString(3, eventActor.GetAccountName());
    	pstmt->setString(4, logEvent);

	sql::ResultSet* result = pstmt->executeQuery();

	if (result->next()) {
    
		

	} else {
    
		

	}


	delete con;
	delete result;
	delete pstmt;

}


RemoteNetworkChangesLogEvent::RemoteNetworkChangesLogEvent(std::string event, Account a, std::string networkCateory){
    
	time_t currentTime;
    	std::time(&currentTime); // Get the current time as a time_t
    	this->time = static_cast<int>(currentTime);
    
}

