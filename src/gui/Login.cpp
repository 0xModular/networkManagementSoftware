/*
 * Login.cpp
 * Created on: Oct 26, 2023
 *
 * Author: Ubljudok
 */

#include "Login.h"

//Constructor

Login::Login() : wxFrame(nullptr, wxID_ANY, "Network Manager Login") {

	//Set Window Size
		
	SetMinSize(*windowSize);
	SetMaxSize(*windowSize);

}
