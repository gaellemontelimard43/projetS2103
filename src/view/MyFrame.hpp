#ifndef __MyFrame_HPP__
#define __MyFrame_HPP__

#include "wx/wxprec.h"

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include<wx/filedlg.h>
#include <wx/image.h>
#include <wx/file.h>
#include <wx/bitmap.h>

#include "MyDrawingPanel.hpp"
#include "MyControlPanel.hpp"



//------------------------------------------------------------------------
class MyFrame: public wxFrame
//------------------------------------------------------------------------
{
public:
	MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
	MyControlPanel* GetControlPanel(){return m_controlPanel ;} ;
	void RefreshDrawing(){m_drawingPanel->Refresh() ;} ;
	void ControleurBouton(int ID);
	void ControleurClick(int m_ClickNumber);

protected:
	void OnQuit(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);
	void OnOpenFile(wxCommandEvent& WXUNUSED(event) ) ;
	void OnSaveFile(wxCommandEvent & WXUNUSED(event)) ;
	void OnClose(wxCloseEvent& event) ;
	void OnSize(wxSizeEvent &event) ;
	

	MyControlPanel *m_controlPanel; // the panel with controls
	MyDrawingPanel *m_drawingPanel; // the panel in which we draw
} ;

#endif