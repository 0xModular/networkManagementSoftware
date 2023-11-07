/*
 * App.cpp
 * Created on: Oct 29, 2023
 *
 * Author: Ubljudok
 */

//THIS WHOLE THING IS TEMP -- FINAL WILL GO IN GUI.cpp

#include "dialogs/LoginDialog.h"
#include "App.h"
#include "MainFrame.h"

wxIMPLEMENT_APP(App);

bool App::OnInit() {

	LoginDialog loginDialog(NULL, 3);

	auto loginModal = loginDialog.ShowModal();

	if (loginModal == wxID_OK) {
	
		std::cout << "Submitting" << std::endl;

	} else if (loginModal == loginDialog.ID_RGSTR) {

		std::cout << "Registering..." << std::endl;

	} else {
		
		std::cout << "Exiting..." << std::endl;

	}
	
	MainFrame* app = new MainFrame("NULL Network Management (alpha)"); //Load MainFrame
	app->Show();

	return true;

}
