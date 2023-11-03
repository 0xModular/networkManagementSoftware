/*
 * App.cpp
 * Created on: Oct 29, 2023
 *
 * Author: Ubljudok
 */

#include "2FA.h"
#include "App.h"
#include "Login.h"
#include "MainFrame.h"
#include "NetworkField.h"
#include "Registration.h"

wxIMPLEMENT_APP(App);

bool App::OnInit() {
	
	wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL); //Load Box Sizer
	MainFrame* app = new MainFrame("NULL Network Management (alpha)"); //Load MainFrame
	
	NetworkField* networkField = new NetworkField(app); //Create NetworkField and attach it to MainFrame

	sizer->Add(networkField, 1, wxEXPAND); //Apply sizer to NetworkField
	
	app->SetSizer(sizer); //Set MainFrame sizer to sizer
	app->SetAutoLayout(true);

	app->Show();

	//Temp -- Login
	
	(new Login())->Show();

	//Temp -- 2FA
	
	(new TwoFactorAuthentication())->Show();

	//Temp -- Registration
	
	(new Registration())->Show();

	return true;

}
