/*
 * AddUserAccessDialog.h
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

class AddUserAccessDialog : public wxDialog {

        public:

                AddUserAccessDialog(wxWindow* parent, ReferenceValidationMechanism* rvm, Account* user); //Constructor
                ~AddUserAccessDialog() noexcept {}; //Destructor

        private:

                //Constructor Functions
                void CreateControls();
                void ConnectControls();



                //RVM
                ReferenceValidationMechanism* rvm;
		Account* user;



		//Control Variables
		wxStaticText* username;
		wxStaticText* password;

		wxRadioBox* access;

		wxButton* submit;
		wxButton* cancel;



		//Event Handler Functions
		void OnSubmit(wxCommandEvent & event);
		void OnCancel(wxCommandEvent & event);

};
