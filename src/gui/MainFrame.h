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
#include "../../assets/icons/TOOLBAR_ADD_NOTE.xpm"
#include "../../assets/icons/TOOLBAR_SELECT.xpm"
#include "../../assets/icons/TOOLBAR_TEST_CONNECTION.xpm"
#include "../../assets/icons/TOOLBAR_ZOOM_FIT.xpm"
#include "../../assets/icons/TOOLBAR_ZOOM_OUT.xpm"
#include "../../assets/icons/TOOLBAR_ZOOM_IN.xpm"

//Other Objects
#include "NetworkField.h"
#include "../ReferenceValidationMechanism.h"

//Dialogs
#include "dialogs/DeviceManagementDialog.h"
#include "dialogs/UserManagementDialog.h"
#include "dialogs/NetworkInformationDialog.h"

class MainFrame : public wxFrame {
	
	public:

		MainFrame(const wxString& title, ReferenceValidationMechanism* rvm); //Constructor
		~MainFrame() noexcept {}; //Destructor

	private:

		//Construction Functions
		void CreateMainMenu();
        	void CreateToolBar();
        	void CreateStatusBar();
        	void BindMainMenu();
       		void BindToolBar();

		//--Construction Variable--//
		int userType; // = Account->GetUserType(); or something like that
		

		
		//RVM
		ReferenceValidationMechanism* rvm;
		Network* n;
		
		
		//Sizer
		wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);



		//Network Field
		NetworkField* nf = new NetworkField(this, wxID_ANY, wxDefaultPosition, wxDefaultSize);


		//Resources

		//--TOOLBAR ICONS--//
		inline static const wxIcon* TB_ADD_NOTE = new wxIcon(TOOLBAR_ADD_NOTE);
		inline static const wxIcon* TB_SELECT = new wxIcon(TOOLBAR_SELECT);
		inline static const wxIcon* TB_TEST_CONNECTION = new wxIcon(TOOLBAR_TEST_CONNECTION);
		inline static const wxIcon* TB_ZOOM_FIT = new wxIcon(TOOLBAR_ZOOM_FIT);
		inline static const wxIcon* TB_ZOOM_OUT = new wxIcon(TOOLBAR_ZOOM_OUT);
		inline static const wxIcon* TB_ZOOM_IN = new wxIcon(TOOLBAR_ZOOM_IN);



		//Main Menu
		wxMenuBar* mm = new wxMenuBar();
		
		//--MAIN MENU IDS--//
		inline static const int ID_REFRESH = 1;
		inline static const int ID_LOGOUT = 2;
		inline static const int ID_MANAGEDEVICES = 3;
		inline static const int ID_VIEWNETWORK = 4;
		inline static const int ID_MANAGEUSERS = 5;
		inline static const int ID_UPDATEUSER = 6;
		inline static const int ID_OPENDOCS = 7;		


		//Toolbar
		wxToolBar* tb = new wxToolBar(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTB_HORIZONTAL);	

		//--TOOLBAR IDS--//
		inline static const int ID_SELECT = 8;
		inline static const int ID_TESTCONNECTION = 9;
		inline static const int ID_NOTE = 10;
		inline static const int ID_ZOOMIN = 11;
		inline static const int ID_ZOOMOUT = 12;
		inline static const int ID_RESETZOOM = 13;

		
		//--TOOLBAR EVENTS--//
                void OnHoverToolbarSelection(wxCommandEvent & event); //Display on Statusbar "Set to... Mode" or "Zoom..."

                //---Modes---//
                void OnSelectionMode(wxCommandEvent & event); //Default Mode of the Program, allows you to select devices
                void OnTestingMode(wxCommandEvent & event); //When in this mode, user selects one device, then another, which triggers tests, where results are shown in Testing Suite Window
                void OnPlaceNoteMode(wxCommandEvent & event); //When in this mode, clicking on the Network Field add a text note

                //---Zoom---//                          //These are Self Explanatory
                void OnZoomIn(wxCommandEvent & event);
                void OnZoomOut(wxCommandEvent & event);
                void OnResetZoom(wxCommandEvent & event);

                //---ToolBar Mode IDs---//
                inline static const int SELECTION_MODE = 0;
                inline static const int TEST_CONNECTION_MODE = 1;
                inline static const int ADD_NOTE_MODE = 2;




		//Statusbar
		wxStatusBar* sb = new wxStatusBar(this);
		
        	//--SET WIDTHS--//
       		inline static const int SB_WIDTHS[] = {250, -1};
	
	        //--SET STYLES--//
	        inline static const int SB_STYLES[] = {wxSB_SUNKEN, wxSB_SUNKEN};



		//Event Handler Functions

		//--STANDARD--//
		void OnExit(wxCommandEvent & event); //When User Clicks 'X' or Quit on the File Menu
		
		//--MAIN MENU--//
		
		//---File---//
		void OnRefresh(wxCommandEvent & event); //Reloads Network
		void OnUpload(wxCommandEvent & event); //Updates Network		
		void OnLogOut(wxCommandEvent & event); //Logs User Out and Returns to Log In Prompt
		//OnExit 			//Exits the Program Fully - Will Prompt if Not Saved

		//---Edit---//
		void OnUndo(wxCommandEvent & event); //Undo Previous Action
		void OnRedo(wxCommandEvent & event); //Redo Undone Action

		//---Network---//
		void OnManageDevices(wxCommandEvent & event); //Opens Device Manager
		void OnViewInfo(wxCommandEvent & event); //Opens Network Information Window

		//---Users---//
		void OnManageUsers(wxCommandEvent & event); //Opens User Manager
		void OnUpdateAccount(wxCommandEvent & event); //Opens Account Management Menu
		
		//---Help---//
		void OnOpenDocs(wxCommandEvent & event); //Open Up Browser Window to Documentation

		//--TOOLBAR--// --SEE PROTECTED

};


