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
#include <numeric>

#include "../../ReferenceValidationMechanism.h"

class DeviceManagementDialog : public wxDialog {

        public:

                DeviceManagementDialog(wxWindow* parent, ReferenceValidationMechanism* rvm ); //Constructor
		~DeviceManagementDialog() noexcept {}; //Destructor

        private:
		
		//Construction Functions
		void CreateControls();
		void ConnectControls();



		//RVM
		ReferenceValidationMechanism* rvm;



		//Components
		wxScrolledWindow* devicesArea;
		wxPanel* buttonPanel;
		wxListView* devices;


		//Buttons
		//--Sorting--//
		wxButton* sortByName;
		wxButton* sortByMAC;
		wxButton* sortByIP;

		//--Other--//
		wxButton* refresh;
		wxButton* close;
		
		//--Button IDs--//
		inline static const int ID_SORTNAME = 0;
		inline static const int ID_SORTMAC = 1;
		inline static const int ID_SORTIP = 2;
		inline static const int ID_REFRESH = 3;
	


		//Event Handlers
		void onSortByName();
		void onSortByMAC();
		void onSortByIP();
		void onRefresh();
		void onClose();

};

