-- These are the first-draft tables and WILL NOT WORK anymore. 

CREATE TABLE Network(
    Category varchar(255) NOT NULL,
    Location varchar(255) NOT NULL,
    PRIMARY KEY (Category)
);

CREATE TABLE Accounts (
    UserName varchar(255) NOT NULL,
    Type varchar(8) NOT NULL,
    Password varchar(255) NOT NULL,
    LoginAttempts INT(2),
    PRIMARY KEY (UserName),
    FOREIGN KEY (Category) REFERENCES Network(Category)
);

CREATE TABLE Logs (
    LogNumber INT AUTO_INCREMENT PRIMARY KEY,
    Category varchar(255) NOT NULL,
    Time INT(255),
    Account varchar(255) NOT NULL,
    Event varchar(4095),
    FOREIGN KEY (Category) REFERENCES Network(Category),
    FOREIGN KEY (Account) REFERENCES Accounts(UserName)
);

CREATE TABLE Devices (
    MacAddress varchar(12) NOT NULL,
    LinkedAccount varchar(255) null,
    PositionX INT(10000) null,
    PositionY INT(10000) null,
    Ipv4 varchar(255),
    DeviceName varchar(255),
    Wired BOOLEAN,
    Network varchar(255) NOT NULL,
    PRIMARY KEY (MacAddress),
    FOREIGN KEY (LinkedAccount) REFERENCES Accounts(UserName),
    FOREIGN KEY (Network) REFERENCES Network(Category)
);

CREATE TABLE DevicePrivacyFlags (
    FlagNum varchar(255) NOT NULL,
    Device varchar(12) NOT NULL,
    Flag varchar(63) NOT NULL,
    PRIMARY KEY (FlagNum),
    FOREIGN KEY (Device) REFERENCES Devices(MacAddress)
);

CREATE TABLE DeviceNetwork(
    CategoryId INT AUTO_INCREMENT PRIMARY KEY,
    Category varchar(255) NOT NULL,
    Device varchar(255) NOT NULL,
    PRIMARY KEY (CategoryNum),
    FOREIGN KEY (Device) REFERENCES Devices(MacAddress),
    FOREIGN KEY (Category) REFERENCES Network(Category)
);
 
CREATE TABLE AccountMessages(
    messageID INT AUTO_INCREMENT PRIMARY KEY,
    Account varchar(255) NOT NULL,
    message varchar(8191) NOT NULL,
    FOREIGN KEY (Account) REFERENCES Accounts(UserName)
)

 
