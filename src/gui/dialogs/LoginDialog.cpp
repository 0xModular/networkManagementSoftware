/*
 * LoginDialog.cpp
 * Created on: Oct 26, 2023
 *
 * Author: Ubljudok
 */

#include "LoginDialog.h"

//Constructor
LoginDialog::LoginDialog(wxWindow* parent, int maxAttempts, struct Credentials* credentials, ReferenceValidationMechanism* rvm) : wxDialog(parent, -1, _T("Network Manager Login")) {

	this->cred = credentials;

	this->attempts = 0;
	this->maxAttempts = maxAttempts;

	CreateControls();
	ConnectControls();

}

void LoginDialog::CreateControls() {

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

	this->showPassword = new wxCheckBox(this, -1, _T("Show Password?"));

	mainSizer->Add(this->showPassword, 0, wxLEFT|wxRIGHT|wxBOTTOM, 10);

	mainSizer->Add(new wxStaticLine(this, wxID_STATIC), 0, wxLEFT|wxRIGHT|wxEXPAND, 10);



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

	this->rgstr = new wxButton(this, this->ID_RGSTR, _T("Register New Account"));
        horizontalSizer->Add(this->rgstr, 0, wxRIGHT, 0);

	this->ok = new wxButton(this, wxID_OK, _T("Log In"));
        horizontalSizer->Add(this->ok, 0, wxALL, 0);

	mainSizer->Add(horizontalSizer, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 10);



	//Set Sizer
	SetSizer(mainSizer);



	//Other Operations
	
	this->warningText->Hide();

	mainSizer->SetSizeHints(this);

	this->ok->SetDefault();

}

void LoginDialog::ConnectControls() {

	this->showPassword->Bind(wxEVT_CHECKBOX, &LoginDialog::OnShowPassword, this);
	
	this->cancel->Bind(wxEVT_BUTTON, &LoginDialog::OnCancel, this);
	this->rgstr->Bind(wxEVT_BUTTON, &LoginDialog::OnRegister, this);
	this->ok->Bind(wxEVT_BUTTON, &LoginDialog::OnOk, this);

}



//Event Handler Functions
void LoginDialog::OnShowPassword(wxCommandEvent & event) {

	Freeze();

	wxString shownPass = this->passwordEntry->GetValue();
	wxSizer* sizer = this->passwordEntry->GetContainingSizer();

	long from, to;

	this->passwordEntry->GetSelection(&from, &to);

	int iStyle = (this->showPassword->IsChecked() ? 0 : wxTE_PASSWORD);

	sizer->Detach(this->passwordEntry);
	delete this->passwordEntry;

	this->passwordEntry = new wxTextCtrl(this, -1, shownPass, wxDefaultPosition, wxDefaultSize, iStyle);
	this->passwordEntry->SetFocus();
	this->passwordEntry->SetSelection(from, to);

	sizer->Add(this->passwordEntry, 1, wxRIGHT, 5);
	sizer->Layout();

	Thaw();

}

void LoginDialog::OnCancel(wxCommandEvent & event) {

	this->EndModal(wxID_CANCEL);

}

void LoginDialog::OnRegister(wxCommandEvent & event) {

	this->EndModal(this->ID_RGSTR);

}

void LoginDialog::OnOk(wxCommandEvent & event) {

	//this->warningText->Show();	
	//GetSizer()->SetSizeHints(this);
	
	//Get Input
	wxString wx_Username = this->usernameEntry->GetValue();
	wxString wx_Password = this->passwordEntry->GetValue();

	this->username = std::string(wx_Username.mb_str(wxConvUTF8));
	this->password = std::string(wx_Password.mb_str(wxConvUTF8));

	struct Credentials credentials;
	credentials.username = this->username;
	credentials.password = this->password;

	*cred = credentials;	

	this->EndModal(wxID_OK);
}
