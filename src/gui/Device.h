/*
 * Device.h
 * Created on Nov 5, 2023
 *
 * Author: Ubljudok
 */

#pragma once
#include <string>


struct Device {
	
	//Identification
	std::string name;
	std::string mac;
	//TODO: Consult other group members on other Idenification info
	


	//Positional Information
	int posX;
	int posY;
	

	
	//Color (Depends on if it is selected)
	wxColour color;

}
