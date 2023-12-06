/*
 * MainFrame.cpp
 * Created on Nov 1, 2023
 *
 * Author: Ubljudok
 */

#include "MainFrame.h"



//Constructor

MainFrame::MainFrame(const wxString& title, ReferenceValidationMechanism* rvm) : wxFrame(nullptr, wxID_ANY, title) {

	//Set RVM
	this->rvm = rvm;

	//Get Network
	this->n = rvm->GetNetwork();
	
	//Set Sizer
	SetSizer(this->sizer);
	SetAutoLayout(true);

	//Create GUI
	CreateMainMenu();
	CreateToolBar();
	this->sizer->Add(this->nf, 1, wxEXPAND); //Add NetworkField to Sizer
	CreateStatusBar();

	//Bind GUI
	BindMainMenu();
	BindToolBar();

	//Set Minimum Window Size
	SetMinSize(wxSize(828, 512));

	//Set to Default Mode
	wxCommandEvent defaultMode(wxEVT_COMMAND_MENU_SELECTED, this->ID_SELECT);
        MainFrame::OnSelectionMode(defaultMode);

	//Prepare Dialogs
	this->deviceManagementDialog = new DeviceManagementDialog(this, this->rvm);
	this->userManagementDialog = new UserManagementDialog(this, this->rvm);
}

//Construction Functions
void MainFrame::CreateMainMenu() {

	//Create Menu Items
	//--FILE--//
        auto mm_File = new wxMenu();

        auto mm_FileRefresh = mm_File->Append(this->ID_REFRESH, "Refresh Network", "Refresh Network");
	
        auto mm_FileUpload = mm_File->Append(wxID_SAVE, "Upload Changes", "Upload Changes"); //Save Network File
        mm_FileUpload->SetBitmap(wxArtProvider::GetBitmap(wxART_FILE_SAVE, wxART_MENU));

        mm_File->AppendSeparator();

        auto mm_FileLogOut = mm_File->Append(this->ID_LOGOUT, "Log Out", "Log out of this program"); //Log Out

        auto mm_FileExit = mm_File->Append(wxID_EXIT); //Exit Program
        mm_FileExit->SetBitmap(wxArtProvider::GetBitmap(wxART_QUIT, wxART_MENU));

        //--EDIT--//
        auto mm_Edit = new wxMenu();

        auto mm_EditUndo = mm_Edit->Append(wxID_UNDO); //Undo Action
        mm_EditUndo->SetBitmap(wxArtProvider::GetBitmap(wxART_UNDO, wxART_MENU));

        auto mm_EditRedo = mm_Edit->Append(wxID_REDO); //Redo Action
        mm_EditRedo->SetBitmap(wxArtProvider::GetBitmap(wxART_REDO, wxART_MENU));

        //--NETWORK--//
        auto mm_Network = new wxMenu();

        auto mm_NetworkManageDevices = mm_Network->Append(this->ID_MANAGEDEVICES, "Manage Devices", "Manage Devices"); //Manage Devices - Restricted to Network Admin

        auto mm_NetworkViewInfo = mm_Network->Append(this->ID_VIEWNETWORK, "View Network Information", "View Network Information"); //View Network Information

        //--USERS--//
        auto mm_Users = new wxMenu();

        auto mm_UsersManage = mm_Users->Append(this->ID_MANAGEUSERS, "Manage Users", "Manage Users"); //Manage Users - Restricted to Network Admin

        auto mm_UsersUpdate = mm_Users->Append(this->ID_UPDATEUSER, "Update Account Information", "Update Account Information"); //Update User Account Information

        //--HELP--//
        auto mm_Help = new wxMenu();

        auto mm_HelpOpenDocs = mm_Help->Append(this->ID_OPENDOCS, "Open Documentation", "Open Documentation"); //Link to Documentation



	//Add to Menu
	this->mm->Append(mm_File, "&File");
        this->mm->Append(mm_Edit, "&Edit");
        this->mm->Append(mm_Network, "&Network");
        this->mm->Append(mm_Users, "&Users");
        this->mm->Append(mm_Help, "&Help");



	//Set Menu
        SetMenuBar(this->mm);	
}

