/*
 * EditUserDialog.cpp
 * Created on: Nov 15, 2023
 *
 * Author: Ubljudok
 */

#include "EditUserDialog.h"

EditUserDialog::EditUserDialog(wxWindow* parent, ReferenceValidationMechanism* rvm, Account* user) {

	//Set RVM and User
        this->rvm = rvm;
        this->user = user;

        CreateControls();
        ConnectControls();

}

//Construction Functions
void EditUserDialog::CreateControls() {

	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* horizontalSizer;



	//Edit Button Area

	this->changeUsername = new wxButton(this, this->ID_USER, _T("Change Username"));
	this->changePassword = new wxButton(this, this->ID_PASS, _T("Change Password"));

	mainSizer->Add(this->changeUsername, 0, wxALL, 0);
	mainSizer->Add(this->changePassword, 0, wxALL, 0);

	mainSizer->Add(new wxStaticLine(this, wxID_STATIC), 0, wxLEFT|wxRIGHT|wxEXPAND, 10);



	//Bottom Button Area
	horizontalSizer = new wxBoxSizer(wxHORIZONTAL);

	this->cancel = new wxButton(this, wxID_CANCEL, _T("Cancel"));
	this->submit = new wxButton(this, wxID_OK, _T("Submit"));

	horizontalSizer->Add(this->cancel, 0, wxRIGHT, 0);
	horizontalSizer->Add(this->submit, 0, wxRIGHT, 0);

	mainSizer->Add(horizontalSizer, 0, wxALIGN_CENTER_VERTICAL, 10);
	


	//Set Sizer
	SetSizer(mainSizer);
	mainSizer->SetSizeHints(this);

}

void EditUserDialog::ConnectControls() {

	this->changeUsername->Bind(wxEVT_BUTTON, &EditUserDialog::OnChangeUsername, this);
	this->changePassword->Bind(wxEVT_BUTTON, &EditUserDialog::OnChangePassword, this);
	
	this->cancel->Bind(wxEVT_BUTTON, &EditUserDialog::OnCancel, this);
	this->submit->Bind(wxEVT_BUTTON, &EditUserDialog::OnSubmit, this);

}



//Event Handler Functions
void EditUserDialog::OnChangeUsername(wxCommandEvent & event) {



}

void EditUserDialog::OnChangePassword(wxCommandEvent & event) {



}

void EditUserDialog::OnCancel(wxCommandEvent & event) {



}

void EditUserDialog::OnSubmit(wxCommandEvent & event) {



}
