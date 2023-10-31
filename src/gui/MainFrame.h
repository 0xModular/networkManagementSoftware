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

class MainFrame : public wxFrame {
	
	public:

		MainFrame(const wxString& title);

	private:

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

	auto mm_FileQuit = mm_File->Append(wxID_EXIT); //Exit Program
	mm_FileQuit->SetBitmap(wxArtProvider::GetBitmap(wxART_QUIT, wxART_MENU));

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
	tb->AddTool(ID_SELECT, "Select", wxArtProvider::GetBitmap(wxART_COPY, wxART_TOOLBAR)); //Cursor is in Select Mode
	tb->AddTool(ID_ADDDEVICE, "Add Device", wxArtProvider::GetBitmap(wxART_COPY, wxART_TOOLBAR)); //Cursor will Add Device when clicking on Network Field - Restricted to Network Admin
	tb->AddTool(ID_TESTCONNECTION, "Test Connection", wxArtProvider::GetBitmap(wxART_COPY, wxART_TOOLBAR)); //Cursor will Select Two Devices to Test
	tb->AddTool(ID_NOTE, "Place Note", wxArtProvider::GetBitmap(wxART_COPY, wxART_TOOLBAR)); //Cursor will Place Note when clicking on Network Field
	tb->AddSeparator();
	tb->AddTool(wxID_ZOOM_IN, "&Zoom In", wxArtProvider::GetBitmap(wxART_COPY, wxART_TOOLBAR)); //Network Field will be Zoomed In
	tb->AddTool(wxID_ZOOM_OUT, "&Zoom Out", wxArtProvider::GetBitmap(wxART_COPY, wxART_TOOLBAR)); //Network Field will be Zoomed Out
	tb->AddTool(wxID_ZOOM_FIT, "&Reset Zoom", wxArtProvider::GetBitmap(wxART_COPY, wxART_TOOLBAR)); //Network Field Zoom will be set to Default
	
	//--APPLY TOOLBAR--//
	SetToolBar(tb);
	tb->Realize();
	


	//Set Minimum Window Size

	SetMinSize(wxSize(828, 512));
}