void MainFrame::CreateToolBar() {

	//Create Toolbar Items
        auto tb_SetSelectionMode = this->tb->AddCheckTool(this->ID_SELECT, "Select", *TB_SELECT, wxNullBitmap, "Selection Mode"); //Cursor is in Select Mode
        auto tb_SetTestConnectionMode = this->tb->AddCheckTool(this->ID_TESTCONNECTION, "Test Connection", *TB_TEST_CONNECTION, wxNullBitmap, "Test Connection"); //Cursor will Select Two Devices to Test
        auto tb_SetAddNoteMode = this->tb->AddCheckTool(this->ID_NOTE, "Place Note", *TB_ADD_NOTE, wxNullBitmap, "Add Note"); //Cursor will Place Note when clicking on Network Field

        this->tb->AddSeparator();

        auto tb_ZoomIn = this->tb->AddTool(this->ID_ZOOMIN, "Zoom In", *TB_ZOOM_IN, "Zoom In"); //Network Field will be Zoomed In
        auto tb_ZoomOut = this->tb->AddTool(this->ID_ZOOMOUT, "Zoom Out", *TB_ZOOM_OUT, "Zoom Out"); //Network Field will be Zoomed Out
        auto tb_ZoomReset = this->tb->AddTool(this->ID_RESETZOOM, "Reset Zoom", *TB_ZOOM_FIT, "Reset Zoom"); //Network Field Zoom will be set to Default



	//Apply Toolbar
	SetToolBar(this->tb);
        this->tb->Realize();

}

void MainFrame::CreateStatusBar() {

	//Create Statusbar Fields
	this->sb->SetFieldsCount(sizeof(this->SB_WIDTHS)); //Declare how many Status Bar Fields are there
        this->sb->SetStatusWidths(sizeof(this->SB_WIDTHS), this->SB_WIDTHS); //Set Width of each Field
        this->sb->SetStatusStyles(sizeof(this->SB_STYLES), this->SB_STYLES); //Set Style of each Field
	


	//Apply Statusbar
	SetStatusBar(this->sb);

}

void MainFrame::BindMainMenu() {

	//File
	this->mm->Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnRefresh, this, this->ID_REFRESH);
        this->mm->Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnUpload, this, wxID_SAVE);
        this->mm->Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnLogOut, this, this->ID_LOGOUT);
        this->mm->Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnExit, this, wxID_EXIT);

	//Edit
        this->mm->Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnUndo, this, wxID_UNDO);
        this->mm->Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnRedo, this, wxID_REDO);

	//Network
        this->mm->Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnManageDevices, this, this->ID_MANAGEDEVICES);
        this->mm->Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnViewInfo, this, this->ID_VIEWNETWORK);

	//Users
        this->mm->Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnManageUsers, this, this->ID_MANAGEUSERS);
        this->mm->Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnUpdateAccount, this, this->ID_UPDATEUSER);

	//Help
        this->mm->Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnOpenDocs, this, this->ID_OPENDOCS);

}
 
void MainFrame::BindToolBar() {

	this->tb->Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnSelectionMode, this, this->ID_SELECT);
        this->tb->Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnTestingMode, this, this->ID_TESTCONNECTION);
        this->tb->Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnPlaceNoteMode, this, this->ID_NOTE);

        this->tb->Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnZoomIn, this, this->ID_ZOOMIN);
        this->tb->Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnZoomOut, this, this->ID_ZOOMOUT);
        this->tb->Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnResetZoom, this, this->ID_RESETZOOM);

}



//Event Handler Functions

//--STANDARD--//
void MainFrame::OnExit(wxCommandEvent &event) {
	std::cout << "Exiting" << std::endl; //Temp

	Close(true);
}

//--Main Menu--//

//---File---//
void MainFrame::OnRefresh(wxCommandEvent & event) {
        std::cout << "Refreshing Network" << std::endl; //Temp
}

void MainFrame::OnUpload(wxCommandEvent & event) {
        std::cout << "Uploading" << std::endl; //Temp
}

void MainFrame::OnLogOut(wxCommandEvent & event) {
        std::cout << "Logging Out" << std::endl; //Temp
}

