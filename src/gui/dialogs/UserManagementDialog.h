/*
 * UserManagementDialog.h
 * Created on: Nov 6, 2023
 *
 * Author: Ubljudok
 */

#pragma once
#include <wx/wx.h>

#include "../../ReferenceValidationMechanism.h"

class UserManagementDialog : public wxDialog {

        public:

                UserManagementDialog(wxWindow* parent, ReferenceValidationMechanism* rvm); //Constructor
		~UserManagementDialog() noexcept {};

        private:

                //To be added

};

