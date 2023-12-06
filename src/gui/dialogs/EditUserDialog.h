/*
 * EditUserDialog.h
 * Created on: Nov 15, 2023
 *
 * Author: Ubljudok
 */

#pragma once
#include <wx/wx.h>
#include <wx/statline.h>
#include <wx/radiobut.h>

#include <string>

#include "../../ReferenceValidationMechanism.h"

#include "EditUsernameDialog.h"
#include "EditPasswordDialog.h"

class ReferenceValidationMechanism;

class EditUserDialog : public wxDialog {

        public:

                EditUserDialog(wxWindow* parent, ReferenceValidationMechanism* rvm, Account* user); //Constructor
                ~EditUserDialog() noexcept {}; //Destructor

        private:

                //Constructor Functions
                void CreateControls();
                void ConnectControls();



                //RVM and User
                ReferenceValidationMechanism* rvm;
		Account* user;



                //Control Variables
		wxButton* changeUsername;
		wxButton* changePassword;

		wxButton* submit;
		wxButton* cancel;

		wxRadioBox* access;

		//--Button IDs--//
		inline static const int ID_USER = 0;
		inline static const int ID_PASS = 1;



		//Event Handler Functions
		void OnChangeUsername(wxCommandEvent & event);
		void OnChangePassword(wxCommandEvent & event);
		void OnSubmit(wxCommandEvent & event);
		void OnCancel(wxCommandEvent & event);

};

