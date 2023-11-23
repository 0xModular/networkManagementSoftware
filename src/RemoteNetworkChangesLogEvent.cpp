/*
 * RemoteNetworkChangesLogEvent.cpp
 * Created on: Nov 11, 2023
 *
 * Author: Layne
 */


#include "RemoteNetworkChangesLogEvent.h"

std::vector<RemoteNetworkChangesLogEvent> RemoteNetworkChangesLogEvent::ReadLogs(ReferenceValidationMechanism *r){


}

bool RemoteNetworkChangesLogEvent::CreateNewEventLogInDB(std::string event, ReferenceValidationMechanism *r) {

    auto con = DatabaseConnection::GetSecureConnection("log", "log");

    if (!con) 
        return false;

	//get time
    time_t rawTime;
    time(&rawTime);
    int currentTime = static_cast<int>(rawTime);

	//set query
    std::stringstream query;
    query << "INSERT INTO Log (Category, Time, Account, Event) VALUES (?, ?, ?, ?)";

    sql::PreparedStatement* pstmt;
    pstmt = con->prepareStatement(query.str());
    pstmt->setString(1, r->GetAccount().GetAccountCat());
    pstmt->setInt(2, currentTime);
    pstmt->setString(3, r->GetAccount().GetAccountName());
    pstmt->setString(4, event);

    bool success = false;

    try {
        success = pstmt->execute();
    } 
	catch (const sql::SQLException& e) {
        success = false;
    }

    delete pstmt;
    delete con;

    return success;
}

RemoteNetworkChangesLogEvent::RemoteNetworkChangesLogEvent(std::string event){
    
	this->logEvent = event;
    
}

