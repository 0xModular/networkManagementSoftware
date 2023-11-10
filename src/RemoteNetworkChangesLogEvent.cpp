#include "RemoteNetworkChangesLogEvent.h"
#include "DatabaseConnection.h"
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>

std::vector<RemoteNetworkChangesLogEvent> RemoteNetworkChangesLogEvent::ReadLogs(ReferenceValidationMechanism *r){


}

bool RemoteNetworkChangesLogEvent::UpdateLogWithNewEvent(ReferenceValidationMechanism *r){

    sql::Connection con = getSecureConnection("log", "log");


    sql::PreparedStatement* pstmt;
	pstmt = con->prepareStatement("INSERT INTO users (Category, Time, Account, Event) WHERE Category = ?, Time = ?, Account = ?, Event = ?");
	pstmt->setString(1, networkCateory);
    pstmt->setString(2, time);
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

