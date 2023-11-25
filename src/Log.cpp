/*
 * RemoteNetworkChangesLogEvent.cpp
 * Created on: Nov 11, 2023
 *
 * Author: Layne
 */


#include "Log.h"

std::vector<Log> Log::ReadLogs(ReferenceValidationMechanism *r){


}

bool Log::CreateNewEventLogInDB(std::string event, ReferenceValidationMechanism *r) {

    if(!r)
        return false;

    auto con = DatabaseConnection::GetSecureConnection("log", "log");

    if (!con) 
        return false;

	//get time
    time_t rawTime;
    std::time(&rawTime);
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

bool Log::CreateNewEventLogInDB(std::string event, Account a) {

    auto con = DatabaseConnection::GetSecureConnection("log", "log");

    if (!con) 
        return false;

	//get time
    time_t rawTime;
    std::time(&rawTime);
    int currentTime = static_cast<int>(rawTime);

	//set query
    std::stringstream query;
    query << "INSERT INTO Log (Category, Time, Account, Event) VALUES (?, ?, ?, ?)";

    sql::PreparedStatement* pstmt;
    pstmt = con->prepareStatement(query.str());
    pstmt->setString(1, a.GetAccountCat());
    pstmt->setInt(2, currentTime);
    pstmt->setString(3, a.GetAccountName());
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

bool Log::CreateNewEventLogInDB(std::stringstream &eventss, ReferenceValidationMechanism *r) {

    std::string event = eventss.str();

        if(!r)
        return false;

    auto con = DatabaseConnection::GetSecureConnection("log", "log");

    if (!con) 
        return false;

	//get time
    time_t rawTime;
    std::time(&rawTime);
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

Log::Log(std::string event){
    
	this->logEvent = event;
    
}

