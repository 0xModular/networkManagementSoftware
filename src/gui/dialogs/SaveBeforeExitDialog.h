/*
 * SaveBeforeExitDialog.h
 * Created on Nov 7, 2023
 *
 * Author: Ubljudok
 */


#pragma once
#include <wx/wx.h>
#include <wx/statline.h>
#include <wx/radiobut.h>

#include <string>

#include "../../ReferenceValidationMechanism.h"

class ReferenceValidationMechanism;

class SaveBeforeExitDialog.h : public wxDialog {

	public:

		SaveBeforeExitDialog(wxWindow* parent, ReferenceValidationMechanism* rvm); //Constructor
                ~SaveBeforeExitDialog() noexcept {}; //Destructor
	
	private:

		//Construction Functions
		void CreateControls();
		void ConnectControls();



		//RVM
		ReferenceValidationMechanism* rvm;
		
		
		
		//Control Variables
		wxButton* cancel;
		wxButton* exitSave;
		wxButton* exitNoSave;



		//Event Handler Functions
		void OnCancel(wxCommandEvent & event);
		void OnExitSave(wxCommandEvent & event);
		void OnExitNoSave(wxCommandEvent & event);

};
