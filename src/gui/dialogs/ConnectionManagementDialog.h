/*
 * ConnectionManagementDialog.h
 * Created on: Nov 29, 2023
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

class ConnectionManagementDialog : public wxDialog {

        public:

                ConnectionManagementDialog(wxWindow* parent, ReferenceValidationMechanism* rvm ); //Constructor
                ~ConnectionManagementDialog() noexcept {}; //Destructor

        private:

                //Construction Functions
                void CreateControls();
                void ConnectControls();
                void Populate();



                //RVM
                ReferenceValidationMechanism* rvm;



                //Components
		wxScrolledWindow* connectionsArea;
		wxListView* connections;

		wxButton* sortByLocalPort;
		wxButton* sortByRemotePort;
		wxButton* sortByRemoteIP;
		wxButton* sortByPID;

		wxButton* refresh;
		wxButton* terminate;
		wxButton* close;



		//Button IDs
		inline static const int ID_REFRESH = 0;
		inline static const int ID_TERMINATE = 1;
		inline static const int ID_SORTLOCALPORT = 2;
		inline static const int ID_SORTREMOTEPORT = 3;
		inline static const int ID_SORTREMOTEIP = 4;
		inline static const int ID_SORTPID = 5;



		//Event Handler Functions
		void OnSortByLocalPort(wxCommandEvent & event);
		void OnSortByRemotePort(wxCommandEvent & event);
		void OnSortByRemoteIP(wxCommandEvent & event);
		void OnSortByPID(wxCommandEvent & event);
		void OnRefresh(wxCommandEvent & event);
		void OnTerminate(wxCommandEvent & event);
		void OnClose(wxCommandEvent & event);

};
