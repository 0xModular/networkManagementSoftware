/*
 * EditDeviceDialog.cpp
 * Created on: Nov 15, 2023
 *
 * Author: Ubljudok
 */

#include "EditDeviceDialog.h"

EditDeviceDialog::EditDeviceDialog(wxWindow* parent, Device* device) : wxDialog(parent, -1, _T("Edit Device")) {

	//Set Device
	this->device = device;

	CreateControls();
	ConnectControls();
	Populate();

}

//Construction Functions
void EditDeviceDialog::CreateControls() {

	//Create Sizers
        wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
        wxBoxSizer* horizontalSizer;
        wxBoxSizer* verticalSizer;



	//Create Panels
	this->connectionsArea = new wxScrolledWindow(this, wxID_ANY);



	//Create DHCP Toggle CheckButton Area
	this->staticDynamic = new wxCheckBox(this, -1, _T("Turn on DHCP"));
	mainSizer->Add(this->staticDynamic, 0, wxLEFT|wxRIGHT|wxBOTTOM, 10);
	mainSizer->Add(new wxStaticLine(this, wxID_STATIC), 0, wxLEFT|wxRIGHT|wxEXPAND, 10);



	//Create Sort Button Area
	horizontalSizer = new wxBoxSizer(wxHORIZONTAL);
	
	this->sortByLocalPort = new wxButton(this, this->ID_SORTLOCALPORT, _T("Sort By Local Port"));
        this->sortByRemotePort = new wxButton(this, this->ID_SORTREMOTEPORT, _T("Sort By Remote Port"));
	this->sortByRemoteIP = new wxButton(this, this->ID_SORTREMOTEIP, _T("Sort By Remote IP"));
        this->sortByPID = new wxButton(this, this->ID_SORTPID, _T("Sort by PID"));

	horizontalSizer->Add(this->sortByLocalPort, 0, wxRIGHT, 0);
	horizontalSizer->Add(this->sortByRemotePort, 0, wxRIGHT, 0);
	horizontalSizer->Add(this->sortByRemoteIP, 0, wxRIGHT, 0);
	horizontalSizer->Add(this->sortByPID, 0, wxRIGHT, 0);

	mainSizer->Add(horizontalSizer, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 10);



	//Create List of Connections
	horizontalSizer = new wxBoxSizer(wxHORIZONTAL);

        verticalSizer = new wxBoxSizer(wxVERTICAL);

	this->connections = new wxListView(this->connectionsArea);

	this->connections->AppendColumn("Local Port");
	this->connections->AppendColumn("Remote Port");
	this->connections->AppendColumn("Remote IP");
	this->connections->AppendColumn("Status");
	this->connections->AppendColumn("PID");

	this->connections->SetColumnWidth(0, 80);
	this->connections->SetColumnWidth(1, 80);
	this->connections->SetColumnWidth(2, 120);
	this->connections->SetColumnWidth(3, 80);
	this->connections->SetColumnWidth(4, 100);

	verticalSizer->Add(this->connections, 0, wxEXPAND, 0);

	this->connectionsArea->SetSizerAndFit(verticalSizer);
	this->connectionsArea->FitInside();
	this->connectionsArea->SetScrollRate(5, 5);

	mainSizer->Add(this->connectionsArea, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 10);

        mainSizer->Add(new wxStaticLine(this, wxID_ANY), 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 10);



	//Create Button Area
	horizontalSizer = new wxBoxSizer(wxHORIZONTAL);

	this->terminateConnection = new wxButton(this, this->ID_TERMINATE, _T("Terminate Connection"));
	this->close = new wxButton(this, wxID_OK, _T("Close"));

	horizontalSizer->Add(this->terminateConnection, 0, wxRIGHT, 0);
        horizontalSizer->Add(this->close, 0, wxRIGHT, 0);

	mainSizer->Add(horizontalSizer, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 10);



	//Set Sizer
        SetSizer(mainSizer);
        mainSizer->SetSizeHints(this);

}

void EditDeviceDialog::ConnectControls() {

	this->sortByLocalPort->Bind(wxEVT_BUTTON, &EditDeviceDialog::OnSortByLocalPort, this);
        this->sortByRemotePort->Bind(wxEVT_BUTTON, &EditDeviceDialog::OnSortByRemotePort, this);
        this->sortByRemoteIP->Bind(wxEVT_BUTTON, &EditDeviceDialog::OnSortByRemoteIP, this);
        this->sortByPID->Bind(wxEVT_BUTTON, &EditDeviceDialog::OnSortByPID, this);

	this->terminateConnection->Bind(wxEVT_BUTTON, &EditDeviceDialog::OnTerminateConnection, this);
        this->close->Bind(wxEVT_BUTTON, &EditDeviceDialog::OnClose, this);

}

void EditDeviceDialog::Populate() {

	/*
	 *
	 * LAYNE
	 *
	 * 

	std::vector<Connection> connectionsVector = this->device->GetConnectionVector();
        int i = 0;

        for (auto &con : connectionsVector) {

                this->connections->InsertItem(i, con.localPort);
                this->connections->SetItem(i, 1, con.remotePort);
                this->connections->SetItem(i, 2, con.remoteIp);
		this->connections->SetItem(i, 3, con.status);
		this->connections->SetItem(i, 4, con.PID);

                i++;

        }
	*/

}



//Event Handler Functions
void EditDeviceDialog::OnSortByLocalPort(wxCommandEvent & event) {



}

void EditDeviceDialog::OnSortByRemotePort(wxCommandEvent & event) {



}

void EditDeviceDialog::OnSortByRemoteIP(wxCommandEvent & event) {



}

void EditDeviceDialog::OnSortByPID(wxCommandEvent & event) {



}

void EditDeviceDialog::OnTerminateConnection(wxCommandEvent & event) {



}

void EditDeviceDialog::OnClose(wxCommandEvent & event) {



}


