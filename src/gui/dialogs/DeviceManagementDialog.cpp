/*
 * DeviceManagementDialog.cpp
 * Created on: Nov 6, 2023
 *
 * Author: Ubljudok
 */

#include "DeviceManagementDialog.h"

//Constructor
DeviceManagementDialog::DeviceManagementDialog(wxWindow *parent, ReferenceValidationMechanism *rvm) : wxDialog(parent, -1, _T("Device Management")) {

	//Set RVM
	this->rvm = rvm;

	CreateControls();
	ConnectControls();

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
	
	mainSizer->Add(new wxStaticLine(this, wxID_ANY), 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 10);



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
	this->close = new wxButton(this, wxID_CANCEL, _T("Close"));

	horizontalSizer->Add(this->refresh, 0, wxRIGHT, 0);
	horizontalSizer->Add(this->close, 0, wxRIGHT, 0);
	
	mainSizer->Add(horizontalSizer, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 10);



	//Set Sizer
	SetSizer(mainSizer);
	mainSizer->SetSizeHints(this);


	
	//Get Initial Devices Populated
	
	//TEMP
	this->devices->InsertItem(0, "Test");
	this->devices->SetItem(0, 1, "Test");
	this->devices->SetItem(0, 2, "Test");

	this->devices->InsertItem(1, "Test");
        this->devices->SetItem(1, 1, "Test");
        this->devices->SetItem(1, 2, "Test");

	this->devices->InsertItem(2, "Test");
        this->devices->SetItem(2, 1, "Test");
        this->devices->SetItem(2, 2, "Test");

	this->devices->InsertItem(3, "Test");
        this->devices->SetItem(3, 1, "Test");
        this->devices->SetItem(3, 2, "Test");

	this->devices->InsertItem(4, "Test");
        this->devices->SetItem(4, 1, "Test");
        this->devices->SetItem(4, 2, "Test");

	this->devices->InsertItem(5, "Test");
        this->devices->SetItem(5, 1, "Test");
        this->devices->SetItem(5, 2, "Test");

	this->devices->InsertItem(6, "Test");
        this->devices->SetItem(6, 1, "Test");
        this->devices->SetItem(6, 2, "Test");

	this->devices->InsertItem(7, "Test");
        this->devices->SetItem(7, 1, "Test");
        this->devices->SetItem(7, 2, "Test");

	this->devices->InsertItem(8, "Test");
        this->devices->SetItem(8, 1, "Test");
        this->devices->SetItem(8, 2, "Test");

	this->devices->InsertItem(9, "Test");
        this->devices->SetItem(9, 1, "Test");
        this->devices->SetItem(9, 2, "Test");

	this->devices->InsertItem(10, "Test");
        this->devices->SetItem(10, 1, "Test");
        this->devices->SetItem(10, 2, "Test");

	this->devices->InsertItem(11, "Test");
        this->devices->SetItem(11, 1, "Test");
        this->devices->SetItem(11, 2, "Test");

}

void DeviceManagementDialog::ConnectControls() {



}