//---Edit---//
void MainFrame::OnUndo(wxCommandEvent & event) {
        std::cout << "Undo" << std::endl; //Temp
}

void MainFrame::OnRedo(wxCommandEvent & event) {
        std::cout << "Redo" << std::endl; //Temp
}

//---Network---//
void MainFrame::OnManageDevices(wxCommandEvent & event) {
        std::cout << "Managing Devices" << std::endl; //Temp
	
	this->deviceManagementDialog->ShowModal();
	
}

void MainFrame::OnViewInfo(wxCommandEvent & event) {
        std::cout << "Viewing Account Info" << std::endl; //Temp
}

//---Users---//
void MainFrame::OnManageUsers(wxCommandEvent & event) {
        std::cout << "Managing Users" << std::endl; //Temp
	
	this->userManagementDialog->ShowModal();

}
                
void MainFrame::OnUpdateAccount(wxCommandEvent & event) {
        std::cout << "Updating Accout" << std::endl; //Temp
}

//---Help---//
void MainFrame::OnOpenDocs(wxCommandEvent & event) {
        std::cout << "Opening Docs" << std::endl; //Temp
}



//--TOOLBAR--//
void MainFrame::OnHoverToolbarSelection(wxCommandEvent & event) {

}

//---Modes---//
void MainFrame::OnSelectionMode(wxCommandEvent & event) {

	if (this-tb->GetToolEnabled(this->ID_SELECT)) { //If Current Tool Is Toggled
		
		//Fix Other Buttons
		if (this-tb->GetToolEnabled(this->ID_TESTCONNECTION))
			this->tb->ToggleTool(this->ID_TESTCONNECTION, false);

		if (this-tb->GetToolEnabled(this->ID_NOTE))
			this->tb->ToggleTool(this->ID_NOTE, false);



		//Set Mode
		this->nf->SetMode(this->SELECTION_MODE);


		//Set Status Bar
		this->sb->SetStatusText("Selection Mode");



		//Keep Button Toggle if Clicked Twice
		this->tb->ToggleTool(this->ID_SELECT, true);

	}

}
                
void MainFrame::OnTestingMode(wxCommandEvent & event) {
	
        if (this-tb->GetToolEnabled(this->ID_TESTCONNECTION)) { //If Current Tool Is Toggled

                //Fix Other Buttons
                if (this-tb->GetToolEnabled(this->ID_SELECT))
                        this->tb->ToggleTool(this->ID_SELECT, false);

                if (this-tb->GetToolEnabled(this->ID_NOTE))
                        this->tb->ToggleTool(this->ID_NOTE, false);



                //Set Mode
		this->nf->SetMode(this->TEST_CONNECTION_MODE);


                //Set Status Bar
                this->sb->SetStatusText("Testing...");



                //Keep Button Toggle if Clicked Twice
                this->tb->ToggleTool(this->ID_TESTCONNECTION, true);

        }

}
                
void MainFrame::OnPlaceNoteMode(wxCommandEvent & event) {
	
        if (this-tb->GetToolEnabled(this->ID_NOTE)) { //If Current Tool Is Toggled

                //Fix Other Buttons
                if (this-tb->GetToolEnabled(this->ID_TESTCONNECTION))
                        this->tb->ToggleTool(this->ID_TESTCONNECTION, false);

                if (this-tb->GetToolEnabled(this->ID_SELECT))
                        this->tb->ToggleTool(this->ID_SELECT, false);



                //Set Mode
		this->nf->SetMode(this->ADD_NOTE_MODE);


                //Set Status Bar
                this->sb->SetStatusText("Placing Note...");


                //Keep Button Toggle if Clicked Twice
                this->tb->ToggleTool(this->ID_NOTE, true);

        }

}

//---Zoom---//
void MainFrame::OnZoomIn(wxCommandEvent & event) {
        std::cout << "Zooming In" << std::endl; //Temp
}
                
void MainFrame::OnZoomOut(wxCommandEvent & event) {
        std::cout << "Zooming Out" << std::endl; //Temp
}
               
void MainFrame::OnResetZoom(wxCommandEvent & event) {
        std::cout << "Resetting Zoom" << std::endl; //Temp
}

