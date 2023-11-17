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

class UserManagementDialog : public wxDialog {

        public:

                UserManagementDialog(wxWindow* parent, ReferenceValidationMechanism* rvm); //Constructor
		~UserManagementDialog() noexcept {};

        private:

                //Construction Functions
		void CreateControls();
		void ConnectControls();
		void PopulateUsers();
		void PopulateQueue();



		//RVM
		ReferenceValidationMechanism* rvm;



		//Components
		wxScrolledWindow* userArea;
		wxScrolledWindow* queueArea;
		wxListView* users;
		wxListView* actionQueue; //Queue of actions (e.g. new account created) waiting to be approved by Network Admin



		//Buttons
		//--General--//
		wxButton* refresh;
		wxButton* close;
		
		//--Users--//
		wxButton* sortByUsername;
		wxButton* sortByAccess;
		wxButton* sortByDate;
		wxButton* editUser;

		//--Queue--//
		wxButton* approve;
		wxButton* reject;
		wxButton* approveAll;
		wxButton* rejectAll;

		//--Button IDs--//
		inline static const int ID_REFRESH = 0;
		inline static const int ID_SORTUSERNAME = 1;
		inline static const int ID_SORTACCESS = 2;
		inline static const int ID_SORTDATE= 3;
		inline static const int ID_EDITUSER = 4;
		inline static const int ID_APPROVE = 5;
		inline static const int ID_REJECT = 6;
		inline static const int ID_APPROVEALL = 7;
		inline static const int ID_REJECTALL = 8;



		//Event Handlers
		void OnRefresh(wxCommandEvent & event);
		void OnClose(wxCommandEvent & event);
		
		void OnSortByUsername(wxCommandEvent & event);
		void OnSortByAccess(wxCommandEvent & event);
		void OnSortByDate(wxCommandEvent & event);
		void OnEditUser(wxCommandEvent & event);

		void OnApprove(wxCommandEvent & event);
		void OnReject(wxCommandEvent & event);
		void OnApproveAll(wxCommandEvent & event);
		void OnRejectAll(wxCommandEvent & event);

};

