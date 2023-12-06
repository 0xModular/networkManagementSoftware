/*
 * AddDeviceDialog.cpp
 * Created on Nov 15, 2023
 *
 * Author: Ubljudok
 */

#include "AddDeviceDialog.h"

AddDeviceDialog::AddDeviceDialog(wxWindow* parent, Network* net) : wxDialog(parent, -1, _T("Add Device")) {

	//Set Network
	this->net = net;

	CreateControls();
	ConnectControls();

}



//Construction Fucntions
void AddDeviceDialog::CreateControls() {

	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
        wxBoxSizer* horizontalSizer;



	//Name
	horizontalSizer = new wxBoxSizer(wxHORIZONTAL);

	horizontalSizer->Add(new wxStaticText(this, wxID_STATIC, _T("Name: ")), 0, wxALL|wxALIGN_CENTER_VERTICAL, 0);

	this->name = new wxTextCtrl(this, -1, wxEmptyString, wxDefaultPosition, wxDefaultSize);
	horizontalSizer->Add(this->name, 1, wxLEFT, 5);

	mainSizer->Add(horizontalSizer, 0, wxLEFT|wxRIGHT|wxBOTTOM|wxEXPAND, 10);



	//MAC
        horizontalSizer = new wxBoxSizer(wxHORIZONTAL);

        horizontalSizer->Add(new wxStaticText(this, wxID_STATIC, _T("MAC: ")), 0, wxALL|wxALIGN_CENTER_VERTICAL, 0);

        this->MAC = new wxTextCtrl(this, -1, wxEmptyString, wxDefaultPosition, wxDefaultSize);
        horizontalSizer->Add(this->MAC, 1, wxLEFT, 5);

        mainSizer->Add(horizontalSizer, 0, wxLEFT|wxRIGHT|wxBOTTOM|wxEXPAND, 10);



	//IP
        horizontalSizer = new wxBoxSizer(wxHORIZONTAL);

        horizontalSizer->Add(new wxStaticText(this, wxID_STATIC, _T("IPv4: ")), 0, wxALL|wxALIGN_CENTER_VERTICAL, 0);

        this->IP = new wxTextCtrl(this, -1, wxEmptyString, wxDefaultPosition, wxDefaultSize);
        horizontalSizer->Add(this->IP, 1, wxLEFT, 5);

        mainSizer->Add(horizontalSizer, 0, wxLEFT|wxRIGHT|wxBOTTOM|wxEXPAND, 10);



	//Wired?
	this->wired = new wxCheckBox(this, -1, _T("Wired Connection?"));
	
	mainSizer->Add(this->wired, 0, wxLEFT|wxRIGHT|wxBOTTOM, 10);
	
	mainSizer->Add(new wxStaticLine(this, wxID_STATIC), 0, wxLEFT|wxRIGHT|wxEXPAND, 10);



	//Warning Area
	this->warningText = new wxStaticText(this, wxID_STATIC, wxEmptyString);

        wxFont font = warningText->GetFont();
                font.MakeBold();
                warningText->SetFont(font);
                warningText->SetForegroundColour(*wxRED);

        mainSizer->Add(warningText, 0, wxLEFT|wxRIGHT|wxBOTTOM|wxALIGN_CENTER_HORIZONTAL, 10);



	//Button Area
	horizontalSizer = new wxBoxSizer(wxHORIZONTAL);

	this->ok = new wxButton(this, wxID_OK, _T("Apply & Exit"));
	this->cancel = new wxButton(this, wxID_CANCEL, _T("Cancel"));

	horizontalSizer->Add(this->ok, 0, wxALL, 0);
	horizontalSizer->Add(this->cancel, 0, wxALL, 0);

	mainSizer->Add(horizontalSizer, 0, wxLEFT|wxRIGHT|wxBOTTOM|wxEXPAND, 10);



	//Set Sizer
	SetSizer(mainSizer);



	//Other Operations
        
        this->warningText->Hide();

        mainSizer->SetSizeHints(this);

        this->ok->SetDefault();

}

void AddDeviceDialog::ConnectControls() {

	this->ok->Bind(wxEVT_BUTTON, &AddDeviceDialog::OnOk, this);
	this->cancel->Bind(wxEVT_BUTTON, &AddDeviceDialog::OnCancel, this);

}



//Event Handler Function
void AddDeviceDialog::OnOk(wxCommandEvent & event) {

	this->EndModal(wxID_OK);

}

void AddDeviceDialog::OnCancel(wxCommandEvent & event) {

	this->EndModal(wxID_CANCEL);

}
