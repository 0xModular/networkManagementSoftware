/*
 * TwoFactorAuthenticationDialog.h
 * Created on Nov 1, 2023
 *
 * Author: Ubljudok
 */

#pragma once
#include <wx/wx.h>
#include <wx/statline.h>
#include <string>

#include "../../ReferenceValidationMechanism.h"

class ReferenceValidationMechanism;

class TwoFactorAuthenticationDialog : public wxDialog {

	public:

		TwoFactorAuthenticationDialog(wxWindow* parent, int code, ReferenceValidationMechanism* rvm); //Constructor
		virtual ~TwoFactorAuthenticationDialog() noexcept {};
		
		void UpdateCode(int newCode);

	private:

		//Misc Functions
		void CreateControls();
		void ConnectControls();
		void ProcessInput();

		//Event Handler Functions
		void OnCancel(wxCommandEvent & event);
		void OnSubmit(wxCommandEvent & event);



		//Control Variables
		wxStaticText* warningText;

		wxTextCtrl* entry;

		wxButton* cancel;
		wxButton* submit;



		//Misc Variables
		int enteredCode; //Process wxString into std::string into int;
		int code;

		ReferenceValidationMechanism* rvm;

};
