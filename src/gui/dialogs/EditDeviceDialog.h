/*
 * EditDeviceDialog.h
 * Created on Nov 15, 2023
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

class EditDeviceDialog : public wxDialog {

        public:

                EditDeviceDialog(wxWindow* parent, ReferenceValidationMechanism* rvm); //Constructor
                ~EditDeviceDialog() noexcept {}; //Destructor

        private:

                //Constructor Functions
                void CreateControls();
                void ConnectControls();



                //RVM
                ReferenceValidationMechanism* rvm;



                //Control Variables
		wxButton* submit;
		wxButton* cancel;

		wxCheckBox* staticDynamic;

		//TODO Add More if Necessary



		//Event Handler Functions
		void OnSubmit(wxCommandEvent & event);
		void OnCancel(wxCommandEvent & event);

};
