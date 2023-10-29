/*
 * MainFrame.h
 * Created on: Oct 29, 2023
 *
 * Author: Ubljudok
 */

#pragma once
#include <wx/wx.h>

class MainFrame : public wxFrame {
	
	public:

		MainFrame(const wxString& title);

};



//Constuctor

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {

        //Nothing Yet...

}

