-- Author: Layne 

-- Copy and paste all this code and execute it on a fresh sql server to completly set it up for use with the network managment software
-- As long as you execute all this code in order you shouldn't need to do any other setup on the sql server

CREATE DATABASE `test1` 
USE test1;

CREATE TABLE `Network` (
  `GatewayMac` varchar(20) NOT NULL,
  `FirstAdmin` varchar(255) NOT NULL,
  PRIMARY KEY (`GatewayMac`)
);

CREATE TABLE `Accounts` (
  `UserName` varchar(255) NOT NULL,
  `Type` varchar(8) NOT NULL,
  `Password` varchar(255) NOT NULL,
  `NetCategory` varchar(255) NOT NULL,
  `LoginAttempts` int DEFAULT NULL,
  PRIMARY KEY (`UserName`),
  KEY `fk_Accounts_1_idx` (`NetCategory`),
  CONSTRAINT `fk_Accounts_1` FOREIGN KEY (`NetCategory`) REFERENCES `Network` (`GatewayMac`)
); 

CREATE TABLE `AccountMessages` (
  `messageID` int NOT NULL AUTO_INCREMENT,
  `Account` varchar(255) NOT NULL,
  `Message` varchar(8191) NOT NULL,
  PRIMARY KEY (`messageID`),
  KEY `Account` (`Account`),
  CONSTRAINT `AccountMessages_ibfk_1` FOREIGN KEY (`Account`) REFERENCES `Accounts` (`UserName`)
); 

CREATE TABLE `Devices` (
  `MacAddress` varchar(20) NOT NULL,
  `LinkedAccount` varchar(255) DEFAULT NULL,
  `PositionX` int DEFAULT NULL,
  `PositionY` int DEFAULT NULL,
  `Ipv4` varchar(255) DEFAULT NULL,
  `DeviceName` varchar(255) DEFAULT NULL,
  `Wired` tinyint(1) DEFAULT NULL,
  `GenericDeviceId` int NOT NULL AUTO_INCREMENT,
  `Network` varchar(20) NOT NULL,
  PRIMARY KEY (`GenericDeviceId`),
  KEY `LinkedAccount` (`LinkedAccount`),
  KEY `fk_Devices_1_idx` (`Network`),
  CONSTRAINT `Devices_ibfk_1` FOREIGN KEY (`LinkedAccount`) REFERENCES `Accounts` (`UserName`),
  CONSTRAINT `fk_Devices_1` FOREIGN KEY (`Network`) REFERENCES `Network` (`GatewayMac`)
) 

CREATE TABLE `DevicePrivacyFlags` (
  `FlagNum` varchar(255) NOT NULL,
  `Device` int NOT NULL,
  `Flag` varchar(63) NOT NULL,
  PRIMARY KEY (`FlagNum`),
  KEY `Device` (`Device`),
  CONSTRAINT `DevicePrivacyFlags_ibfk_1` FOREIGN KEY (`Device`) REFERENCES `Devices` (`GenericDeviceId`)
); 

CREATE TABLE `Logs` (
  `LogNumber` int NOT NULL AUTO_INCREMENT,
  `Category` varchar(255) NOT NULL,
  `Time` int DEFAULT NULL,
  `Account` varchar(255) NOT NULL,
  `Event` varchar(4095) DEFAULT NULL,
  PRIMARY KEY (`LogNumber`),
  KEY `Account` (`Account`),
  KEY `fk_Logs_1_idx` (`Category`),
  CONSTRAINT `fk_Logs_1` FOREIGN KEY (`Category`) REFERENCES `Network` (`GatewayMac`),
  CONSTRAINT `Logs_ibfk_2` FOREIGN KEY (`Account`) REFERENCES `Accounts` (`UserName`)
); 

CREATE TABLE `NetworkNotes` (
  `GenericNoteId` int NOT NULL AUTO_INCREMENT,
  `PosX` int NOT NULL,
  `PosY` int NOT NULL,
  `Message` varchar(4096) NOT NULL,
  `Network` varchar(20) NOT NULL,
  PRIMARY KEY (`GenericNoteId`),
  KEY `fk_new_table_1_idx` (`Network`),
  CONSTRAINT `fk_new_table_1` FOREIGN KEY (`Network`) REFERENCES `Network` (`GatewayMac`)
);


INSERT INTO Network (GatewayMac, FirstAdmin) VALUES ("unknown", "unknown");
INSERT INTO Accounts (UserName, Type, Password, NetCategory, LoginAttempts) VALUES ("LayneWasHere", "admin", "ThisEasterEggIsForEva", "unknown", 12 + 5);


CREATE USER 'account'@'localhost' IDENTIFIED BY 'account';
GRANT INSERT, SELECT ON test1.Accounts TO 'account'@'localhost';
GRANT INSERT, SELECT ON test1.Network TO 'account'@'localhost';
GRANT INSERT, SELECT ON test1.AccountMessages TO 'account'@'localhost';
FLUSH PRIVILEGES;


CREATE USER 'login'@'localhost' IDENTIFIED BY 'login';
GRANT UPDATE, SELECT ON test1.Accounts TO 'login'@'localhost';
FLUSH PRIVILEGES;


CREATE USER 'netadmin'@'localhost' IDENTIFIED BY 'netadmin';
GRANT INSERT ON test1.AccountMessages TO 'netadmin'@'localhost';
GRANT UPDATE, SELECT, DELETE ON test1.Accounts TO 'netadmin'@'localhost';
GRANT UPDATE, SELECT ON test1.Devices TO 'netadmin'@'localhost';
GRANT SELECT ON test1.Logs TO 'netadmin'@'localhost';
FLUSH PRIVILEGES;


CREATE USER 'network'@'localhost' IDENTIFIED BY 'network';
GRANT UPDATE, SELECT, INSERT ON test1.Devices TO 'network'@'localhost';
GRANT SELECT, INSERT ON test1.DeviceNetworks TO 'network'@'localhost';
GRANT SELECT, UPDATE, INSERT, DELETE ON test1.NetworkNotes TO 'network'@'localhost';
FLUSH PRIVILEGES;


CREATE USER 'log'@'localhost' IDENTIFIED BY 'log';
GRANT INSERT ON test1.Logs TO 'log'@'localhost';
FLUSH PRIVILEGES;


