/*
 * Account.cpp
 * Created on: Oct 24, 2023
 *
 * Author: Layne
 */

#include "Account.h"



//Admin: Gets the managable accounts from the DB
std::vector<Account> Account::GetManagableAccounts(ReferenceValidationMechanism *r)
{

    auto con = DatabaseConnection::GetSecureConnection("netadmin", "netadmin");

    std::vector<Account> accountVec;

    if (con == nullptr || !r->CheckAuthorization(2))
    {
        delete con;
        std::stringstream logMessage;
        logMessage << "Accounts for network category " << r->GetAccount().GetAccountCat() << " retrieve attempt failed";
        Log::CreateNewEventLogInDB(logMessage, r);
        return accountVec;
    }

    try
    {

        std::string query = "SELECT UserName, Type, Category FROM Accounts WHERE Category = ? AND Type != ?";
        std::unique_ptr<sql::PreparedStatement> pstmt(con->prepareStatement(query));
        pstmt->setString(1, r->GetAccount().GetAccountCat());
        pstmt->setString(2, "admin");

        std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());
        while (res->next())
        {

            std::string name = res->getString("col1");
            std::string accType = res->getString("col2");
            std::string cat = res->getString("col3");
            Account a(name, accType, cat);
            accountVec.push_back(a);
        }
    }

    catch (sql::SQLException &e)
    {
        std::stringstream logMessage;
        logMessage << "Accounts for network category " << r->GetAccount().GetAccountCat() << " retrieve attempt failed";
        Log::CreateNewEventLogInDB(logMessage, r);
        accountVec.clear();
        return accountVec;
    }

    std::stringstream logMessage;
    logMessage << "Accounts for network category " << r->GetAccount().GetAccountCat() << " retrieved successfully";
    if (!Log::CreateNewEventLogInDB(logMessage, r))
        accountVec.clear(); // if log fails then this function fails

    return accountVec;
}


//Admin: remove an account from this network
bool Account::RemoveAccount(ReferenceValidationMechanism *r)
{

    auto con = DatabaseConnection::GetSecureConnection("netadmin", "netadmin");

    if (con == nullptr || !r->CheckAuthorization(2))
    {
        delete con;
        std::stringstream logMessage;
        logMessage << "Attempt to delete account " << this->userName << " failed";
        Log::CreateNewEventLogInDB(logMessage, r);
        return false;
    }

    try
    {

        std::string query = "DELETE FROM Accounts WHERE type != ? AND UserName = ? AND Category = ?";
        std::unique_ptr<sql::PreparedStatement> pstmt(con->prepareStatement(query));
        pstmt->setString(1, "admin");
        pstmt->setString(2, this->userName);
        pstmt->setString(3, r->GetAccount().userName);
        pstmt->execute();
    }
    catch (sql::SQLException &e)
    {

        std::stringstream logMessage;
        logMessage << "Attempt to delete account " << this->userName << " failed";
        Log::CreateNewEventLogInDB(logMessage, r);
        return false;
    }

    std::stringstream logMessage;
    logMessage << "Account " << this->userName << " succesfully deleted";
    Log::CreateNewEventLogInDB(logMessage, r);
    return true; 

} // ON DELETE CASCADE


//Admin: Change account name for an account on this network
bool Account::EditAccountName(std::string newName, ReferenceValidationMechanism *r)
{

    auto con = DatabaseConnection::GetSecureConnection("netadmin", "netadmin");

    if (con == nullptr || !r->CheckAuthorization(2))
    {
        delete con;
        std::stringstream logMessage;
        logMessage << "Attempt to update account name for account " << this->userName << " to " << newName << " failed";
        Log::CreateNewEventLogInDB(logMessage, r);
        return false;
    }

    try
    {

        std::string query = "UPDATE Accounts SET UserName = ? WHERE UserName = ?";
        std::unique_ptr<sql::PreparedStatement> pstmt(con->prepareStatement(query));
        pstmt->setString(1, newName);
        pstmt->setString(2, this->userName);
        pstmt->execute();
    }
    catch (sql::SQLException &e)
    {

        std::stringstream logMessage;
        logMessage << "Attempt to update account name for account " << this->userName << " to " << newName << " failed";
        Log::CreateNewEventLogInDB(logMessage, r);
        return false;
    }

    std::stringstream logMessage;
    logMessage << "Updated account name for account " << this->userName << " to " << newName;
    Log::CreateNewEventLogInDB(logMessage, r);
    NotifyAccount("your account username was updated", *this);
    return true;
}


