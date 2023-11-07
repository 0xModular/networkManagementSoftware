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
	
	if (this->mode == this->SELECTION_MODE){
	
		if (mouseOverDevice) {
		
			if (!isDragging) {
			
				//Add or Remove Device to/from Selection Buffer

				//Mark Device as Selected	
			
			} else {
			
				//Move Devices in Selection Buffer

			}
		
		} else {
		
			//Clear Selection Buffer
		
		}


	} else if (this->mode == this->TEST_CONNECTION_MODE) {

		if (mouseOverDevice) {
                
                	//Add Device to Selection Buffer
			
			//If Two Devices in Selection Buffer, then test
                
                } else {
                
                	//Clear Selection Buffer
                
                }


	} else if (this->mode == this->ADD_NOTE_MODE) {

		if (mouseOverDevice) {

			//Add Note

			//Shift Note Position

                } else {

			//Add Note

                }

	}

}

void NetworkField::OnMouseMovement(wxMouseEvent & event) {

	//If Moving, isDragging = true... or smth like that

	//Get Mouse Position

}
                
void NetworkField::OnMouseLeftUp(wxMouseEvent & event) {
	
	if (this->mode == this->ADD_DEVICE_MODE) {

		if (mouseOverDevice) {
                
                	//Device Prompt

			//shift coordinates

                        //Add Device in Backend

                        //Add Device on Field
                        
                        //this->devices.push_back(Device);
                
                } else {
                
                	//Device Prompt

                        //Add Device in Backend

                        //Add Device on Field
                        
                        //this->devices.push_back(Device);
                
                }


	} else if (this->mode == this->TEST_CONNECTION_MODE) {

		//Switch to Selection Mode

	} else if (this->mode == this->ADD_NOTE_MODE) {

		//Switch to Selection Mode

	}
}

void NetworkField::OnMouseScroll(wxMouseEvent & event) {

	//Zoom

}

void NetworkField::OnContextMenuEvent(wxContextMenuEvent & event) {

	if (mouseOverDevice) {
	
		//Build Device Context Menu
	
	} else {
	
		//Build Network Context Menu
	
	}

}
