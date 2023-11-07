/*
 * LoginDialog.h
 * Created on: Oct 26, 2023
 *
 * Author: Ubljudok
 */

#pragma once
#include <wx/wx.h>
#include <string>
#include <vector>

class LoginDialog : public wxDialog {
	
	public:
		
		LoginDialog(wxWindow* parent, std::vector<std::string> usernames, std::vector<std::string> passwords, int maxAttempts); //Constuctor
		virtual ~LoginDialog(); //Destructor

	private:
		
		//Misc Functions
		void CreateControls();
		void ConnectControls();



		//Event Handler Functions
		void OnShowPassword(wxCommandEvent & event);
		
		void OnOk(wxCommandEvent & event);
		void OnCancel(wxCommandEvent & event);
		void OnRegisterNewAccount(wxCommandEvent & event);



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
		int attempts;
		int maxAttempts;

};
