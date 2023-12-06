/*
 * DeviceManagementDialog.h
 * Created on Nov 6, 2023
 *
 * Author: Ubljudok
 */

#pragma once
#include <wx/wx.h>
#include <wx/listctrl.h>
#include <wx/statline.h>

#include <vector>
//#include <numeric>

#include "../../ReferenceValidationMechanism.h"

class DeviceManagementDialog : public wxDialog {

        public:

                DeviceManagementDialog(wxWindow* parent, Network* net); //Constructor
		~DeviceManagementDialog() noexcept {}; //Destructor

        private:
		
		//Construction Functions
		void CreateControls();
		void ConnectControls();
		void Populate();



		//Network
		Network* net;



		//Components
		wxScrolledWindow* devicesArea;
		wxListView* devices;
	


		//Buttons
		//--Sorting--//
		wxButton* sortByName;
		wxButton* sortByMAC;
		wxButton* sortByIP;

		//--Other--//
		wxButton* refresh;
		wxButton* close;
		wxButton* edit;
		wxButton* add;

		//--Button IDs--//
		inline static const int ID_SORTNAME = 0;
		inline static const int ID_SORTMAC = 1;
		inline static const int ID_SORTIP = 2;
		inline static const int ID_REFRESH = 3;
		inline static const int ID_EDIT = 4;
		inline static const int ID_ADD = 5;

		//Event Handlers
		void OnSortByName(wxCommandEvent & event);
		void OnSortByMAC(wxCommandEvent & event);
		void OnSortByIP(wxCommandEvent & event);
		void OnRefresh(wxCommandEvent & event);
		void OnClose(wxCommandEvent & event);
		void OnEdit(wxCommandEvent & event);
		void OnAdd(wxCommandEvent & event);

};

