/*
 * EditUsernameDialog.h
 * Created on: Nov 29, 2023
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

class EditUsernameDialog : public wxDialog {

        public:

                EditUsernameDialog(wxWindow* parent, ReferenceValidationMechanism* rvm, Account* user); //Constructor
                ~EditUsernameDialog() noexcept {}; //Destructor

        private:

                //Constructor Functions
                void CreateControls();
                void ConnectControls();



                //RVM and User
                ReferenceValidationMechanism* rvm;
		Account* user;



                //Control Variables
		wxStaticText* oldUsername;

		wxTextCtrl* newUsernameEntry;
		wxTextCtrl* newUsernameReentry;

		wxButton* submit;
		wxButton* cancel;



		//Event Handler Functions
		void OnSubmit(wxCommandEvent & event);
                void OnCancel(wxCommandEvent & event);

};

