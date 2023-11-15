/*
 * GUI.h
 * Created on: Oct 29, 2023
 *
 * Author: Ubljudok
 */

#include "ReferenceValidationMechanism.h"
#include "gui/App.h"

bool App::OnInit() {

	//Program Loop

	//while (true) {
	
		//--LOGIN--//
		
		//Load Instance Of Login

			//If Login Credentials incorrect -- load new instance of Login w/ "Wrong Password"

			//If Login Credentials correct -- load instance of 2FA
			
				//If 2FA incorrect -- Close, and load new instance of Login w/ "Incorrect 2FA Credentials"

				//If 2FA correct -- load instance of Network Manager

			//If Select Cancel -- close, break;

			//If Select Registration -- close and load new instance of Registration

		
		//--REGISTRATION--//

			//If Username Taken -- load new instance of Registration "Taken Username"

			//If Password Doesn't Match -- load new instance of Registration "Password Doesn't Match"

			//If Select Cancel -- close, load instance of Login

			//If Select Submit -- submit credentials for Network Admin Review/Approval

		
		//--NETWORK MANAGER--//
		
			// ...	
	
	
	//}
	
	//Dialogs
	this->login = new LoginDialog(NULL, 3, &(this->cred), false);
	this->tfa = new TwoFactorAuthenticationDialog(NULL, 0);
	this->rgstr = new RegistrationDialog(NULL);



	//Frames
	this->app = new MainFrame("NULL Network Management (alpha)");



	//Start Main Program Loop
	Login();
	
	return true;












/*	//ALL BELOW IS TEMP!!!

	struct Credentials cred; 

        LoginDialog loginDialog(NULL, 3, &cred, false);

        auto loginModal = loginDialog.ShowModal();

        if (loginModal == wxID_OK) {
        
		
	       
		// std::cout << "Submitting" << std::endl;

        } else if (loginModal == loginDialog.ID_RGSTR) {

                std::cout << "Registering..." << std::endl;

        } else {

                std::cout << "Exiting..." << std::endl;

        }

        MainFrame* app = new MainFrame("NULL Network Management (alpha)"); //Load MainFrame
        app->Show();

        return true;
*/
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
