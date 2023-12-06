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
#include "../ReferenceValidationMechanism.h"

#include "MainFrame.h"


class App : public wxApp {
	
	public:

		//Main Event Handlers
		bool OnInit() override;
		


		//Program Windows/Dialog Handlers
		void Login();
		void TwoFactorAuthentication();
		void Register();
		void MainApp();

	private:

		//Dialogs
		LoginDialog* login;
		TwoFactorAuthenticationDialog* tfa;
		RegistrationDialog* rgstr;



		//Frames
		MainFrame* app;



		//Misc
		ReferenceValidationMechanism* rvm;

};

