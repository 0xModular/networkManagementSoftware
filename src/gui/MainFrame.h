/*
 * MainFrame.h
 * Created on: Oct 29, 2023
 *
 * Author: Ubljudok
 */

#pragma once
#include <wx/wx.h>
#include <wx/artprov.h>
#include <map>

//XPM RESOURCES
#include "../../assets/icons/TOOLBAR_ADD_DEVICE.xpm"
#include "../../assets/icons/TOOLBAR_ADD_NOTE.xpm"
#include "../../assets/icons/TOOLBAR_SELECT.xpm"
#include "../../assets/icons/TOOLBAR_TEST_CONNECTION.xpm"
#include "../../assets/icons/TOOLBAR_ZOOM_FIT.xpm"
#include "../../assets/icons/TOOLBAR_ZOOM_OUT.xpm"
#include "../../assets/icons/TOOLBAR_ZOOM_IN.xpm"


class MainFrame : public wxFrame {
	
	public:

		MainFrame(const wxString& title);

	private:

		//Resources

		//--TOOLBOX ICONS--//
		inline static const wxIcon* TB_ADD_DEVICE = new wxIcon(TOOLBAR_ADD_DEVICE);
		inline static const wxIcon* TB_ADD_NOTE = new wxIcon(TOOLBAR_ADD_NOTE);
		inline static const wxIcon* TB_SELECT = new wxIcon(TOOLBAR_SELECT);
		inline static const wxIcon* TB_TEST_CONNECTION = new wxIcon(TOOLBAR_TEST_CONNECTION);
		inline static const wxIcon* TB_ZOOM_FIT = new wxIcon(TOOLBAR_ZOOM_FIT);
		inline static const wxIcon* TB_ZOOM_OUT = new wxIcon(TOOLBAR_ZOOM_OUT);
		inline static const wxIcon* TB_ZOOM_IN = new wxIcon(TOOLBAR_ZOOM_IN);



		//Main Menu
		wxMenuBar* mm = new wxMenuBar();
		
		//--MAIN MENU IDS--//
		inline static const int ID_CONFIG = 1;
		inline static const int ID_MANAGEDEVICES = 2;
		inline static const int ID_VIEWNETWORK = 3;
		inline static const int ID_MANAGEUSERS = 4;
		inline static const int ID_UPDATEUSER = 5;
		inline static const int ID_OPENDOCS = 6;



		//Toolbar
		wxToolBar* tb = new wxToolBar(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTB_HORIZONTAL);	

		//--TOOLBAR IDS--//
		inline static const int ID_SELECT = 7;
		inline static const int ID_ADDDEVICE = 8;
		inline static const int ID_TESTCONNECTION = 9;
		inline static const int ID_NOTE = 10;
};

