/*
 * Registration.cpp
 * Created on Nov 1, 2023
 *
 * Author: Ubljudok
 */

#include "Registration.h"

Registration::Registration() : wxFrame(nullptr, wxID_ANY, "Account Registration") {

	//Set Window Size
	SetMinSize(*windowSize);
	SetMaxSize(*windowSize);
	
}
