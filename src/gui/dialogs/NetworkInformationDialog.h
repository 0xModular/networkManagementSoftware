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

		NetworkInformationDialog(wxWindow* parent, ReferenceValidationMechanism* rvm); //Constructor
                ~NetworkInformationDeviceDialog() noexcept {}; //Destructor

	private:

		//Constructor Functions
		void CreateControls();
		void ConnectControls();



		//RVM
		ReferenceValidationMechanism* rvm;



		//ControlVariables
		wxStaticText* info;
		wxButton* ok;



		//Event Handler Functions
		void OnOk(wxCommandEvent & event);
};
