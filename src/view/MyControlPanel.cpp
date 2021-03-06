#include "wx/wxprec.h"

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include<wx/filedlg.h>
#include <wx/image.h>
#include <wx/file.h>
#include <wx/bitmap.h>

#include "MyControlPanel.hpp"
#include "MyFrame.hpp"
#include "MyDrawingPanel.hpp"
#include "../model/Cercle.h"
#include "../model/Forme.h"
#include "../model/Rectangle.h"
#include "../model/Ligne.h"

#define WIDGET_PANEL_WIDTH	150
#define WIDGET_Y0			30
#define WIDGET_Y_STEP		50

enum
{
	ID_LIGNE = 1,
	ID_CERCLE,
	ID_TRIANGLE,
	ID_RECTANGLE,
	ID_RADIUS,
	ID_EPAISSEUR,
	ID_COORDONNEES,
	ID_COULEUR_CONTROLEUR1,
	ID_COULEUR_CONTROLEUR2,
	ID_COULEUR_FORME,
};


//------------------------------------------------------------------------
MyControlPanel::MyControlPanel(wxWindow *parent) : wxPanel(parent)
//------------------------------------------------------------------------
// In this constructor, create the controls and associate each of them (bind) a method
{
	int w, h, y ;
	GetParent()->GetSize(&w,&h) ;
	SetSize(wxRect(wxPoint(0,0), wxPoint(WIDGET_PANEL_WIDTH, h))) ;
	SetBackgroundColour(wxColor(229,175,52)) ;

	y = WIDGET_Y0 ;
	m_button = new wxButton(this,ID_LIGNE, wxT("ligne"), wxPoint(10, y)) ;
	Bind(wxEVT_BUTTON, &MyControlPanel::OnBoutonLigne, this, ID_LIGNE) ;

	y += WIDGET_Y0 ;
	m_button = new wxButton(this, ID_CERCLE, wxT("cercle"), wxPoint(10, y)) ;
	Bind(wxEVT_BUTTON, &MyControlPanel::OnBoutonCercle, this, ID_CERCLE) ;

	y += WIDGET_Y0 ;
	m_button = new wxButton(this, ID_TRIANGLE, wxT("triangle"), wxPoint(10, y)) ;
	Bind(wxEVT_BUTTON, &MyControlPanel::OnBoutonTriangle, this, ID_TRIANGLE) ;

	y += WIDGET_Y0 ;
	m_button = new wxButton(this, ID_RECTANGLE, wxT("rectanle"), wxPoint(10, y)) ;
	Bind(wxEVT_BUTTON, &MyControlPanel::OnBoutonRectangle, this, ID_RECTANGLE) ;
	
	y+= WIDGET_Y_STEP ;
	wxStaticText* text1 = new wxStaticText(this, wxID_ANY, wxT("Epaisseur du trait"), wxPoint(10, y)) ;
	
	y+= 15 ;
	m_slider = new wxSlider(this, ID_EPAISSEUR, 10, 2, 100, wxPoint(10, y), wxSize(100,20)) ;
	Bind(wxEVT_SCROLL_THUMBTRACK, &MyControlPanel::OnSlider, this, ID_EPAISSEUR) ;

	y+= WIDGET_Y_STEP ;
	wxStaticText* text2 = new wxStaticText(this, wxID_ANY, wxT("Radius"), wxPoint(10, y)) ;
	
	y+= 15 ;
	m_slider = new wxSlider(this, ID_RADIUS, 10, 2, 100, wxPoint(10, y), wxSize(100,20)) ;
	Bind(wxEVT_SCROLL_THUMBTRACK, &MyControlPanel::OnSlider, this, ID_RADIUS) ;
	
	y+= WIDGET_Y_STEP ;
	m_checkBox = new wxCheckBox(this, ID_COORDONNEES, "Show (x,y)", wxPoint(10, y), wxSize(100,20)) ;
	Bind(wxEVT_CHECKBOX, &MyControlPanel::OnCoordonnees, this, ID_COORDONNEES) ;	

	y+= WIDGET_Y_STEP ;
	m_radioButton = new wxRadioButton(this, ID_COULEUR_CONTROLEUR1, "Standard", wxPoint(10, y), wxSize(100,20),0,wxDefaultValidator) ;
	Bind(wxEVT_RADIOBUTTON, &MyControlPanel::OnCouleur, this, ID_COULEUR_CONTROLEUR1) ;

	m_radioButton2 = new wxRadioButton(this, ID_COULEUR_CONTROLEUR2, "Eco", wxPoint(92, y), wxSize(100,20),0,wxDefaultValidator) ;
	Bind(wxEVT_RADIOBUTTON, &MyControlPanel::OnCouleur, this, ID_COULEUR_CONTROLEUR2) ;

	y+= WIDGET_Y_STEP ;
	m_comboBox = new wxComboBox(this, ID_COULEUR_FORME, "Couleurs", wxPoint(10, y), wxSize(100,20),0,NULL,0,wxDefaultValidator,"comboBox");
	Bind(wxEVT_COMBOBOX, &MyControlPanel::OnComboBox, this, ID_COULEUR_FORME) ;
}

