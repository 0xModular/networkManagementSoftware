/*
 * App.cpp
 * Created on: Oct 29, 2023
 *
 * Author: Ubljudok
 */

#include "App.h"
#include "MainFrame.h"
#include <wx/wx.h>

wxIMPLEMENT_APP(App);

bool App::OnInit() {
	
	MainFrame* app = new MainFrame("NULL Network Management (alpha)");
	
	app->Show();

	return true;

}
