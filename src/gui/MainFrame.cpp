/*
 * MainFrame.cpp
 * Created on Nov 1, 2023
 *
 * Author: Ubljudok
 */

#include "MainFrame.h"



//Constructor

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {

        //Main Menu
	
	//--FILE--//
	auto mm_File = new wxMenu();

	auto mm_FileNew = mm_File->Append(wxID_NEW); //Make a New Network File - Restricted to Network Admin
	mm_FileNew->SetBitmap(wxArtProvider::GetBitmap(wxART_NEW, wxART_MENU));
	
	auto mm_FileOpen = mm_File->Append(wxID_OPEN); //Open a Network File
	mm_FileOpen->SetBitmap(wxArtProvider::GetBitmap(wxART_FILE_OPEN, wxART_MENU));

	auto mm_FileSave = mm_File->Append(wxID_SAVE); //Save Network File
	mm_FileSave->SetBitmap(wxArtProvider::GetBitmap(wxART_FILE_SAVE, wxART_MENU));

	auto mm_FileSaveAs = mm_File->Append(wxID_SAVEAS); //Save Network File to Location - Restricted to Network Admin
	mm_FileSaveAs->SetBitmap(wxArtProvider::GetBitmap(wxART_FILE_SAVE_AS, wxART_MENU));

	mm_File->AppendSeparator();

	auto mm_FileLogOut = mm_File->Append(ID_LOGOUT, "Log Out", "Log out of this program"); //Log Out

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

	auto mm_NetworkConfigure = mm_Network->Append(ID_CONFIG,"Configure Network", "Configure Network"); //Configure Network - Restricted to Network Admin

	auto mm_NetworkManageDevices = mm_Network->Append(ID_MANAGEDEVICES, "Manage Devices", "Manage Devices"); //Manage Devices - Restricted to Network Admin

	auto mm_NetworkViewInfo = mm_Network->Append(ID_VIEWNETWORK, "View Network Information", "View Network Information"); //View Network Information


	//--USERS--//
	auto mm_Users = new wxMenu();

	auto mm_UsersManage = mm_Users->Append(ID_MANAGEUSERS, "Manage Users", "Manage Users"); //Manage Users - Restricted to Network Admin

	auto mm_UsersUpdate = mm_Users->Append(ID_UPDATEUSER, "Update Account Information", "Update Account Information"); //Update User Account Information

	//--HELP--//
	auto mm_Help = new wxMenu();

	auto mm_HelpOpenDocs = mm_Help->Append(ID_OPENDOCS, "Open Documentation", "Open Documentation"); //Link to Documentation

	//--BIND MENU EVENTS--//
	mm->Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnNew, this, wxID_NEW);
	mm->Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnOpen, this, wxID_OPEN);
	mm->Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnSave, this, wxID_SAVE);
	mm->Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnSaveAs, this, wxID_SAVEAS);
	mm->Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnLogOut, this, MainFrame::ID_LOGOUT);
	mm->Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnExit, this, wxID_EXIT);

	mm->Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnUndo, this, wxID_UNDO);
	mm->Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnRedo, this, wxID_REDO);

	mm->Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnConfigure, this, MainFrame::ID_CONFIG);
	mm->Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnManageDevices, this, MainFrame::ID_MANAGEDEVICES);
	mm->Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnViewInfo, this, MainFrame::ID_VIEWNETWORK);

	mm->Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnManageUsers, this, MainFrame::ID_MANAGEUSERS);
	mm->Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnUpdateAccount, this, MainFrame::ID_UPDATEUSER);

	mm->Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnOpenDocs, this, MainFrame::ID_OPENDOCS);

	//--APPLY MAIN MENU--//	
	mm->Append(mm_File, "&File");
	mm->Append(mm_Edit, "&Edit");
	mm->Append(mm_Network, "&Network");
	mm->Append(mm_Users, "&Users");
	mm->Append(mm_Help, "&Help");

	SetMenuBar(mm);



	//Toolbar
	
	//--ADD TOOLBAR OPTIONS--//
	auto tb_SetSelectionMode = tb->AddTool(ID_SELECT, "Select", *TB_SELECT, "Selection Mode"); //Cursor is in Select Mode
	auto tb_SetAddDeviceMode = tb->AddTool(ID_ADDDEVICE, "Add Device", *TB_ADD_DEVICE, "Add Device"); //Cursor will Add Device when clicking on Network Field - Restricted to Network Admin
	auto tb_SetTestConnectionMode = tb->AddTool(ID_TESTCONNECTION, "Test Connection", *TB_TEST_CONNECTION, "Test Connection"); //Cursor will Select Two Devices to Test
	auto tb_SetAddNoteMode = tb->AddTool(ID_NOTE, "Place Note", *TB_ADD_NOTE, "Add Note"); //Cursor will Place Note when clicking on Network Field
	
	tb->AddSeparator();
	
	auto tb_ZoomIn = tb->AddTool(ID_ZOOMIN, "Zoom In", *TB_ZOOM_IN, "Zoom In"); //Network Field will be Zoomed In
	auto tb_ZoomOut = tb->AddTool(ID_ZOOMOUT, "Zoom Out", *TB_ZOOM_OUT, "Zoom Out"); //Network Field will be Zoomed Out
	auto tb_ZoomReset = tb->AddTool(ID_RESETZOOM, "Reset Zoom", *TB_ZOOM_FIT, "Reset Zoom"); //Network Field Zoom will be set to Default
	
	//--BIND TOOLBAR EVENTS--//
	tb->Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnSelectionMode, this, MainFrame::ID_SELECT);
	tb->Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnAddDeviceMode, this, MainFrame::ID_ADDDEVICE);
	tb->Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnTestingMode, this, MainFrame::ID_TESTCONNECTION);
	tb->Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnPlaceNoteMode, this, MainFrame::ID_NOTE);

	tb->Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnZoomIn, this, MainFrame::ID_ZOOMIN);
	tb->Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnZoomOut, this, MainFrame::ID_ZOOMOUT);
	tb->Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnResetZoom, this, MainFrame::ID_RESETZOOM);

	//--APPLY TOOLBAR--//
	SetToolBar(tb);
	tb->Realize();



	//Statusbar
	
	//--SET STATUS BAR--//
	sb->SetFieldsCount(sizeof(sb_Widths)); //Declare how many Status Bar Fields are there
	sb->SetStatusWidths(sizeof(sb_Widths), sb_Widths); //Set Width of each Field
	sb->SetStatusStyles(sizeof(sb_Styles), sb_Styles); //Set Style of each Field
	
	//--SET DEFAULT TEXT--//
	sb->SetStatusText("Selection Mode"); //Left
	sb->SetStatusText("None Selected", 1); //Right-ish
	
	//--APPLY STATUSBAR--//
	SetStatusBar(sb);
		
		
	//Set Minimum Window Size

	SetMinSize(wxSize(828, 512));
}


