/*
 * UserManagementDialog.cpp
 * Created on: Nov 6, 2023
 *
 * Author: Ubljudok
 */

#include "UserManagementDialog.h"


//Constructor
UserManagementDialog::UserManagementDialog(wxWindow *parent, ReferenceValidationMechanism *rvm) : wxDialog(parent, -1, _T("User Management")) {

        //Set RVM
	this->rvm = rvm;

	CreateControls();
	ConnectControls();
	PopulateUsers();
	PopulateQueue();

}



//Construction Functions
void UserManagementDialog::CreateControls() {

	//Create Sizers
	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* horizontalSizer;
	wxBoxSizer* verticalSizer;
	wxBoxSizer* userListSizer;
	wxBoxSizer* queueListSizer;
	wxBoxSizer* buttonSizer;



	//Create Panels
	this->userArea = new wxScrolledWindow(this, wxID_ANY);
	this->queueArea = new wxScrolledWindow(this, wxID_ANY);



	//Create User List Foundation
	userListSizer = new wxBoxSizer(wxVERTICAL);

	verticalSizer = new wxBoxSizer(wxVERTICAL);

	this->users = new wxListView(this->userArea);

	this->users->AppendColumn("Username");
	this->users->AppendColumn("Access Level");
	this->users->AppendColumn("Date Created");

	this->users->SetColumnWidth(0, 200);
	this->users->SetColumnWidth(1, 150);
	this->users->SetColumnWidth(2, 150);

	userListSizer->Add(this->users, 0, wxEXPAND, 0);

	this->userArea->SetSizerAndFit(userListSizer);
	this->userArea->FitInside();
	this->userArea->SetScrollRate(5, 5);

	//--Buttons--//
	buttonSizer = new wxBoxSizer(wxHORIZONTAL);
	
	this->sortByUsername = new wxButton(this, this->ID_SORTUSERNAME, _T("Sort By Username"));
	this->sortByAccess = new wxButton(this, this->ID_SORTACCESS, _T("Sort By Type"));
	this->sortByDate = new wxButton(this, this->ID_SORTDATE, _T("Sort By Creation Date"));
	
	buttonSizer->Add(this->sortByUsername, 0, wxEXPAND, 0);
	buttonSizer->AddStretchSpacer(10);
	buttonSizer->Add(this->sortByAccess, 0, wxEXPAND, 0);
	buttonSizer->AddStretchSpacer(10);
	buttonSizer->Add(this->sortByDate, 0, wxEXPAND, 0);

	verticalSizer->Add(buttonSizer, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 0);
	verticalSizer->Add(new wxStaticLine(this, wxID_ANY), 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 10);
	verticalSizer->Add(this->userArea, 0, wxEXPAND, 0);

	this->editUser = new wxButton(this, this->ID_EDITUSER, _T("Edit Selected Device"));

	verticalSizer->Add(new wxStaticLine(this, wxID_ANY), 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 10);
	verticalSizer->Add(this->editUser, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 0);

	horizontalSizer = new wxBoxSizer(wxHORIZONTAL);

	horizontalSizer->Add(verticalSizer, 0, wxRIGHT, 0);



	//Create User Action Queue
	verticalSizer = new wxBoxSizer(wxVERTICAL);

	queueListSizer = new wxBoxSizer(wxVERTICAL);

	this->actionQueue = new wxListView(this->queueArea);

	this->actionQueue->AppendColumn("Date");
	this->actionQueue->AppendColumn("Type");
	this->actionQueue->AppendColumn("Description");

	this->actionQueue->SetColumnWidth(0, 100);
	this->actionQueue->SetColumnWidth(1, 100);
	this->actionQueue->SetColumnWidth(2, 300);

	queueListSizer->Add(this->actionQueue, 0, wxEXPAND, 0);

	this->queueArea->SetSizerAndFit(queueListSizer);
	this->queueArea->FitInside();
	this->queueArea->SetScrollRate(5, 5);

	//--Buttons--//
	buttonSizer = new wxBoxSizer(wxHORIZONTAL);

	this->approve = new wxButton(this, this->ID_APPROVE, _T("Approve Selected"));
	this->reject = new wxButton(this, this->ID_REJECT, _T("Reject Selected"));
	this->approveAll = new wxButton(this, this->ID_APPROVEALL, _T("Approve All"));
	this->rejectAll = new wxButton(this, this->ID_REJECTALL, _T("Reject All"));

	buttonSizer->Add(this->approve, 0, wxRIGHT, 0);
	buttonSizer->Add(this->approveAll, 0, wxRIGHT, 0);
	buttonSizer->Add(this->reject, 0, wxRIGHT, 0);
	buttonSizer->Add(this->rejectAll, 0, wxRIGHT, 0);

	verticalSizer->Add(buttonSizer, 0, wxEXPAND, 0);
	verticalSizer->Add(new wxStaticLine(this, wxID_ANY), 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 10);
	verticalSizer->Add(this->queueArea, 0, wxEXPAND, 0);	

	horizontalSizer->Add(20, 0, 0);
	horizontalSizer->Add(verticalSizer, 0, wxRIGHT, 0);


	
	mainSizer->Add(horizontalSizer, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 10);
	mainSizer->Add(new wxStaticLine(this, wxID_ANY), 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 10);



	//Add Rest of Buttons
	buttonSizer = new wxBoxSizer(wxHORIZONTAL);

	this->refresh = new wxButton(this, this->ID_REFRESH, _T("Refresh"));
	this->close = new wxButton(this, wxID_CANCEL, _T("Close"));

	buttonSizer->Add(this->refresh, 0, wxEXPAND, 0);
	buttonSizer->Add(100, 0, 0);
	buttonSizer->Add(this->close, 0, wxEXPAND, 0);

	mainSizer->Add(buttonSizer, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 0);
	mainSizer->Add(0, 10, 0);
	

	//Set Sizer
	SetSizer(mainSizer);
	mainSizer->SetSizeHints(this);

}

