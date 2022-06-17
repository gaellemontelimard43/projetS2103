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
#include "../model/Forme.h"
#include "../model/Cercle.h"
#include "../model/Ligne.h"
#include "../model/Rectangle.h"
#include "../model/Dessin.h"

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
	dessin = Dessin();
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
	MyControlPanel* control = frame->m_controlPanel ;
	m_onePoint.x = event.m_x ;
	m_onePoint.y = event.m_y ;
	//Refresh() ; // send an event that calls the OnPaint method


	switch(control->Id_Bouton){
		case 1: 
			if(m_ClickNumber == 0){
				frame-> Miseazero();
				frame->ControleurClick(m_ClickNumber,m_onePoint.x,m_onePoint.y);
				m_ClickNumber ++ ;
			}else{
				frame->ControleurClick(m_ClickNumber,m_onePoint.x,m_onePoint.y);
				dessin.ajouterforme(new Ligne(m_listclicks[0].x,m_listclicks[0].y,m_listclicks[1].x,m_listclicks[1].y));
				m_ClickNumber = 0 ;
			}
		break;

		case 2:
			if(m_ClickNumber == 0){
				frame-> Miseazero() ;
				frame->ControleurClick(m_ClickNumber,m_onePoint.x,m_onePoint.y);
				m_ClickNumber ++ ;
			}else{
				frame->ControleurClick(m_ClickNumber,m_onePoint.x,m_onePoint.y);
				
				dessin.ajouterforme(new Cercle(m_listclicks[0], sqrt((pow(m_listclicks[1].x-m_listclicks[0].x,2))+pow(m_listclicks[1].y-m_listclicks[0].y,2)), "Cercle"));
				m_ClickNumber = 0 ;
			}

		break;

		case 3:
			if(m_ClickNumber == 0){
				frame->ControleurClick(m_ClickNumber,m_onePoint.x,m_onePoint.y);
				m_ClickNumber ++ ;
			}else if (m_ClickNumber = 1){
				frame->ControleurClick(m_ClickNumber,m_onePoint.x,m_onePoint.y);
				m_ClickNumber ++ ;
			}else {

				frame->ControleurClick(m_ClickNumber,m_onePoint.x,m_onePoint.y);
				//new Triangle(m_listclicks[0], sqrt((pow(m_listclicks[1].x-m_listclicks[0].x,2))+pow(m_listclicks[1].y-m_listclicks[0].y,2)));
				m_ClickNumber = 0 ;
			}

		break;

		case 4:
			if(m_ClickNumber == 0){
				frame-> Miseazero() ;
				frame->ControleurClick(m_ClickNumber,m_onePoint.x,m_onePoint.y);
				m_ClickNumber ++ ;
			}else{
				frame->ControleurClick(m_ClickNumber,m_onePoint.x,m_onePoint.y);
				dessin.ajouterforme(new Rectangle(m_listclicks[0].x, m_listclicks[0].y, (m_listclicks[1].x-m_listclicks[0].x),(m_listclicks[1].y-m_listclicks[0].y),"rectangle"));
				m_ClickNumber = 0 ;
			}
		break;
	}
	Refresh() ;
}

//------------------------------------------------------------------------
void MyDrawingPanel::OnPaint(wxPaintEvent &event)
//------------------------------------------------------------------------
// called automatically when the panel is shown for the first time or
// when the panel is resized
// You have to call OnPaint with Refresh() when you need to update the panel content
{
	std::cerr << "Rentrons dans paint" << std::endl ;
	// read the control values
	MyFrame* frame =  (MyFrame*)GetParent() ;
	MyControlPanel* control = frame->m_controlPanel ;
	int radius = m_listclicks[0].x + m_listclicks[1].x ;
	bool check = frame->GetControlPanel()->GetCheckBoxValue() ;

	// then paint
	wxPaintDC dc(this);	

	//dc.setPen(wxNullPen);
	//dc.setPen(wxPen(wxcolour(RED),epaisseur));
	//dc.DrawLine(m_mousePoint, m_onePoint) ;
	//il faut l'initaialiser dans toute les classe 

	dessin.drawAll(dc);

	if(m_listclicks[1].x == 0){}
	else if(control->Id_Bouton == 1){dc.DrawLine(m_listclicks[0], m_listclicks[1]) ;} //check si valeur OKAY 
	else if(control->Id_Bouton == 2){dc.DrawCircle(m_listclicks[0], sqrt((pow(m_listclicks[1].x-m_listclicks[0].x,2))+pow(m_listclicks[1].y-m_listclicks[0].y,2)));}
	else if(control->Id_Bouton == 4){dc.DrawRectangle(wxPoint(m_listclicks[0].x, m_listclicks[0].y), wxSize((m_listclicks[1].x-m_listclicks[0].x),(m_listclicks[1].y-m_listclicks[0].y))) ;}

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