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
#include <vector>

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

		MainFrame(const wxString& title); //Constructor

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
		inline static const int ID_LOGOUT = 1;
		inline static const int ID_CONFIG = 2;
		inline static const int ID_MANAGEDEVICES = 3;
		inline static const int ID_VIEWNETWORK = 4;
		inline static const int ID_MANAGEUSERS = 5;
		inline static const int ID_UPDATEUSER = 6;
		inline static const int ID_OPENDOCS = 7;



		//Toolbar
		wxToolBar* tb = new wxToolBar(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTB_HORIZONTAL);	

		//--TOOLBAR IDS--//
		inline static const int ID_SELECT = 8;
		inline static const int ID_ADDDEVICE = 9;
		inline static const int ID_TESTCONNECTION = 10;
		inline static const int ID_NOTE = 11;
	
		inline static const int ID_ZOOMIN = 12;
		inline static const int ID_ZOOMOUT = 13;
		inline static const int ID_RESETZOOM = 14;

		//--TOOLBAR MODE IDS--//
		inline static const int SELECTION_MODE = 0;
		inline static const int ADD_DEVICE_MODE = 1;
		inline static const int TEST_CONNECTION_MODE = 2;
		inline static const int ADD_NOTE_MODE = 3;


		//Statusbar
		wxStatusBar* sb = new wxStatusBar(this);
		
        	//--SET WIDTHS--//
       		inline static const int sb_Widths[] = {250, -1};
	
	        //--SET STYLES--//
	        inline static const int sb_Styles[] = {wxSB_SUNKEN, wxSB_SUNKEN};



		//Event Handler Functions

		//--STANDARD--//
		void OnExit(wxCommandEvent & event); //When User Clicks 'X' or Quit on the File Menu
		
		//--MAIN MENU--//
		
		//---File---//
		void OnNew(wxCommandEvent & event); //Creates New Network File, Gives Prompt 
		void OnOpen(wxCommandEvent & event); //Opens Existing Network File
		void OnSave(wxCommandEvent & event); //Saves Network State to Network File
		void OnSaveAs(wxCommandEvent & event); //Saves Network State, and Allows User to Choose Location of Network File
		void OnLogOut(wxCommandEvent & event); //Logs User Out and Returns to Log In Prompt
		//OnExit 			//Exits the Program Fully - Will Prompt if Not Saved

		//---Edit---//
		void OnUndo(wxCommandEvent & event); //Undo Previous Action
		void OnRedo(wxCommandEvent & event); //Redo Undone Action

		//---Network---//
		void OnConfigure(wxCommandEvent & event); //Opens Configuration Suite
		void OnManageDevices(wxCommandEvent & event); //Opens Device Manager
		void OnViewInfo(wxCommandEvent & event); //Opens Network Information Window

		//---Users---//
		void OnManageUsers(wxCommandEvent & event); //Opens User Manager
		void OnUpdateAccount(wxCommandEvent & event); //Opens Account Management Menu
		
		//---Help---//
		void OnOpenDocs(wxCommandEvent & event); //Open Up Browser Window to Documentation

		//--TOOLBAR--//
		
		void OnHoverToolbarSelection(wxCommandEvent & event); //Display on Statusbar "Set to... Mode" or "Zoom..."

		//---Modes---//
                void OnSelectionMode(wxCommandEvent & event); //Default Mode of the Program, allows you to select devices
		void OnAddDeviceMode(wxCommandEvent & event); //When in this mode, clicking on the Network Field prompts Device Addition Menu
                void OnTestingMode(wxCommandEvent & event); //When in this mode, user selects one device, then another, which triggers tests, where results are shown in Testing Suite Window
                void OnPlaceNoteMode(wxCommandEvent & event); //When in this mode, clicking on the Network Field add a text note

		//---Zoom---// 				//These are Self Explanatory
                void OnZoomIn(wxCommandEvent & event); 
                void OnZoomOut(wxCommandEvent & event);
                void OnResetZoom(wxCommandEvent & event);

};