void UserManagementDialog::ConnectControls() {

	this->refresh->Bind(wxEVT_BUTTON, &UserManagementDialog::OnRefresh, this);
	this->close->Bind(wxEVT_BUTTON, &UserManagementDialog::OnClose, this);

	this->sortByUsername->Bind(wxEVT_BUTTON, &UserManagementDialog::OnSortByUsername, this);
	this->sortByAccess->Bind(wxEVT_BUTTON, &UserManagementDialog::OnSortByAccess, this);
	this->sortByDate->Bind(wxEVT_BUTTON, &UserManagementDialog::OnSortByDate, this);

	this->editUser->Bind(wxEVT_BUTTON, &UserManagementDialog::OnEditUser, this);

	this->approve->Bind(wxEVT_BUTTON, &UserManagementDialog::OnApprove, this);
	this->reject->Bind(wxEVT_BUTTON, &UserManagementDialog::OnReject, this);
	this->approveAll->Bind(wxEVT_BUTTON, &UserManagementDialog::OnApproveAll, this);
	this->rejectAll->Bind(wxEVT_BUTTON, &UserManagementDialog::OnRejectAll, this);

}

void UserManagementDialog::PopulateUsers() {



}

void UserManagementDialog::PopulateQueue() {



}



//Event Handler Functions
void UserManagementDialog::OnRefresh(wxCommandEvent & event) {



}
                
void UserManagementDialog::OnClose(wxCommandEvent & event) {

	this->EndModal(wxID_CANCEL);

}

void UserManagementDialog::OnSortByUsername(wxCommandEvent & event) {



}
                
void UserManagementDialog::OnSortByAccess(wxCommandEvent & event) {



}
                
void UserManagementDialog::OnSortByDate(wxCommandEvent & event) {



}
                
void UserManagementDialog::OnEditUser(wxCommandEvent & event) {



}

void UserManagementDialog::OnApprove(wxCommandEvent & event) {



}
                
void UserManagementDialog::OnReject(wxCommandEvent & event) {



}
                
void UserManagementDialog::OnApproveAll(wxCommandEvent & event) {



}
                
void UserManagementDialog::OnRejectAll(wxCommandEvent & event) {



}
