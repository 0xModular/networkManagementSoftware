#include "RemoteNetworkChangesLogEvent.h"

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





    //INSERT INTO users (first_name, last_name, email)
    //VALUES ('John', 'Doe', 'johndoe@example.com');

}


RemoteNetworkChangesLogEvent::RemoteNetworkChangesLogEvent(std::string event, Account a, std::string networkCateory){

    


    time_t currentTime;
    std::time(&currentTime); // Get the current time as a time_t
    this->time = static_cast<int>(currentTime);
    
}

void EncryptOutgoingLog(){

    
}

