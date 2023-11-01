/*
 * MainFrame.cpp
 * Created on Nov 1, 2023
 *
 * Author: Ubljudok
 */

#include "MainFrame.h"



//Constuctor

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

	auto mm_FileLogOut = mm_File->Append(ID_LOGOUT, "Log Out"); //Log Out

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

	auto mm_NetworkConfigure = mm_Network->Append(ID_CONFIG,"Configure Network"); //Configure Network - Restricted to Network Admin

	auto mm_NetworkManageDevices = mm_Network->Append(ID_MANAGEDEVICES, "Manage Devices"); //Manage Devices - Restricted to Network Admin

	auto mm_NetworkViewInfo = mm_Network->Append(ID_VIEWNETWORK, "View Network Information"); //View Network Information


	//--USERS--//
	auto mm_Users = new wxMenu();

	auto mm_UsersManage = mm_Users->Append(ID_MANAGEUSERS, "Manage Users"); //Manage Users - Restricted to Network Admin

	auto mm_UsersUpdate = mm_Users->Append(ID_UPDATEUSER, "Update Account Information"); //Update User Account Information

	//--HELP--//
	auto mm_Help = new wxMenu();

	auto mm_HelpOpenDocs = mm_Help->Append(ID_OPENDOCS, "Open Documentation"); //Link to Documentation
	
	//--APPLY MAIN MENU--//	
	mm->Append(mm_File, "&File");
	mm->Append(mm_Edit, "&Edit");
	mm->Append(mm_Network, "&Network");
	mm->Append(mm_Users, "&Users");
	mm->Append(mm_Help, "&Help");

	SetMenuBar(mm);



	//Toolbar
	
	//--ADD TOOLBAR OPTIONS--//
	tb->AddTool(ID_SELECT, "Select", *TB_SELECT, "Selection Mode"); //Cursor is in Select Mode
	tb->AddTool(ID_ADDDEVICE, "Add Device", *TB_ADD_DEVICE, "Add Device"); //Cursor will Add Device when clicking on Network Field - Restricted to Network Admin
	tb->AddTool(ID_TESTCONNECTION, "Test Connection", *TB_TEST_CONNECTION, "Test Connection"); //Cursor will Select Two Devices to Test
	tb->AddTool(ID_NOTE, "Place Note", *TB_ADD_NOTE, "Add Note"); //Cursor will Place Note when clicking on Network Field
	tb->AddSeparator();
	tb->AddTool(wxID_ZOOM_IN, "&Zoom In", *TB_ZOOM_IN, "Zoom In"); //Network Field will be Zoomed In
	tb->AddTool(wxID_ZOOM_OUT, "&Zoom Out", *TB_ZOOM_OUT, "Zoom Out"); //Network Field will be Zoomed Out
	tb->AddTool(wxID_ZOOM_FIT, "&Reset Zoom", *TB_ZOOM_FIT, "Reset Zoom"); //Network Field Zoom will be set to Default
	
	//--APPLY TOOLBAR--//
	SetToolBar(tb);
	tb->Realize();
	


	//Set Minimum Window Size

	SetMinSize(wxSize(828, 512));
}

