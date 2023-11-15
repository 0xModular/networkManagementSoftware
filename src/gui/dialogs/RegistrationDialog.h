/*
 * RegistrationDialog.h
 * Created on: Nov 1, 2023
 *
 * Author: Ubljudok
 */

#pragma once
#include <wx/wx.h>
#include <wx/statline.h>

#include <string>
#include <vector>

#include "../../ReferenceValidationMechanism.h"

class ReferenceValidationMechanism;

class RegistrationDialog : public wxDialog {

	public:
	
		RegistrationDialog(wxWindow* parent, ReferenceValidationMechanism* rvm); //Constructor
		virtual ~RegistrationDialog() noexcept {}; //Destructor
	
	private:

		//Misc Functions
		void CreateControls();
		void ConnectControls();
		bool ComparePasswords();
		

		//Event Handler Functions
		void OnShowPassword(wxCommandEvent & event);

		void OnCancel(wxCommandEvent & event);
		void OnSubmit(wxCommandEvent & event);



		//Control Variables
		wxStaticText* warningText;

		wxTextCtrl* usernameEntry;

		wxTextCtrl* passwordEntry;
		wxTextCtrl* passwordReentry;
		wxCheckBox* showPassword;

		wxButton* cancel;
		wxButton* submit;



		//Misc
		ReferenceValidationMechanism* rvm;
		
		std::string username;
		std::string password;
		std::string password2;

};
