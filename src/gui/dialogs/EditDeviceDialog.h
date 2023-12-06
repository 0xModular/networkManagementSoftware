/*
 * EditDeviceDialog.h
 * Created on Nov 15, 2023
 *
 * Author: Ubljudok
 */

#pragma once
#include <wx/wx.h>
#include <wx/statline.h>
#include <wx/listctrl.h>

#include <string>

#include "../../ReferenceValidationMechanism.h"

class ReferenceValidationMechanism;

class EditDeviceDialog : public wxDialog {

        public:

                EditDeviceDialog(wxWindow* parent, Device* device); //Constructor
                ~EditDeviceDialog() noexcept {}; //Destructor

        private:

                //Constructor Functions
                void CreateControls();
                void ConnectControls();
		void Populate();


                //Device
		Device* device;



	 	//Components
		wxScrolledWindow* connectionsArea;
		wxListView* connections;



                //Control Variables
		wxButton* sortByLocalPort;
		wxButton* sortByRemotePort;
		wxButton* sortByRemoteIP;
		wxButton* sortByPID;

		wxButton* terminateConnection;
		wxButton* close;

		wxCheckBox* staticDynamic;

		//--Button IDs--//
		inline static const int ID_SORTLOCALPORT = 0;
		inline static const int ID_SORTREMOTEPORT = 1;
		inline static const int ID_SORTREMOTEIP = 2;
		inline static const int ID_SORTPID = 3;
		inline static const int ID_TERMINATE = 4;



		//Event Handler Functions
		void OnSortByLocalPort(wxCommandEvent & event);
		void OnSortByRemotePort(wxCommandEvent & event);
		void OnSortByRemoteIP(wxCommandEvent & event);
		void OnSortByPID(wxCommandEvent & event);
		void OnTerminateConnection(wxCommandEvent & event);
		void OnClose(wxCommandEvent & event);

};
