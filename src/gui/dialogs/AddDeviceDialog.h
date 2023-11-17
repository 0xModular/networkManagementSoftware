/*
 * AddDeviceDialog.h
 * Created on Nov 15, 2023
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

class AddDeviceDialog : public wxDialog {

	public:

		AddDeviceDialog(wxWindow* parent, ReferenceValidationMechanism* rvm); //Constructor
		~AddDeviceDialog() noexcept {}; //Destructor
	
	private:

		//Constructor Functions
		void CreateControls();
		void ConnectControls();



		//RVM
		ReferenceValidationMechanism* rvm;



		//Control Variables
		wxTextCtrl* name;
		wxTextCtrl* MAC;
		wxTextCtrl* IP;
		
		wxCheckBox* wired;

		wxStaticText* warningText;

		wxButton* ok;
		wxButton* cancel;



		//Event Handler Functions
		void OnOk(wxCommandEvent & event);
		void OnCancel(wxCommandEvent & event);



		//Status Constants
		inline static const int ID_NOCONNECTION = -1;
		inline static const int ID_SUCCESSFUL = 0;
		inline static const int ID_DOESNTEXIST = 1;
		inline static const int ID_FIELDEMPTY = 2;

};