//Admin: Link a device to this user
bool Account::LinkDevice(Device d, ReferenceValidationMechanism *r)
{

    auto con = DatabaseConnection::GetSecureConnection("netadmin", "netadmin");

    if (con == nullptr || !r->CheckAuthorization(2))
    {
        delete con;
        std::stringstream logMessage;
        logMessage << "Attempt to link Device " << d.GetMac() << " to account " << this->userName << "failed";
        Log::CreateNewEventLogInDB(logMessage, r);
        return false;
    }

    try
    {

        sql::PreparedStatement *pstmt;
        pstmt = con->prepareStatement("UPDATE Devices SET LinkedAccount = ? WHERE MacAddress = ?");
        pstmt->setString(1, this->userName);
        pstmt->setString(2, d.GetMac());
        pstmt->execute();
    }
    catch (sql::SQLException &e)
    {

        std::stringstream logMessage;
        logMessage << "Attempt to link Device " << d.GetMac() << " to account " << this->userName << "failed";
        Log::CreateNewEventLogInDB(logMessage, r);
        return false;
    }

    std::stringstream logMessage;
    logMessage << "Linked Device " << d.GetMac() << " to account " << this->userName;
    Log::CreateNewEventLogInDB(logMessage, r);
    NotifyAccount("A device was linked to your account", *this);
    return true;
}


//unlink a device from this users. Returns success
bool Account::UnlinkDevice(Device d, ReferenceValidationMechanism *r)
{

    auto con = DatabaseConnection::GetSecureConnection("netadmin", "netadmin");

    if (con == nullptr || !r->CheckAuthorization(2))
    {
        std::stringstream logMessage;
        logMessage << "Attempt to unlink Device " << d.GetMac() << " to account " << this->userName << "failed";
        Log::CreateNewEventLogInDB(logMessage, r);
        return false;
    }

    try
    {

        sql::PreparedStatement *pstmt;
        pstmt = con->prepareStatement("UPDATE Devices SET LinkedAccount = ? WHERE LinkedAccount = ? AND MacAddress = ?");
        pstmt->setString(1, "");
        pstmt->setString(2, this->userName);
        pstmt->setString(3, d.GetMac());
        pstmt->executeQuery();
    }
    catch (sql::SQLException &e)
    {

        std::stringstream logMessage;
        logMessage << "Attempt to unlink Device " << d.GetMac() << " to account " << this->userName << "failed";
        Log::CreateNewEventLogInDB(logMessage, r);
        return false;
    }

    std::stringstream logMessage;
    logMessage << "Unlinked Device " << d.GetMac() << " to account " << this->userName;
    Log::CreateNewEventLogInDB(logMessage, r);
    NotifyAccount("A device was unlinked from your account", *this);
    return true;
}

//constructor
Account::Account(std::string name, std::string t, std::string cat)
{

    this->type = t;
    this->userName = name;
    this->category = cat;
}

//deconstructor
Account::~Account(){

}


//static create account. -1 cant connect, 0 success, 1 account already exists, 2 passwords dont match, 3 box left empty
int Account::CreateNewAccountInDB(std::string name, std::string password1, std::string password2)
{

    sql::Connection *con = DatabaseConnection::GetSecureConnection("account", "account");

    try
    {

        // check if connection established
        if (con == nullptr)
        {
            return -1;
        }

        // check if passwords match
        if (password1 != password2)
        {
            return 2;
        }

        // check if any empty boxes
        if (name.empty() || password1.empty() || password2.empty())
        {
            return 3;
        }

        sql::PreparedStatement *pstmt;
        sql::ResultSet *result;

        // check if account already exists
        pstmt = con->prepareStatement("SELECT username FROM Accounts WHERE username = ?");
        pstmt->setString(1, name);
        result = pstmt->executeQuery();
        if (result->next())
        {
            delete pstmt;
            delete result;
            return 1;
        }

        // check if connected to local network
        std::string gateMac = Network::GatewayMac();
        std::cout << gateMac << " Mac\n";
        if (gateMac.compare("error") == 0)
        {

            delete pstmt;
            delete result;
            return -1;
        }

        pstmt = con->prepareStatement("SELECT GatewayMac FROM Network WHERE GatewayMac = ?");
        pstmt->setString(1, gateMac);
        result = pstmt->executeQuery();
        std::string type;

        // check if this LAN has an entry yet or not
        if (result->next())
            type = "none"; // if this LAN does have accounts already then the new account is given type "none"

        else
        {

            // if this LAN does not have accounts already then the new account is given type "admin" and this LAN is added to the DB
            type = "admin";
            pstmt = con->prepareStatement("INSERT INTO Network (GatewayMac, FirstAdmin) VALUES (?, ?)");
            pstmt->setString(1, gateMac);
            pstmt->setString(2, name);
            pstmt->executeUpdate();
        }

        // success \/\/\/

        // enter new account into DB
        pstmt = con->prepareStatement("INSERT INTO Accounts (UserName, Type, Password, LoginAttempts, NetCategory) VALUES (?, ?, ?, ?, ?)");
        pstmt->setString(1, name);
        pstmt->setString(2, type);
        pstmt->setString(3, ReferenceValidationMechanism::EncryptString(password1, 34));
        pstmt->setInt(4, 0); // LoginAttempts default value is 0
        pstmt->setString(5, gateMac);

        pstmt->executeUpdate();

        // Create Account object
        Account *a = new Account(name, type, gateMac);
        // log success
        Log::CreateNewEventLogInDB("new account created success", *a);

        delete pstmt;
        delete result;

        return 0; // return success
    }
    catch (sql::SQLException &e)
    {
        std::cerr << "account create exception\n";
        // Log::CreateNewEventLogInDB("new account creation failed", Account(name, "N/A", "N/A"));

        std::cerr << "SQL Exception: ";
        std::cerr << "Error code: " << e.getErrorCode() << std::endl;
        std::cerr << "SQL state: " << e.getSQLState() << std::endl;
        std::cerr << "Error message: " << e.what() << std::endl;
        return -1;
        
    }
}


