/*
 * LoginDialog.h
 * Created on: Oct 26, 2023
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

class LoginDialog : public wxDialog {
	
	public:
		
		LoginDialog(wxWindow* parent, ReferenceValidationMechanism* rvm); //Constuctor
		virtual ~LoginDialog() noexcept {}; //Destructor

		inline static const int ID_RGSTR = 2;
		
	private:

		//Misc Functions
		void CreateControls();
		void ConnectControls();



		//Event Handler Functions
		void OnShowPassword(wxCommandEvent & event);
		
		void OnOk(wxCommandEvent & event);
		void OnCancel(wxCommandEvent & event);
		void OnRegister(wxCommandEvent & event);



		//Control Variables
		wxStaticText* warningText;
		
		wxTextCtrl* usernameEntry;
		
		wxTextCtrl* passwordEntry;
		wxCheckBox* showPassword;

		wxButton* ok;
		wxButton* cancel;
		wxButton* rgstr;



		//Misc Variables
		std::string username;
		std::string password;

		

		//RVM
		ReferenceValidationMechanism* rvm;



		//Status Constants
		inline static const int ID_NOCONNECTION = -1;
		inline static const int ID_SUCCESSFUL = 0;
		inline static const int ID_NOTFOUND = 1;
		inline static const int ID_WRONGPASSWORD = 2;
		inline static const int ID_TOOMANYATTEMPTS = 3;
		inline static const int ID_EMPTYFIELD = 4;
};
