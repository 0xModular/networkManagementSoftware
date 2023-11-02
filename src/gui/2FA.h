/*
 * 2FA.h
 * Created on Nov 1, 2023
 *
 * Author: Ubljudok
 */

#pragma once
#include <wx/wx.h>

class TwoFactorAuthentication : public wxFrame {

	public:

		TwoFactorAuthentication(); //Constructor
	
	private:

		inline static const wxSize* windowSize = new wxSize(400, 300);

};
