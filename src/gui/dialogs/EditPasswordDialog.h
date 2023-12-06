/*
 * EditPasswordDialog.h
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

class EditPasswordDialog : public wxDialog {

        public:

                EditPasswordDialog(wxWindow* parent, ReferenceValidationMechanism* rvm, Account* user); //Constructor
                ~EditPasswordDialog() noexcept {}; //Destructor

        private:

                //Constructor Functions
                void CreateControls();
                void ConnectControls();



                //RVM and User
                ReferenceValidationMechanism* rvm;
		Account* user;



                //Control Variables
                wxStaticText* oldPassword;

                wxTextCtrl* newPasswordEntry;
                wxTextCtrl* newPasswordReentry;

		wxCheckBox* showPassword;
                wxButton* submit;
                wxButton* cancel;



                //Event Handler Functions
		void OnShowPassword(wxCommandEvent & event);
                void OnSubmit(wxCommandEvent & event);
                void OnCancel(wxCommandEvent & event);

};

