/*
 * EditPasswordDialog.cpp
 * Created on Nov 29, 2023
 *
 * Author: Ubljudok
 */

#include "EditPasswordDialog.h"

//Constructor
EditPasswordDialog::EditPasswordDialog(wxWindow* parent, ReferenceValidationMechanism* rvm, Account* user) : wxDialog(parent, -1, _T("Edit Password")) {

        //Set RVM and User
        this->rvm;
        this->user;

        CreateControls();
        ConnectControls();

}


//Construction Functions
void EditPasswordDialog::CreateControls() {

        wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
        wxBoxSizer* horizontalSizer;



        //New Password Entry
        horizontalSizer = new wxBoxSizer(wxHORIZONTAL);

        horizontalSizer->Add(new wxStaticText(this, wxID_STATIC, _T("Enter New Password: ")), 0, wxALL|wxALIGN_CENTER_VERTICAL, 0);

        this->newPasswordEntry = new wxTextCtrl(this, -1, wxEmptyString, wxDefaultPosition, wxDefaultSize);

        horizontalSizer->Add(this->newPasswordEntry, 1, wxLEFT, 5);
        mainSizer->Add(horizontalSizer, 0, wxLEFT|wxRIGHT|wxBOTTOM|wxEXPAND, 10);



        //New Password Reentry
        horizontalSizer = new wxBoxSizer(wxHORIZONTAL);

        horizontalSizer->Add(new wxStaticText(this, wxID_STATIC, _T("Reenter Password: ")), 0, wxALL|wxALIGN_CENTER_VERTICAL, 0);

        this->newPasswordReentry = new wxTextCtrl(this, -1, wxEmptyString, wxDefaultPosition, wxDefaultSize);

        horizontalSizer->Add(this->newPasswordReentry, 1, wxLEFT, 5);
        mainSizer->Add(horizontalSizer, 0, wxLEFT|wxRIGHT|wxBOTTOM|wxEXPAND, 10);

	

	//Show Password
	this->showPassword = new wxCheckBox(this, -1, _T("Show Password?"));

        mainSizer->Add(this->showPassword, 0, wxLEFT|wxRIGHT|wxBOTTOM, 10);

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

void EditPasswordDialog::ConnectControls() {

        this->cancel->Bind(wxEVT_BUTTON, &EditPasswordDialog::OnCancel, this);
        this->submit->Bind(wxEVT_BUTTON, &EditPasswordDialog::OnSubmit, this);

	this->showPassword->Bind(wxEVT_CHECKBOX, &EditPasswordDialog::OnShowPassword, this);

}



//Event Handler Functions
void EditPasswordDialog::OnShowPassword(wxCommandEvent & event) {

	Freeze();

        wxString shownPass1 = this->newPasswordEntry->GetValue();
        wxString shownPass2 = this->newPasswordReentry->GetValue();
        
        wxSizer* sizer1 = this->newPasswordEntry->GetContainingSizer();
        wxSizer* sizer2 = this->newPasswordReentry->GetContainingSizer();

        long from1, to1, from2, to2;

        this->newPasswordEntry->GetSelection(&from1, &to1);
        this->newPasswordReentry->GetSelection(&from2, &to2);

        int iStyle = (this->showPassword->IsChecked() ? 0 : wxTE_PASSWORD);

        sizer1->Detach(this->newPasswordEntry);
        sizer2->Detach(this->newPasswordReentry);
        delete this->newPasswordEntry;
        delete this->newPasswordReentry;

        this->newPasswordEntry = new wxTextCtrl(this, -1, shownPass1, wxDefaultPosition, wxDefaultSize, iStyle);
        this->newPasswordEntry->SetFocus();
        this->newPasswordEntry->SetSelection(from1, to1);

        this->newPasswordReentry = new wxTextCtrl(this, -1, shownPass2, wxDefaultPosition, wxDefaultSize, iStyle);
        this->newPasswordReentry->SetFocus();
        this->newPasswordReentry->SetSelection(from2, to2);

        sizer1->Add(this->newPasswordEntry, 1, wxRIGHT, 5);
        sizer1->Layout();
        sizer2->Add(this->newPasswordReentry, 1, wxRIGHT, 5);
        sizer2->Layout();

        Thaw();

}

void EditPasswordDialog::OnCancel(wxCommandEvent & event) {



}

void EditPasswordDialog::OnSubmit(wxCommandEvent & event) {



}

