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
#include "MyFrame.hpp"
#include "../model/Point.h"

#define WIDGET_PANEL_WIDTH	150

//************************************************************************
//************************************************************************
// MyDrawingPanel class (where drawings are displayed)
//************************************************************************
//************************************************************************

//------------------------------------------------------------------------
MyDrawingPanel::MyDrawingPanel(wxWindow *parent) : wxPanel(parent)
//------------------------------------------------------------------------
// In this constructor, bind some mouse events and the paint event with the appropriate methods
{
	int w, h ;
	GetParent()->GetClientSize(&w,&h) ;
	SetSize(wxRect(wxPoint(WIDGET_PANEL_WIDTH,0), wxPoint(w, h))) ;
	SetBackgroundColour(wxColour(0xFF,0xFF,0xFF)) ;
	Bind(wxEVT_MOTION, &MyDrawingPanel::OnMouseMove, this);
	Bind(wxEVT_LEFT_DOWN, &MyDrawingPanel::OnMouseLeftDown, this);
	Bind(wxEVT_PAINT, &MyDrawingPanel::OnPaint, this) ;
	m_onePoint.x = (w-WIDGET_PANEL_WIDTH)/2 ;
	m_onePoint.y = h/2 ;
	m_mousePoint = m_onePoint ;
}

//------------------------------------------------------------------------
void MyDrawingPanel::OnMouseMove(wxMouseEvent &event)
//------------------------------------------------------------------------
// called when the mouse is moved
{
	m_mousePoint.x = event.m_x ;
	m_mousePoint.y = event.m_y ;
	Refresh() ;	// send an event that calls the OnPaint method
}

//------------------------------------------------------------------------
void MyDrawingPanel::OnMouseLeftDown(wxMouseEvent &event)
//------------------------------------------------------------------------
// called when the mouse left button is pressed
{
	MyFrame* frame = (MyFrame*)GetParent() ;
	MyControlPanel* panel = (MyControlPanel*)GetParent() ;
	m_onePoint.x = event.m_x ;
	m_onePoint.y = event.m_y ;
	//Refresh() ; // send an event that calls the OnPaint method


	switch(panel->Id_Bouton){
		case 1: 
			if(m_ClickNumber = 0){
				frame->ControleurClick(m_ClickNumber,m_onePoint.x,m_onePoint.y);
				m_ClickNumber ++ ;
			}else{
				frame->ControleurClick(m_ClickNumber,m_onePoint.x,m_onePoint.y);
				m_ClickNumber = 0 ;
			}
		break;

		case 2:
			if(m_ClickNumber = 0){
				frame->ControleurClick(m_ClickNumber,m_onePoint.x,m_onePoint.y);
				m_ClickNumber ++ ;
			}else{
				frame->ControleurClick(m_ClickNumber,m_onePoint.x,m_onePoint.y);
				m_ClickNumber = 0 ;
			}

		break;

		case 3:

		break;

		case 4:
			if(m_ClickNumber = 0){
				frame->ControleurClick(m_ClickNumber,m_onePoint.x,m_onePoint.y);
				m_ClickNumber ++ ;
			}else{
				frame->ControleurClick(m_ClickNumber,m_onePoint.x,m_onePoint.y);
				m_ClickNumber = 0 ;
			}
		break;
	}
}

//------------------------------------------------------------------------
void MyDrawingPanel::OnPaint(wxPaintEvent &event)
//------------------------------------------------------------------------
// called automatically when the panel is shown for the first time or
// when the panel is resized
// You have to call OnPaint with Refresh() when you need to update the panel content
{
	// read the control values
	MyFrame* frame =  (MyFrame*)GetParent() ;
	MyControlPanel* panel = (MyControlPanel*)GetParent() ;
	int radius = frame->GetControlPanel()->GetSliderValue() ;
	bool check = frame->GetControlPanel()->GetCheckBoxValue() ;

	// then paint
	wxPaintDC dc(this);	

	//dc.setPen(wxNullPen);
	//dc.setPen(wxPen(wxcolour(RED),epaisseur));
	//dc.DrawLine(m_mousePoint, m_onePoint) ;
/*
	if( ==1){
		dc.DrawLine(m_listclicks[0], m_listclicks[1]);
	}
	if( ==2){
		dc.DrawCircle(m_listclicks[0],radius/2);
	}*/
	//if(frame->Id_Bouton == 1){dc.DrawLine(m_mousePoint, m_onePoint) ;}
	if(panel->Id_Bouton == 1){dc.DrawLine(*m_listclicks[0], *m_listclicks[1]) ;}

	dc.DrawRectangle(wxPoint(m_onePoint.x-radius/2, m_onePoint.y-radius/2), wxSize(radius,radius)) ;
	dc.DrawCircle(wxPoint(m_mousePoint), radius/2) ;

	
	if (check)
	{
		wxString coordinates ;
		coordinates.sprintf(wxT("(%d,%d)"), m_mousePoint.x, m_mousePoint.y) ;
		dc.DrawText(coordinates, wxPoint(m_mousePoint.x, m_mousePoint.y+20)) ;
	}
}

//------------------------------------------------------------------------
void MyDrawingPanel::OpenFile(wxString fileName)
//------------------------------------------------------------------------
{
	// just to open (and close) any file 
	FILE* f = fopen(fileName, "r") ;
	if (f)
	{
		wxMessageBox(wxT("The file was opened then closed")) ;
		fclose(f) ;
	}
}

//------------------------------------------------------------------------
void MyDrawingPanel::SaveFile(wxString fileName)
//------------------------------------------------------------------------
{
	// just to create a tiny file
	FILE* f = fopen(fileName, "w") ;
	if (!f)
		wxMessageBox(wxT("Cannot save file"));
	else
	{
		fprintf(f, "S1102 software can create and write a file") ;
		wxMessageBox(wxT("The file was saved")) ;
		fclose(f) ;
	}
}