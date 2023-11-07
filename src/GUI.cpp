/*
 * GUI.cpp
 * Created on: Oct 29, 2023
 *
 * Author: Ubljudok
 */

#include "gui/App.h"
#include "gui/structures/Credentials.h"

wxIMPLEMENT_APP(App);

bool App::OnInit() {


	//ALL BELOW IS TEMP!!!

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

}
