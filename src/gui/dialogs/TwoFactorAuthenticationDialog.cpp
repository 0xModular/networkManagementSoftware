/*
 * TwoFactorAuthenticationDialog.cpp
 * Created on: Nov 1, 2023
 *
 * Author: Ubljudok
 */

#include "TwoFactorAuthenticationDialog.h"

TwoFactorAuthenticationDialog::TwoFactorAuthenticationDialog(wxWindow* parent, int currentCode, ReferenceValidationMechanism* rvm) : wxDialog(parent, -1, _T("Two Factor Authentication")) {

	this->code = currentCode;

	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
        wxBoxSizer* horizontalSizer;



	//2FA Entry Area
	horizontalSizer = new wxBoxSizer(wxHORIZONTAL);

	horizontalSizer->Add(new wxStaticText(this, wxID_STATIC, _T("Enter Code: ")), 0, wxALL|wxALIGN_CENTER_VERTICAL, 0);

	this->entry = new wxTextCtrl(this, -1, wxEmptyString, wxDefaultPosition, wxDefaultSize);
	horizontalSizer->Add(this->entry, 1, wxLEFT, 5);

	mainSizer->Add(horizontalSizer, 0, wxLEFT|wxRIGHT|wxBOTTOM|wxEXPAND, 10);



	//Warning Area
	this->warningText = new wxStaticText(this, wxID_STATIC, _T("Wrong password!"));

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

void TwoFactorAuthenticationDialog::ConnectControls() {

	this->cancel->Bind(wxEVT_BUTTON, &TwoFactorAuthenticationDialog::OnCancel, this);
        this->submit->Bind(wxEVT_BUTTON, &TwoFactorAuthenticationDialog::OnSubmit, this);

}



//Misc Functions
void TwoFactorAuthenticationDialog::UpdateCode(int newCode) {

	this->code = newCode;

}

void TwoFactorAuthenticationDialog::ProcessInput() {

	//Nothing Here for now...

}


//Event Handler Functions
void TwoFactorAuthenticationDialog::OnCancel(wxCommandEvent & event) {

	this->EndModal(wxID_CANCEL);

}

void TwoFactorAuthenticationDialog::OnSubmit(wxCommandEvent & event) {

	this->EndModal(wxID_OK);

}
