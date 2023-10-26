/*
 * Application.cpp
 * Created on: Oct 26, 2023
 *
 * Author: Ubljudok
 */

#include "Application.h"
#include <wx/wx.h>

//Temp

int main () {
	auto application = new wxApplication;
	application->MainLoop(new wxFrame(nullptr, wxID_ANY, wxEmptyString));
}
