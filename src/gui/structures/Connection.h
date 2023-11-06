/*
 * Connection.h
 * Created on: Nov 5, 2023
 *
 * Author: Ubljudok
 */

#pragma once
#include "Device.h"

struct Connection {
	
	//Type
	bool isWireless;



	//Devices
	Device* deviceOne;
	Device* deviceTwo;
	
};
