CREATE DATABASE `test1`;
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
  `message` varchar(8191) NOT NULL,
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
  PRIMARY KEY (`MacAddress`),
  KEY `LinkedAccount` (`LinkedAccount`),
  CONSTRAINT `Devices_ibfk_1` FOREIGN KEY (`LinkedAccount`) REFERENCES `Accounts` (`UserName`)
);

CREATE TABLE `DeviceNetworks` (
  `CategoryNum` int NOT NULL AUTO_INCREMENT,
  `Category` varchar(20) NOT NULL,
  `DeviceMac` varchar(20) NOT NULL,
  PRIMARY KEY (`CategoryNum`),
  KEY `AccountNetworkCategories_ibfk_1_idx` (`DeviceMac`),
  KEY `fk_DeviceNetworks_1_idx` (`Category`),
  CONSTRAINT `DeviceNetworks_ibfk_1` FOREIGN KEY (`DeviceMac`) REFERENCES `Devices` (`MacAddress`) ON DELETE RESTRICT ON UPDATE RESTRICT,
  CONSTRAINT `fk_DeviceNetworks_1` FOREIGN KEY (`Category`) REFERENCES `Network` (`GatewayMac`)
); 

CREATE TABLE `DevicePrivacyFlags` (
  `FlagNum` varchar(255) NOT NULL,
  `Device` varchar(12) NOT NULL,
  `Flag` varchar(63) NOT NULL,
  PRIMARY KEY (`FlagNum`),
  KEY `Device` (`Device`),
  CONSTRAINT `DevicePrivacyFlags_ibfk_1` FOREIGN KEY (`Device`) REFERENCES `Devices` (`MacAddress`)
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








