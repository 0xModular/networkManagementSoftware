/*
 * NetworkField.cpp
 * Created on: Nov 1, 2023
 *
 * Author: Ubljudok
 */

#include "NetworkField.h"
#include "Device.h"
#include "Connection.h"
#include "Note.h"


//Constructor

NetworkField::NetworkField(wxWindow *parent, wxWindowID id, const wxPoint &pos, const wxSize &size) : wxWindow(parent, id, pos, size) {

	//Set Color
	this->SetBackgroundColour(*wxLIGHT_GREY);

	//Set Default Mode - SELECTION_MODE
	this->mode = 0;

}
