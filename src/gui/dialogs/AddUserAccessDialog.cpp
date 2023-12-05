/*
 * AddUserAccessDialog.cpp
 * Created on: Nov 29, 2023
 *
 * Author: Ubljudok
 */

#include "AddUserAccessDialog.h"

AddUserAccessDialog::AddUserAccessDialog(wxWindow* parent, ReferenceValidationMechanism* rvm, Account* user): wxDialog(parent, -1, _T("Set Access Level to New User")) {

	//Set RVM and User
	this->rvm = rvm;
	this->user = user;

	CreateControls();
	ConnectControls();

}

//Construction Functions
void AddUserAccessDialog::CreateControls() {

	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* horizontalSizer = new wxBoxSizer(wxHORIZONTAL);



	std::string top = "For Account: ";
	top.append(this->user->GetAccountName());

	mainSizer->Add(new wxStaticText(this, wxID_STATIC, top), 0, wxALL|wxALIGN_CENTER_VERTICAL, 0);



	//Access Selection Area
	wxArrayString* select = new wxArrayString;
	select->Add("Network Admin");
	select->Add("Engineer");

	this->access = new wxRadioBox(this, wxID_ANY, "Access Level", wxPoint(20, 20), wxSize(200, 150), *select, wxRA_SPECIFY_COLS);

	mainSizer->Add(this->access, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 10);

	mainSizer->Add(new wxStaticLine(this, wxID_STATIC), 0, wxLEFT|wxRIGHT|wxEXPAND, 10);



	//Button Area
	this->cancel = new wxButton(this, wxID_CANCEL, _T("Cancel"));
	this->submit = new wxButton(this, wxID_OK, _T("Submit"));

	horizontalSizer->Add(this->cancel, 0, wxALL, 10);
	horizontalSizer->Add(this->submit, 0, wxALL, 10);

	mainSizer->Add(horizontalSizer, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 10);



	//Set Sizer
	SetSizer(mainSizer);
	mainSizer->SetSizeHints(this);

}

void AddUserAccessDialog::ConnectControls() {

	this->cancel->Bind(wxEVT_BUTTON, &AddUserAccessDialog::OnCancel, this);
	this->submit->Bind(wxEVT_BUTTON, &AddUserAccessDialog::OnSubmit, this);

}



//Event Handler Functions
void AddUserAccessDialog::OnCancel(wxCommandEvent & event){



}

void AddUserAccessDialog::OnSubmit(wxCommandEvent & event) {



}