//------------------------------------------------------------------------
void MyControlPanel::OnBoutonLigne(wxCommandEvent &event) //boutonLigne
//------------------------------------------------------------------------
{
	MyFrame* frame = (MyFrame*)GetParent() ;
	MyDrawingPanel* drawing = frame->m_drawingPanel ;
	Id_Bouton = 1 ;
	drawing->m_ClickNumber = 0 ;
	wxMessageBox(wxT("Cliquez deux fois pour avoir une ligne!")) ;
}


//------------------------------------------------------------------------
void MyControlPanel::OnBoutonCercle(wxCommandEvent &event)
//------------------------------------------------------------------------
{
	MyFrame* frame = (MyFrame*)GetParent();
	Id_Bouton = 2 ;
	wxMessageBox(wxT("Cliquez deux fois pour avoir un cercle !")) ;
	frame->RefreshDrawing() ;	// update the drawing panel
}

//------------------------------------------------------------------------
void MyControlPanel::OnBoutonTriangle(wxCommandEvent &event)
//------------------------------------------------------------------------
{
	MyFrame* frame = (MyFrame*)GetParent() ;
	Id_Bouton = 3 ;
	wxMessageBox(wxT("Cliquez trois fois pour avoir un triangle !")) ;
	frame->RefreshDrawing() ;	// update the drawing panel
}

//------------------------------------------------------------------------
void MyControlPanel::OnBoutonRectangle(wxCommandEvent &event)
//------------------------------------------------------------------------
{
	MyFrame* frame = (MyFrame*)GetParent() ;
	Id_Bouton = 4 ;
	wxMessageBox(wxT("Cliquez deux fois pour avoir un rectangle !")) ;
	frame->RefreshDrawing() ;	// update the drawing panel
}

//------------------------------------------------------------------------
void MyControlPanel::OnCouleur(wxCommandEvent &event)
//------------------------------------------------------------------------
{
	MyFrame* frame = (MyFrame*)GetParent() ;
	MyDrawingPanel* panel = (MyDrawingPanel*)GetParent() ;

	if(m_radioButton->GetValue() == true){
	SetBackgroundColour(wxColor(229,175,52)) ;
	}
	else{
		SetBackgroundColour(wxColor(106,196,86)) ;
		panel->SetBackgroundColour(*wxGREEN);
		frame->RefreshDrawing();
	}
}

//------------------------------------------------------------------------
void MyControlPanel::OnComboBox(wxCommandEvent &event)
//------------------------------------------------------------------------
{
	
	MyFrame* frame = (MyFrame*)GetParent() ;
	frame->RefreshDrawing() ;	// update the drawing panel
}

//------------------------------------------------------------------------
void MyControlPanel::OnSlider(wxScrollEvent &event)
//------------------------------------------------------------------------
{
	MyFrame* frame = (MyFrame*)GetParent() ;
	frame->RefreshDrawing() ;	// update the drawing panel
}

//------------------------------------------------------------------------
void MyControlPanel::OnCoordonnees(wxCommandEvent &event)
//------------------------------------------------------------------------
{
	MyFrame* frame = (MyFrame*)GetParent() ;
	frame->RefreshDrawing() ;	// update the drawing panel
}