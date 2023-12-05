/*
 * EditUsernameDialog.cpp
 * Created on Nov 29, 2023
 *
 * Author: Ubljudok
 */

#include "EditUsernameDialog.h"

//Constructor
EditUsernameDialog::EditUsernameDialog(wxWindow* parent, ReferenceValidationMechanism* rvm, Account* user) : wxDialog(parent, -1, _T("Edit Username")) {

	//Set RVM and User
	this->rvm;
	this->user;

	CreateControls();
	ConnectControls();

}

//Construction Functions
void EditUsernameDialog::CreateControls() {

	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* horizontalSizer;

	std::string top = "Current Username: ";
        top.append(this->user->GetAccountName());

        mainSizer->Add(new wxStaticText(this, wxID_STATIC, top), 0, wxALL|wxALIGN_CENTER_VERTICAL, 0);



	//New Username Entry
	horizontalSizer = new wxBoxSizer(wxHORIZONTAL);

	horizontalSizer->Add(new wxStaticText(this, wxID_STATIC, _T("Enter New Username: ")), 0, wxALL|wxALIGN_CENTER_VERTICAL, 0);

	this->newUsernameEntry = new wxTextCtrl(this, -1, wxEmptyString, wxDefaultPosition, wxDefaultSize);
	
	horizontalSizer->Add(this->newUsernameEntry, 1, wxLEFT, 5);
	mainSizer->Add(horizontalSizer, 0, wxLEFT|wxRIGHT|wxBOTTOM|wxEXPAND, 10);



	//New Username Reentry
	horizontalSizer = new wxBoxSizer(wxHORIZONTAL);

        horizontalSizer->Add(new wxStaticText(this, wxID_STATIC, _T("Reenter Username: ")), 0, wxALL|wxALIGN_CENTER_VERTICAL, 0);

        this->newUsernameReentry = new wxTextCtrl(this, -1, wxEmptyString, wxDefaultPosition, wxDefaultSize);

	horizontalSizer->Add(this->newUsernameReentry, 1, wxLEFT, 5);
        mainSizer->Add(horizontalSizer, 0, wxLEFT|wxRIGHT|wxBOTTOM|wxEXPAND, 10);

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

void EditUsernameDialog::ConnectControls() {

	this->cancel->Bind(wxEVT_BUTTON, &EditUsernameDialog::OnCancel, this);
        this->submit->Bind(wxEVT_BUTTON, &EditUsernameDialog::OnSubmit, this);

}



//Event Handler Functions

void EditUsernameDialog::OnCancel(wxCommandEvent & event) {



}

void EditUsernameDialog::OnSubmit(wxCommandEvent & event) {



}
