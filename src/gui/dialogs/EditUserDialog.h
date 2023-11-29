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

class ReferenceValidationMechanism;

class EditUserDialog : public wxDialog {

        public:

                EditUserDialog(wxWindow* parent, ReferenceValidationMechanism* rvm); //Constructor
                ~EditUserDialog() noexcept {}; //Destructor

        private:

                //Constructor Functions
                void CreateControls();
                void ConnectControls();



                //RVM
                ReferenceValidationMechanism* rvm;



                //Control Variables
		wxStaticText* currentUsername;
		wxStaticText* currentPassword;

		wxButton* changeUsername;
		wxButton* changePassword;

		wxButton* submit;
		wxButton* cancel;

		wxRadioBox* access;



		//Event Handler Functions
		void OnChangeUsername(wxCommandEvent & event);
		void OnChangePassword(wxCommandEvent & event);
		void OnSubmit(wxCommandEvent & event);
		void OnCancel(wxCommandEvent & event);

};

