/*
 * NetworkInformationDialog.h
 * Created on Nov 7, 2023
 *
 * Author: Ubljudok
 */

#pragma once
#include <wx/wx.h>
#include <wx/statline.h>
#include <wx/radiobut.h>

#include <string>

#include "../../ReferenceValidationMechanism.h"

class ReferenceValidationMechanism;

class NetworkInformationDialog : public wxDialog {

	public:

		NetworkInformationDialog(wxWindow* parent, Network* net); //Constructor
                ~NetworkInformationDialog() noexcept {}; //Destructor

	private:

		//Constructor Functions
		void CreateControls();
		void ConnectControls();



		//Network
		Network* net;



		//Panels
		wxScrolledWindow* infoPanel;



		//ControlVariables
		wxStaticText* info;
		wxButton* ok;



		//Event Handler Functions
		void OnOk(wxCommandEvent & event);

};
