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

		wxMenuBar* mm = new wxMenuBar(); //Main Menu

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

	//--USERS--// - Restricted to Network Admin
	auto mm_Users = new wxMenu();

	//--HELP--//
	auto mm_Help = new wxMenu();
	
	//--APPLY MAIN MENU--//	
	mm->Append(mm_File, "&File");
	mm->Append(mm_Edit, "&Edit");
	mm->Append(mm_Network, "&Network");
	mm->Append(mm_Users, "&Users");
	mm->Append(mm_Help, "&Help");

	SetMenuBar(mm);



	//Set Minimum Window Size

	SetMinSize(wxSize(828, 512));
}

