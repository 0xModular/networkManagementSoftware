/*
 * App.cpp
 * Created on: Oct 29, 2023
 *
 * Author: Ubljudok
 */

//THIS WHOLE THING IS TEMP -- FINAL WILL GO IN GUI.cpp

#include "App.h"
#include "MainFrame.h"

wxIMPLEMENT_APP(App);

bool App::OnInit() {
	
	MainFrame* app = new MainFrame("NULL Network Management (alpha)"); //Load MainFrame
	app->Show();

	return true;

}
