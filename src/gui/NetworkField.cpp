/*
 * NetworkField.cpp
 * Created on: Nov 1, 2023
 *
 * Author: Ubljudok
 */

#include "NetworkField.h"
#include "structures/Device.h"
#include "structures/Connection.h"
#include "structures/Note.h"


//Constructor

NetworkField::NetworkField(wxWindow *parent, wxWindowID id, const wxPoint &pos, const wxSize &size) : wxWindow(parent, id, pos, size) {

	//Set Color
	this->SetBackgroundColour(*wxLIGHT_GREY);

	//Set Default Mode - SELECTION_MODE
	this->mode = 0;

}


//Setters and Getters
void NetworkField::setMode(int newMode) {
	this->mode = newMode;
}

int NetworkField::getMode() {
	return this->mode;
}



//Event Handler Functions
void NetworkField::OnPaint(wxPaintEvent & event){

}

void NetworkField::DrawDeviceOnContext(wxGraphicsContext *gc){

}

void NetworkField::OnMouseLeftDown(wxMouseEvent & event){

}

void NetworkField::OnMouseMovement(wxMouseEvent & event){

}
                
void NetworkField::OnMouseLeftUp(wxMouseEvent & event){

}

void NetworkField::OnContextMenuEvent(wxContextMenuEvent & event){

}
                
void NetworkField::BuildContextMenu(){

}

