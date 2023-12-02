/*
 * DeviceOnField.h
 * Created on Nov 5, 2023
 *
 * Author: Ubljudok
 */

#pragma once
#include <wx/wx.h>
#include <string>

struct Device_ {
	
	//Associated Device
	//Device	

	//postitional info is saved to server. The device object in the backend also has int x and int y. Make sure
	//to update those too so that it gets saved

	//Positional Information
	wxPoint position;
	

	
	//Color (Depends on if it is selected)
	wxColour color;

};
