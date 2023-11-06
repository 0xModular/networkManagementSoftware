/*
 * NetworkField.h
 * Created on: Nov 1, 2023
 *
 * Author: Ubljudok
 */

#pragma once
#include <wx/wx.h>
#include <wx/sizer.h>
#include <vector>

#include "structures/Device.h"
#include "structures/Connection.h"
#include "structures/Note.h"

class NetworkField : public wxWindow {
	
	public:
		
		NetworkField(wxWindow *parent, wxWindowID id, const wxPoint &pos, const wxSize &size); //Constructor

	private:

		int mode; //Default is SELECTION_MODE
		
		/*
		 * inline static const int SELECTION_MODE = 0;
                 * inline static const int ADD_DEVICE_MODE = 1;
                 * inline static const int TEST_CONNECTION_MODE = 2;
                 * inline static const int ADD_NOTE_MODE = 3;
		 */
		
		void setMode(int newMode);
		int getMode();


		//Conditions
		bool mouseOverDevice;
		bool isDragging;



		//Objects
		wxMenu* networkFieldContextMenu;
		wxMenu* deviceContextMenu;
		std::vector<Device> devices;
		std::vector<Connection> connections;
		std::vector<Note> notes;


		//Network Field Events
		void OnPaint(wxPaintEvent & event);
		void DrawDeviceOnContext(wxGraphicsContext *gc);
		
		void OnMouseLeftDown(wxMouseEvent & event);
		void OnMouseMovement(wxMouseEvent & event);
		void OnMouseLeftUp(wxMouseEvent & event);

		void OnContextMenuEvent(wxContextMenuEvent & event); //Right Mouse
		void BuildContextMenu();

};
