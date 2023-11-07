/*
 * App.h
 * Created on: Oct 29, 2023
 *
 * Author: Ubljudok
 */

#pragma once
#include <wx/wx.h>

#include "dialogs/LoginDialog.h"
#include "dialogs/RegistrationDialog.h"
#include "dialogs/TwoFactorAuthenticationDialog.h"

#include "MainFrame.h"


class App : public wxApp {
	
	public:

		bool OnInit() override;

};

