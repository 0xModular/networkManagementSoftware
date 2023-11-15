/*
 * GUI.h
 * Created on: Oct 29, 2023
 *
 * Author: Ubljudok
 */

#include "ReferenceValidationMechanism.h"
#include "gui/App.h"

bool App::OnInit() {
	
	//Dialogs
	this->login = new LoginDialog(NULL, 3, &(this->cred), false);
	this->tfa = new TwoFactorAuthenticationDialog(NULL, 0);
	this->rgstr = new RegistrationDialog(NULL);



	//Frames
	this->app = new MainFrame("NULL Network Management (alpha)");



	//Start Main Program Loop
	Login();
	
	return true;

}

int App::OnExit() {

	return this->wxApp::OnExit();

}

void App::Login() {

	int modal = this->login->ShowModal();

	switch (modal) {
	
		case wxID_OK:

			TwoFactorAuthentication();
			return;

		case this->login->ID_RGSTR:

			Register();
			return;

		case wxID_CANCEL:
		default:

			//Handle Errors
			break;
	
	}

	return;

}

void App::TwoFactorAuthentication() {

	int modal = this->tfa->ShowModal();
	
	switch (modal) {
	
		case wxID_OK:

			MainApp();
			return;

		case wxID_CANCEL:

			Login();
			return;

		default:

			//Handle Errors
			break;
	
	}

	return;
}

void App::Register() {

	int modal = this->rgstr->ShowModal();

	switch (modal) {
	
		case wxID_OK: 
			
			Login();
			return;

		case wxID_CANCEL:

			Login();
			return;

		default:

			//Handle Errors
			break;
	
	}

	return;
}

void App::MainApp() {

	this->app->Show();
	return;

}
