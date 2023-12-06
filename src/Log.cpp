/*
 * RemoteNetworkChangesLogEvent.cpp
 * Created on: Nov 11, 2023
 *
 * Author: Layne
 */


#include "Log.h"

std::vector<Log> Log::ReadAllNetworkLogs(ReferenceValidationMechanism *r){

    auto con = DatabaseConnection::GetSecureConnection("netadmin", "netadmin");

    std::vector<Log> logVec;

    if (con == nullptr || !r->CheckAuthorization(2)){

        std::stringstream logMessage;
        logMessage << "Logs for network category " << r->GetAccount().GetAccountCat() << " retrieve attempt failed";
        Log::CreateNewEventLogInDB(logMessage.str(), r);
        return logVec;
	}

    try {

            std::string query = "SELECT Time, Account, Event FROM Logs WHERE Category = ?";
            std::unique_ptr<sql::PreparedStatement> pstmt(con->prepareStatement(query));
            pstmt->setString(1, r->GetAccount().GetAccountCat());

            std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());
            while (res->next()) {
                
                std::string logEvent = res->getString("Time");
                std::string accName = res->getString("Account");
                std::string logTime = res->getString("Event");
                
                std::string query2 = "SELECT Category, Type FROM Logs WHERE UserName = ?";
                std::unique_ptr<sql::PreparedStatement> pstmt2(con->prepareStatement(query2));
                pstmt2->setString(1, accName);
                std::unique_ptr<sql::ResultSet> res2(pstmt->executeQuery());
                res2->next();

                std::string accCat = res2->getString("Category");
                std::string accType = res2->getString("Type");

                Account a(accName, accType, accCat);

                Log l(logEvent, stoi(logTime), a);
                logVec.push_back(l);
            }
        }
    
    catch (sql::SQLException& e) {
        std::stringstream logMessage;
        logMessage << "Logs for network category " << r->GetAccount().GetAccountCat() << " retrieve attempt failed";
        Log::CreateNewEventLogInDB(logMessage.str(), r);
		logVec.clear();
        return logVec; 
    }

    std::stringstream logMessage;
    logMessage << "Logs for network category " << r->GetAccount().GetAccountCat() << " retrieved successfully";
	if(!Log::CreateNewEventLogInDB(logMessage.str(), r))
		logVec.clear(); //if log fails then this function fails
     

    return logVec;

}

bool Log::CreateNewEventLogInDB(std::string event, ReferenceValidationMechanism *r) {

    return CreateNewEventLogInDB(event, r->GetAccount());

}

void Log::SetNextLogUrgent(){

    urgentNext = true;

}

Log::Log(std::string event, int Time, Account &User){
    
	this->logEvent = event;
    this->time = Time;
    this->user = &User;
    
}

std::string Log::GetLogEvent(){

    return this->logEvent;

}

int Log::GetLogTime(){

    return this->time;

}

Account Log::GetLogAccount(){

    return *this->user;

}




bool Log::CreateNewEventLogInDB(std::string event, Account a) {

    auto con = DatabaseConnection::GetSecureConnection("log", "log");

    if (!con) 
        return false;

	//get time
    time_t rawTime;
    std::time(&rawTime);
    int currentTime = static_cast<int>(rawTime);

    try {


    sql::PreparedStatement* pstmt;
    pstmt = con->prepareStatement("INSERT INTO Logs (Category, Time, Account, Event, Urgent) VALUES (?, ?, ?, ?, ?)");
    pstmt->setString(1, a.GetAccountCat());
    pstmt->setInt(2, currentTime);
    pstmt->setString(3, a.GetAccountName());
    pstmt->setString(4, event);
    pstmt->setBoolean(5, urgentNext);


    if(!pstmt->execute()){

        delete pstmt;
        return true;
    }
    else{

        delete pstmt;
        return false;
    }

    } 
	catch (const sql::SQLException& e) {

        std::cerr << "SQL Exception in CreateNewEventLogInDB: ";
        std::cerr << "Error code: " << e.getErrorCode() << std::endl;
        std::cerr << "SQL state: " << e.getSQLState() << std::endl;
        std::cerr << "Error message: " << e.what() << std::endl;
        return false;
    }

    if(urgentNext)
        urgentNext = false;

}

