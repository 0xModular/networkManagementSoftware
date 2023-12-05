/*
 * NetworkField.cpp
 * Created on: Nov 1, 2023
 *
 * Author: Ubljudok
 */

#include "NetworkField.h"

//Constructor

NetworkField::NetworkField(wxWindow *parent, wxWindowID id, const wxPoint &pos, const wxSize &size) : wxWindow(parent, id, pos, size) {

	//Set Color
	this->SetBackgroundColour(*wxLIGHT_GREY);

}


//Setters and Getters
void NetworkField::SetMode(int newMode) {

	this->mode = newMode;

}

int NetworkField::GetMode() {

	return this->mode;

}



//Event Handler Functions
void NetworkField::OnPaint(wxPaintEvent & event) {

}

void NetworkField::DrawOnContext(wxGraphicsContext *gc) {

}

void NetworkField::MouseOverDevice(wxMouseEvent & event) {

}

void NetworkField::MouseLeaveDevice(wxMouseEvent & event) {

}

void NetworkField::OnMouseLeftDown(wxMouseEvent & event) {
	


}

void NetworkField::OnMouseMovement(wxMouseEvent & event) {



}
                
void NetworkField::OnMouseLeftUp(wxMouseEvent & event) {



}

void NetworkField::OnMouseScroll(wxMouseEvent & event) {

	//Zoom

}

void NetworkField::OnContextMenuEvent(wxContextMenuEvent & event) {



}