//
bool Account::SetAccountType(std::string type, ReferenceValidationMechanism *r){

    auto con = DatabaseConnection::GetSecureConnection("netadmin", "netadmin");

    if (con == nullptr || !r->CheckAuthorization(2) || !(type.compare("admin") == 0 || type.compare("engineer") == 0 || type.compare("none") == 0)){

        std::stringstream logMessage;
        logMessage << "Attempt to update account " << this->userName << " from type " << this->category << " to " << type << " failed";
        Log::CreateNewEventLogInDB(logMessage, r);
        return false;
    }

    try
    {

        sql::PreparedStatement *pstmt;
        sql::ResultSet *result;
        pstmt = con->prepareStatement("UPDATE Accounts SET Type = ? WHERE UserName = ? AND NetCategory = ? AND Type != ?");
        pstmt->setString(1, type);
        pstmt->setString(2, this->userName);
        pstmt->setString(3, r->GetAccount().GetAccountCat());
        pstmt->setString(4, "admin");
        pstmt->executeQuery();

    }
    catch (sql::SQLException &e)
    {

        std::stringstream logMessage;
        logMessage << "Attempt to update account " << this->userName << " from type " << this->category << " to " << type << " failed";
        Log::CreateNewEventLogInDB(logMessage, r);
        return false;
    }

    std::stringstream logMessage;
    logMessage << "Updated account " << this->userName << " from type " << this->category << " to " << type << " successfully";
    Log::CreateNewEventLogInDB(logMessage, r);
    NotifyAccount("your account type was reset", *this);
    return true;

}


bool Account::ResetLoginAttempts(ReferenceValidationMechanism *r){

    auto con = DatabaseConnection::GetSecureConnection("netadmin", "netadmin");

    if (con == nullptr || !r->CheckAuthorization(2)){

        std::stringstream logMessage;
        logMessage << "Attempt to reset login attempts on account " << this->userName << " from type " << this->category << " to " << type << " failed";
        Log::CreateNewEventLogInDB(logMessage, r);
        return false;
    }

    try
    {

        sql::PreparedStatement *pstmt;
        sql::ResultSet *result;
        pstmt = con->prepareStatement("UPDATE Accounts SET LoginAttempts = ? WHERE UserName = ? AND NetCategory = ?");
        pstmt->setInt(1, 0);
        pstmt->setString(2, this->userName);
        pstmt->setString(3, r->GetAccount().GetAccountCat());
        pstmt->executeQuery();

    }
    catch (sql::SQLException &e)
    {

        std::stringstream logMessage;
        logMessage << "Attempt to reset login attempts on account " << this->userName << " from type " << this->category << " to " << type << " failed";
        Log::CreateNewEventLogInDB(logMessage, r);
        return false;
    }

    std::stringstream logMessage;
    logMessage << "Reset login attempts for account " << this->userName << " successfully";
    Log::CreateNewEventLogInDB(logMessage, r);
    NotifyAccount("your login attempts were reset", *this);
    return true;


}


std::vector<std::string> Account::RetrieveAccountMessages(ReferenceValidationMechanism *r){

    auto con = DatabaseConnection::GetSecureConnection("account", "account");

    std::vector<std::string> temp;

    if (con == nullptr){
        return temp;
    }

    try
    {

        sql::PreparedStatement *pstmt;
        sql::ResultSet *result;
        pstmt = con->prepareStatement("SELECT Message FROM AccountMessages WHERE Account = ?");
        pstmt->setString(1, this->userName);
        sql::ResultSet *res = pstmt->executeQuery();

        while(res->next()){
            std::string m = res->getString("Message");
            temp.push_back(m);
        }

    }
    catch (sql::SQLException &e)
    {
        temp.clear();
        return temp;
    }

    return temp;

}


