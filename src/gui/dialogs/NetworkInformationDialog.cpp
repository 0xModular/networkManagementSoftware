/*
 * NetworkInformationDialog.cpp
 * Created on: Nov 7, 2023
 *
 * Author: Ubljudok
 */

#include "NetworkInformationDialog.h"

NetworkInformationDialog::NetworkInformationDialog(wxWindow* parent, Network* net) : wxDialog(parent, -1, _T("Network Information")) {

	//Set RVM
	this->net = net;

	CreateControls();
	ConnectControls();
		
}

//Construction Functions
void NetworkInformationDialog::CreateControls() {

	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* infoSizer = new wxBoxSizer(wxVERTICAL);

	//Create Info Box
	this->infoPanel = new wxScrolledWindow(this, wxID_ANY);
	this->infoPanel->SetMinSize(wxSize(250, 200));

	//TODO: Get Details, add it to this->info
	std::string text = "Joebama\nJoebama\nJoebama";
	this->info = new wxStaticText(infoPanel, wxID_ANY, text); 

	this->infoPanel->SetSizerAndFit(infoSizer);
	this->infoPanel->FitInside();
	this->infoPanel->SetScrollRate(5, 5);

	mainSizer->Add(this->infoPanel, 0, wxALL, 10);



	//Button Area
	this->ok = new wxButton(this, wxID_OK, _T("Close"));
	mainSizer->Add(this->ok, 0, wxALL, 10);



	//Set Sizer
	SetSizer(mainSizer);
        mainSizer->SetSizeHints(this);

}

void NetworkInformationDialog::ConnectControls() {

	this->ok->Bind(wxEVT_BUTTON, &NetworkInformationDialog::OnOk, this);

}



//Event Handler Function
void NetworkInformationDialog::OnOk(wxCommandEvent & event) {

	this->EndModal(wxID_OK);

}
