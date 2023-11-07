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

#include "../structures/Credentials.h"

class LoginDialog : public wxDialog {
	
	public:
		
		LoginDialog(wxWindow* parent, int maxAttempts, struct Credentials* cred, bool wrongPassword); //Constuctor
		virtual ~LoginDialog() noexcept {}; //Destructor

		inline static const int ID_RGSTR = 2;
		
		struct Credentials GetCredentials();

	private:
		
		//Misc Functions
		void CreateControls(bool wrongPassword);
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
		int attempts;
		int maxAttempts;

		struct Credentials* cred;

		std::string username;
		std::string password;

};
