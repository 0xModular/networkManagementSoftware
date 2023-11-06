/*
 * NetworkField.h
 * Created on: Nov 1, 2023
 *
 * Author: Ubljudok
 */

#pragma once
#include <wx/wx.h>
#include <wx/sizer.h>

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



		//Conditions
		bool mouseOverDevice;
		bool isDragging;



		//Objects
		wxMenu* networkFieldContextMenu;
		wxMenu* deviceContextMenu;



		//Network Field Events
		void OnPaint(wxPaintEvent &);
		void DrawDeviceOnContext(wxGraphicsContext *gc);
		
		void OnMouseLeftDown(wxMouseEvent &);
		void OnMouseMovement(wxMouseEvent &);
		void OnMouseLeftUp(wxMouseEvent &);

		void OnContextMenuEvent(wxContextMenuEvent &); //Right Mouse
		void BuildContextMenu();
};