//Event Handler Functions

//--STANDARD--//
void MainFrame::OnExit(wxCommandEvent &event){
	std::cout << "Exiting" << std::endl;
}

//--Main Menu--//

//---File---//
void MainFrame::OnNew(wxCommandEvent & event){
        std::cout << "Creating New" << std::endl;
}

void MainFrame::OnOpen(wxCommandEvent & event){
        std::cout << "Opening" << std::endl;
}

void MainFrame::OnSave(wxCommandEvent & event){
        std::cout << "Saving" << std::endl;
}

void MainFrame::OnSaveAs(wxCommandEvent & event){
	std::cout << "Saving As" << std::endl;
}

void MainFrame::OnLogOut(wxCommandEvent & event){
        std::cout << "Logging Out" << std::endl;
}

//---Edit---//
void MainFrame::OnUndo(wxCommandEvent & event){
        std::cout << "Undo" << std::endl;
}

void MainFrame::OnRedo(wxCommandEvent & event){
        std::cout << "Redo" << std::endl;
}

//---Network---//
void MainFrame::OnConfigure(wxCommandEvent & event){
        std::cout << "Configuring" << std::endl;
}

void MainFrame::OnManageDevices(wxCommandEvent & event){
        std::cout << "Managing Devices" << std::endl;
}

void MainFrame::OnViewInfo(wxCommandEvent & event){
        std::cout << "Viewing Account Info" << std::endl;
}

//---Users---//
void MainFrame::OnManageUsers(wxCommandEvent & event){
        std::cout << "Managing Users" << std::endl;
}
                
void MainFrame::OnUpdateAccount(wxCommandEvent & event){
        std::cout << "Updating Accout" << std::endl;
}

//---Help---//
void MainFrame::OnOpenDocs(wxCommandEvent & event){
        std::cout << "Opening Docs" << std::endl;
}



//--TOOLBAR--//
void MainFrame::OnHoverToolbarSelection(wxCommandEvent & event){

}

//---Modes---//
void MainFrame::OnSelectionMode(wxCommandEvent & event){
	std::cout << "Selection Mode" << std::endl;
}
                
void MainFrame::OnAddDeviceMode(wxCommandEvent & event){
	std::cout << "Add Device Mode" << std::endl;
}
                
void MainFrame::OnTestingMode(wxCommandEvent & event){
	std::cout << "Testing Mode" << std::endl;
}
                
void MainFrame::OnPlaceNoteMode(wxCommandEvent & event){
	std::cout << "Add Note Mode" << std::endl;
}

//---Zoom---//
void MainFrame::OnZoomIn(wxCommandEvent & event){
        std::cout << "Zooming In" << std::endl;
}
                
void MainFrame::OnZoomOut(wxCommandEvent & event){
        std::cout << "Zooming Out" << std::endl;
}
               
void MainFrame::OnResetZoom(wxCommandEvent & event){
        std::cout << "Resetting Zoom" << std::endl;
}



