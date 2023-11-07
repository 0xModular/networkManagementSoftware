/*
 * Registration.h
 * Created on: Nov 1, 2023
 *
 * Author: Ubljudok
 */

#pragma once
#include <wx/wx.h>
#include <string>
#include <vector>

class Registration : public wxDialog {

	public:
	
		Registration(wxWindow* parent, std::vector<std::string> usernames); //Constructor
		virtual ~Registration(); //Destructor
	
	private:

		//Misc Functions
		void CreateControls();
		void ConnectControls();

		

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



		//Misc Variables
		std::string username;
		std::string password;
		std::string password2;

};
