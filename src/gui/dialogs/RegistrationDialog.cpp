/*
 * RegistrationDialog.cpp
 * Created on Nov 1, 2023
 *
 * Author: Ubljudok
 */

#include "RegistrationDialog.h"

//Constructor

RegistrationDialog::RegistrationDialog (wxWindow* parent, ReferenceValidationMechanism* rvm) : wxDialog(parent, -1, _T("Network Management Registration")) {
	
	CreateControls();
	ConnectControls();

}

void RegistrationDialog::CreateControls() {

	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
        wxBoxSizer* horizontalSizer;


        //Username Area
        horizontalSizer = new wxBoxSizer(wxHORIZONTAL);

        horizontalSizer->Add(new wxStaticText(this, wxID_STATIC, _T("Username: ")), 0, wxALL|wxALIGN_CENTER_VERTICAL, 0);

        this->usernameEntry = new wxTextCtrl(this, -1, wxEmptyString, wxDefaultPosition, wxDefaultSize);
        horizontalSizer->Add(this->usernameEntry, 1, wxLEFT, 5);

        mainSizer->Add(horizontalSizer, 0, wxLEFT|wxRIGHT|wxBOTTOM|wxEXPAND, 10);
	

		
	//Password Area
        horizontalSizer = new wxBoxSizer(wxHORIZONTAL);

        horizontalSizer->Add(new wxStaticText(this, wxID_STATIC, _T("Password: ")), 0, wxALL|wxALIGN_CENTER_VERTICAL, 0);

        this->passwordEntry = new wxTextCtrl(this, -1, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD);
        horizontalSizer->Add(this->passwordEntry, 1, wxLEFT, 5);

        mainSizer->Add(horizontalSizer, 0, wxLEFT|wxRIGHT|wxBOTTOM|wxEXPAND, 10);



	//Password Reentry Area
        horizontalSizer = new wxBoxSizer(wxHORIZONTAL);

        horizontalSizer->Add(new wxStaticText(this, wxID_STATIC, _T("Reenter Password: ")), 0, wxALL|wxALIGN_CENTER_VERTICAL, 0);

        this->passwordReentry = new wxTextCtrl(this, -1, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD);
        horizontalSizer->Add(this->passwordReentry, 1, wxLEFT, 5);

        mainSizer->Add(horizontalSizer, 0, wxLEFT|wxRIGHT|wxBOTTOM|wxEXPAND, 10);

        this->showPassword = new wxCheckBox(this, -1, _T("Show Password?"));

	mainSizer->Add(this->showPassword, 0, wxLEFT|wxRIGHT|wxBOTTOM, 10);

        mainSizer->Add(new wxStaticLine(this, wxID_STATIC), 0, wxLEFT|wxRIGHT|wxEXPAND, 10);



	//Warning Area
        this->warningText = new wxStaticText(this, wxID_STATIC, _T("Passwords Do Not Match!"));

        wxFont font = warningText->GetFont();
                font.MakeBold();
                warningText->SetFont(font);
                warningText->SetForegroundColour(*wxRED);

        mainSizer->Add(warningText, 0, wxLEFT|wxRIGHT|wxBOTTOM|wxALIGN_CENTER_HORIZONTAL, 10);



	//Button Area
	horizontalSizer = new wxBoxSizer(wxHORIZONTAL);

	this->cancel = new wxButton(this, wxID_CANCEL, _T("Cancel"));
        horizontalSizer->Add(this->cancel, 0, wxRIGHT, 0);

	this->submit = new wxButton(this, wxID_OK, _T("Submit"));
	horizontalSizer->Add(this->submit, 0, wxRIGHT, 0);

	mainSizer->Add(horizontalSizer, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 10);



	//Set Sizer
        SetSizer(mainSizer);



        //Other Operations
        this->warningText->Hide();

        mainSizer->SetSizeHints(this);

        this->submit->SetDefault();

}

void RegistrationDialog::ConnectControls() {

	this->showPassword->Bind(wxEVT_CHECKBOX, &RegistrationDialog::OnShowPassword, this);

        this->cancel->Bind(wxEVT_BUTTON, &RegistrationDialog::OnCancel, this);
        this->submit->Bind(wxEVT_BUTTON, &RegistrationDialog::OnSubmit, this);

}

//Misc Functions
bool RegistrationDialog::ComparePasswords() {

	return true;

}



//Event Handler Functions
void RegistrationDialog::OnShowPassword(wxCommandEvent & event) {

        Freeze();

        wxString shownPass1 = this->passwordEntry->GetValue();
        wxString shownPass2 = this->passwordReentry->GetValue();
	
	wxSizer* sizer1 = this->passwordEntry->GetContainingSizer();
	wxSizer* sizer2 = this->passwordReentry->GetContainingSizer();

        long from1, to1, from2, to2;

        this->passwordEntry->GetSelection(&from1, &to1);
	this->passwordReentry->GetSelection(&from2, &to2);

        int iStyle = (this->showPassword->IsChecked() ? 0 : wxTE_PASSWORD);

        sizer1->Detach(this->passwordEntry);
	sizer2->Detach(this->passwordReentry);
        delete this->passwordEntry;
	delete this->passwordReentry;

        this->passwordEntry = new wxTextCtrl(this, -1, shownPass1, wxDefaultPosition, wxDefaultSize, iStyle);
        this->passwordEntry->SetFocus();
        this->passwordEntry->SetSelection(from1, to1);

	this->passwordReentry = new wxTextCtrl(this, -1, shownPass2, wxDefaultPosition, wxDefaultSize, iStyle);
        this->passwordReentry->SetFocus();
        this->passwordReentry->SetSelection(from2, to2);

        sizer1->Add(this->passwordEntry, 1, wxRIGHT, 5);
        sizer1->Layout();
	sizer2->Add(this->passwordReentry, 1, wxRIGHT, 5);
	sizer2->Layout();

        Thaw();

}

void RegistrationDialog::OnSubmit(wxCommandEvent & event) {

	this->EndModal(wxID_OK);

}

void RegistrationDialog::OnCancel(wxCommandEvent & event) {

	this->EndModal(wxID_CANCEL);

}
