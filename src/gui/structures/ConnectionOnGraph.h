/*
 * ConnectionOnGraph.h
 * Created on: Nov 5, 2023
 *
 * Author: Ubljudok
 */

#pragma once
#include "DeviceOnGraph.h"

struct Connection {
	
	//Type
	bool isWireless;



	//Devices
	Device* deviceOne;
	Device* deviceTwo;
	
};
