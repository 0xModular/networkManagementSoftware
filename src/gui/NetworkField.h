/*
 * NetworkField.h
 * Created on: Nov 1, 2023
 *
 * Author: Ubljudok
 */

#pragma once
#include <wx/wx.h>
#include <wx/sizer.h>
#include <wx/graphics.h>
#include <wx/dcbuffer.h>

#include <vector>

#include "structures/DeviceOnGraph.h"
#include "structures/ConnectionOnGraph.h"
#include "structures/Note.h"

class NetworkField : public wxWindow {
	
	public:
		
		NetworkField(wxWindow *parent, wxWindowID id, const wxPoint &pos, const wxSize &size); //Constructor
		virtual ~NetworkField() noexcept {}; //Destructor

		void SetMode(int newMode);
                int GetMode();

	private:

		//Modes
		int mode;

		inline static const int SELECTION_MODE = 0; //Default
                inline static const int ADD_DEVICE_MODE = 1;
                inline static const int TEST_CONNECTION_MODE = 2;
               	inline static const int ADD_NOTE_MODE = 3;
		


		//Conditions
		bool mouseOverDevice;
		bool isDragging;



		//Objects
		wxMenu* networkFieldContextMenu;
		wxMenu* deviceContextMenu;
		std::vector<Device> devices;
		std::vector<Connection> connections;
		std::vector<Note> notes;
		
		std::vector<Device> selectionBuffer;

		wxPoint* mousePosition;

		//Network Field Events
		void OnPaint(wxPaintEvent & event);
		void DrawOnContext(wxGraphicsContext *gc);
		
		void MouseOverDevice(wxMouseEvent & event);
		void MouseLeaveDevice(wxMouseEvent & event);

		void OnMouseLeftDown(wxMouseEvent & event);
		void OnMouseMovement(wxMouseEvent & event);
		void OnMouseLeftUp(wxMouseEvent & event);
		void OnMouseScroll(wxMouseEvent & event);

		void OnContextMenuEvent(wxContextMenuEvent & event); //Right Mouse

		//Other Functions
		void AddDevice();
};
