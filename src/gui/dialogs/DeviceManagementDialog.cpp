/*
 * DeviceManagementDialog.cpp
 * Created on: Nov 6, 2023
 *
 * Author: Ubljudok
 */

#include "DeviceManagementDialog.h"

//Constructor
DeviceManagementDialog::DeviceManagementDialog(wxWindow *parent, Network* net) : wxDialog(parent, -1, _T("Device Management")) {

	//Set Network
	this->net = net;

	CreateControls();
	ConnectControls();
	Populate();

}



//Construction Functions
void DeviceManagementDialog::CreateControls() {

	//Create Sizers
	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* horizontalSizer;
	wxBoxSizer* verticalSizer;

	

	//Create Panels
	this->devicesArea = new wxScrolledWindow(this, wxID_ANY);

	

	//Create Sort Button Area
	horizontalSizer = new wxBoxSizer(wxHORIZONTAL);
	
	this->sortByName = new wxButton(this, this->ID_SORTNAME, _T("Sort By Name"));
        this->sortByMAC = new wxButton(this, this->ID_SORTMAC, _T("Sort By MAC"));
        this->sortByIP = new wxButton(this, this->ID_SORTIP, _T("Sort By IP Address"));

	horizontalSizer->Add(this->sortByName, 0, wxEXPAND, 0);
        horizontalSizer->Add(this->sortByMAC, 0, wxEXPAND, 0);
        horizontalSizer->Add(this->sortByIP, 0, wxEXPAND, 0);

	mainSizer->Add(horizontalSizer, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 10);
	


	//Create List Foundation
	horizontalSizer = new wxBoxSizer(wxHORIZONTAL);

	verticalSizer = new wxBoxSizer(wxVERTICAL);
	
	this->devices = new wxListView(this->devicesArea);

	this->devices->AppendColumn("Name");
	this->devices->AppendColumn("MAC Address");
	this->devices->AppendColumn("IPv4 Address");

	this->devices->SetColumnWidth(0, 150);
	this->devices->SetColumnWidth(1, 200);
	this->devices->SetColumnWidth(2, 200);

	verticalSizer->Add(this->devices, 0, wxEXPAND, 0);
	
	this->devicesArea->SetSizerAndFit(verticalSizer);
	this->devicesArea->FitInside();
	this->devicesArea->SetScrollRate(5, 5);

	mainSizer->Add(this->devicesArea, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 10);

	mainSizer->Add(new wxStaticLine(this, wxID_ANY), 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 10);



	//Create Action Button Area
	horizontalSizer = new wxBoxSizer(wxHORIZONTAL);

	this->refresh = new wxButton(this, this->ID_REFRESH, _T("Refresh"));
	this->edit = new wxButton(this, this->ID_EDIT, _T("Edit Selected Device"));
	this->add = new wxButton(this, this->ID_ADD, _T("Add Device"));
	this->close = new wxButton(this, wxID_CANCEL, _T("Close"));

	horizontalSizer->Add(this->refresh, 0, wxRIGHT, 0);
	horizontalSizer->Add(this->edit, 0, wxRIGHT, 0);
	horizontalSizer->Add(this->add, 0, wxRIGHT, 0);
	horizontalSizer->Add(this->close, 0, wxRIGHT, 0);
	
	mainSizer->Add(horizontalSizer, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 10);



	//Set Sizer
	SetSizer(mainSizer);
	mainSizer->SetSizeHints(this);

}

void DeviceManagementDialog::ConnectControls() {

	this->sortByName->Bind(wxEVT_BUTTON, &DeviceManagementDialog::OnSortByName, this);
	this->sortByMAC->Bind(wxEVT_BUTTON, &DeviceManagementDialog::OnSortByMAC, this);
	this->sortByIP->Bind(wxEVT_BUTTON, &DeviceManagementDialog::OnSortByIP, this);

	this->refresh->Bind(wxEVT_BUTTON, &DeviceManagementDialog::OnRefresh, this);
	this->close->Bind(wxEVT_BUTTON, &DeviceManagementDialog::OnClose, this);
	this->edit->Bind(wxEVT_BUTTON, &DeviceManagementDialog::OnEdit, this);
	this->add->Bind(wxEVT_BUTTON, &DeviceManagementDialog::OnAdd, this);

}

void DeviceManagementDialog::Populate() {
/*
	Network* network = this->rvm->GetNetwork();

	std::vector<Device> devices = network->GetDeviceList(this->rvm);

	//Iterate Through Device Vector, fill appropriate info to each column
*/

	std::vector<Device> devicesVector = net->GetDeviceList();
	int i = 0;
	
	for (auto &device : devicesVector) {
	
		this->devices->InsertItem(i, device.GetName());
		this->devices->SetItem(i, 1, device.GetMac());
		this->devices->SetItem(i, 2, device.GetIpv4());
		
		i++;

	}	

}



//Event Handler Functions
void DeviceManagementDialog::OnSortByName(wxCommandEvent & event) {



}

void DeviceManagementDialog::OnSortByMAC(wxCommandEvent & event) {



}

void DeviceManagementDialog::OnSortByIP(wxCommandEvent & event) {



}

void DeviceManagementDialog::OnRefresh(wxCommandEvent & event) {

	Populate();

}

void DeviceManagementDialog::OnClose(wxCommandEvent & event) {

	this->EndModal(wxID_CANCEL);

}

void DeviceManagementDialog::OnEdit(wxCommandEvent & event) {



}

void DeviceManagementDialog::OnAdd(wxCommandEvent & event) {



}