bool Account::RetrieveLinkedDevices(ReferenceValidationMechanism *r){

    auto con = DatabaseConnection::GetSecureConnection("netadmin", "netadmin");

    if (con == nullptr || !r->CheckAuthorization(2)){

        std::stringstream logMessage;
        logMessage << "Attempt to retrieve linked devices on account " << this->userName << " failed";
        Log::CreateNewEventLogInDB(logMessage, r);
        return false;
    }

    try
    {

        sql::PreparedStatement *pstmt;
        sql::ResultSet *result;
        pstmt = con->prepareStatement("SELECT * FROM Devices WHERE LinkedAccount = ? AND Network = ?");
        pstmt->setString(1, this->userName);
        pstmt->setString(2, r->GetAccount().GetAccountCat());
        sql::ResultSet *res = pstmt->executeQuery();

        while(res->next()){
            Device d(res->getString("MacAddress"), res->getString("Ipv4"), res->getBoolean("Wired"), res->getString("DeviceName"), res->getInt("PositionX"), res->getInt("PositionY"), false);
            this->linkedDevices.push_back(d);
        }

    }
    catch (sql::SQLException &e)
    {

        std::stringstream logMessage;
        logMessage << "Attempt to retrieve linked devices on account " << this->userName << " failed";
        Log::CreateNewEventLogInDB(logMessage, r);
        return false;
    }

    std::stringstream logMessage;
    logMessage << "Retrieved linked devices on account " << this->userName << " successfully";
    Log::CreateNewEventLogInDB(logMessage, r);
    return true;


}


bool Account::ResetPassword(std::string newPass1, std::string newPass2, ReferenceValidationMechanism *r){

    auto con = DatabaseConnection::GetSecureConnection("netadmin", "netadmin");

    if (con == nullptr || !r->CheckAuthorization(2)){

        std::stringstream logMessage;
        logMessage << "Attempt to reset password on account " << this->userName << " failed";
        Log::CreateNewEventLogInDB(logMessage, r);
        return false;
    }

    if(newPass1.compare(newPass2) != 0)
        return false;

    try
    {

         sql::PreparedStatement *pstmt;
        sql::ResultSet *result;
        pstmt = con->prepareStatement("UPDATE Accounts SET Password = ? WHERE UserName = ? AND NetCategory = ?");
        pstmt->setString(1, ReferenceValidationMechanism::EncryptString(newPass1, 34));
        pstmt->setString(2, this->userName);
        pstmt->setString(3, r->GetAccount().GetAccountCat());
        pstmt->executeQuery();


    }
    catch (sql::SQLException &e)
    {

        std::stringstream logMessage;
        logMessage << "Attempt to reset password on account " << this->userName << " failed";
        Log::CreateNewEventLogInDB(logMessage, r);
        return false;
    }

    std::stringstream logMessage;
    logMessage << "Reset login attempts for account " << this->userName << " successfully";
    Log::CreateNewEventLogInDB(logMessage, r);
    NotifyAccount("your password was reset", *this);
    return true;


}


void Account::SendMessageToAdmins(std::string m){

     auto con = DatabaseConnection::GetSecureConnection("account", "account");

    try{

        sql::PreparedStatement *pstmt;
        sql::ResultSet *result;
        pstmt = con->prepareStatement("SELECT UserName FROM Accounts WHERE Network = ?");
        pstmt->setString(1, Network::GatewayMac());
        sql::ResultSet *res = pstmt->executeQuery();

        while(res->next()){

            pstmt = con->prepareStatement("INSERT INTO AccountMessages (Account, Message) VALUES (?, ?)");
            pstmt->setString(1, res->getString("UserName"));
            pstmt->setString(2, m);
            pstmt->executeQuery();

        }

        
       


    }
    catch (sql::SQLException &e){
        return;
    }

}


void Account::NotifyAccount(std::string m, Account a){

     auto con = DatabaseConnection::GetSecureConnection("account", "account");

    try{

        sql::PreparedStatement *pstmt;
        sql::ResultSet *result;

        pstmt = con->prepareStatement("INSERT INTO AccountMessages (Account, Message) VALUES (?, ?)");
        pstmt->setString(1, a.userName);
        pstmt->setString(2, m);
        pstmt->executeQuery();


        
       


    }
    catch (sql::SQLException &e){
        return;
    }

}


//getters
std::string Account::GetAccountType()
{

    return this->type;
}

std::string Account::GetAccountName()
{

    return this->userName;
}

std::string Account::GetAccountCat()
{

    return this->category;
}

std::vector<Device> Account::GetLinkedDeviceVec(){

    return this->linkedDevices;

}
