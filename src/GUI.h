/*
 * GUI.h
 * Created on: Oct 29, 2023
 *
 * Author: Ubljudok
 */

#include "gui/App.h"

bool App::OnInit() {
	
	//Create RVM
	this->rvm = new ReferenceValidationMechanism();



	//Frames
        this->app = new MainFrame("NULL Network Management (alpha)", this->rvm);



	//Dialogs
	this->login = new LoginDialog(this->app, this->rvm);
	this->tfa = new TwoFactorAuthenticationDialog(this->app, this->rvm);
	this->rgstr = new RegistrationDialog(this->app, this->rvm);



	//Start Main Program Loop
	Login();

	return true;

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
			this->app->Close();
			return;
	
	}

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
			return;
	
	}

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
