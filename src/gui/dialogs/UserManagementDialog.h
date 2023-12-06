/*
 * UserManagementDialog.h
 * Created on: Nov 6, 2023
 *
 * Author: Ubljudok
 */

#pragma once
#include <wx/wx.h>
#include <wx/listctrl.h>
#include <wx/statline.h>

#include <vector>

#include "../../ReferenceValidationMechanism.h"

#include "EditUserDialog.h"

class UserManagementDialog : public wxDialog {

        public:

                UserManagementDialog(wxWindow* parent, ReferenceValidationMechanism* rvm); //Constructor
		~UserManagementDialog() noexcept {};

        private:

                //Construction Functions
		void CreateControls();
		void ConnectControls();
		void Populate();



		//RVM
		ReferenceValidationMechanism* rvm;



		//Components
		wxScrolledWindow* userArea;
		wxListView* users;



		//Buttons
		//--General--//
		wxButton* refresh;
		wxButton* close;
		
		//--Users--//
		wxButton* sortByUsername;
		wxButton* sortByAccess;
		wxButton* sortByDate;
		wxButton* editUser;

		//--Button IDs--//
		inline static const int ID_REFRESH = 0;
		inline static const int ID_SORTUSERNAME = 1;
		inline static const int ID_SORTACCESS = 2;
		inline static const int ID_SORTDATE= 3;
		inline static const int ID_EDITUSER = 4;



		//Event Handlers
		void OnRefresh(wxCommandEvent & event);
		void OnClose(wxCommandEvent & event);
		
		void OnSortByUsername(wxCommandEvent & event);
		void OnSortByAccess(wxCommandEvent & event);
		void OnSortByDate(wxCommandEvent & event);
		void OnEditUser(wxCommandEvent & event);

};

