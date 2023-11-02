/*
 * 2FA.cpp
 * Created on Nov 1, 2023
 *
 * Author: Ubljudok
 */

#include "2FA.h"

TwoFactorAuthentication::TwoFactorAuthentication() : wxFrame(nullptr, wxID_ANY, "2FA Check") {
	
	//Set Window Size
	
	SetMinSize(*windowSize);
	SetMaxSize(*windowSize);

}
