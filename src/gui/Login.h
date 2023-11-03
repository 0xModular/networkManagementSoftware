/*
 * Login.h
 * Created on: Oct 26, 2023
 *
 * Author: Ubljudok
 */

#pragma once
#include <wx/wx.h>

class Login : public wxFrame {
	
	public:
		
		Login(); //Constuctor
	
	private:
		
		inline static const wxSize* windowSize = new wxSize(400, 500);

};
