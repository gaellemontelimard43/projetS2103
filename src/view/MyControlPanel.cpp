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
	ID_COULEUR1,
	ID_COULEUR2,
	ID_COMBO1,
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
	Bind(wxEVT_BUTTON, &MyControlPanel::OnLigne, this, ID_LIGNE) ;

	y += WIDGET_Y0 ;
	m_button = new wxButton(this, ID_CERCLE, wxT("cercle"), wxPoint(10, y)) ;
	Bind(wxEVT_BUTTON, &MyControlPanel::OnCercle, this, ID_CERCLE) ;

	y += WIDGET_Y0 ;
	m_button = new wxButton(this, ID_TRIANGLE, wxT("triangle"), wxPoint(10, y)) ;
	Bind(wxEVT_BUTTON, &MyControlPanel::OnTriangle, this, ID_TRIANGLE) ;

	y += WIDGET_Y0 ;
	m_button = new wxButton(this, ID_RECTANGLE, wxT("rectanle"), wxPoint(10, y)) ;
	Bind(wxEVT_BUTTON, &MyControlPanel::OnRectangle, this, ID_RECTANGLE) ;
	
	y+= WIDGET_Y_STEP ;
	wxStaticText* text1 = new wxStaticText(this, wxID_ANY, wxT("Radius"), wxPoint(10, y)) ;
	
	y+= 15 ;
	m_slider = new wxSlider(this, ID_RADIUS, 10, 2, 100, wxPoint(10, y), wxSize(100,20)) ;
	Bind(wxEVT_SCROLL_THUMBTRACK, &MyControlPanel::OnSlider, this, ID_RADIUS) ;

	y+= WIDGET_Y_STEP ;
	wxStaticText* text2 = new wxStaticText(this, wxID_ANY, wxT("épaisseur trait"), wxPoint(10, y)) ;
	
	y+= 15 ;
	m_slider = new wxSlider(this, ID_EPAISSEUR, 10, 2, 100, wxPoint(10, y), wxSize(100,20)) ;
	Bind(wxEVT_SCROLL_THUMBTRACK, &MyControlPanel::OnSlider, this, ID_EPAISSEUR) ;
	
	y+= WIDGET_Y_STEP ;
	m_checkBox = new wxCheckBox(this, ID_COORDONNEES, "Show (x,y)", wxPoint(10, y), wxSize(100,20)) ;
	Bind(wxEVT_CHECKBOX, &MyControlPanel::OnCoordonnees, this, ID_COORDONNEES) ;	

	y+= WIDGET_Y_STEP ;
	m_radioButton = new wxRadioButton(this, ID_COULEUR1, "V1", wxPoint(10, y), wxSize(100,20),0,wxDefaultValidator) ;
	Bind(wxEVT_RADIOBUTTON, &MyControlPanel::OnCouleur, this, ID_COULEUR1) ;
	//y+= WIDGET_Y_STEP ;
	m_radioButton2 = new wxRadioButton(this, ID_COULEUR2, "V2", wxPoint(60, y), wxSize(100,20),0,wxDefaultValidator) ;
	Bind(wxEVT_RADIOBUTTON, &MyControlPanel::OnCouleur, this, ID_COULEUR2) ;

	//m_arrItems.Add( wxT("line") );
	//m_arrItems.Add( wxT("rectangle") );
	//m_arrItems.Add( wxT("triangle") );

	//y+= WIDGET_Y_STEP ;
	//m_comboBox = new wxComboBox(this, ID_COMBO1, "forme", wxPoint(10, y), wxSize(100,20),3,m_arrItems,0,wxDefaultValidator,"comboBox");
	//Bind(wxEVT_COMBOBOX, &MyControlPanel::OnComboBox, this, ID_COMBO1) ;
}

//------------------------------------------------------------------------
void MyControlPanel::OnLigne(wxCommandEvent &event)
//------------------------------------------------------------------------
{
	MyFrame* frame = (MyFrame*)GetParent() ;
	frame->ControleurBouton(ID_LIGNE);
	wxMessageBox(wxT("clique deux fois pour avoir une ligne!")) ;
	
}


//------------------------------------------------------------------------
void MyControlPanel::OnCercle(wxCommandEvent &event)
//------------------------------------------------------------------------
{
	MyFrame* frame = (MyFrame*)GetParent() ;
	frame->ControleurBouton(ID_CERCLE);
	wxMessageBox(wxT("clique deux fois pour avoir un cercle !")) ;
}

//------------------------------------------------------------------------
void MyControlPanel::OnTriangle(wxCommandEvent &event)
//------------------------------------------------------------------------
{
	MyFrame* frame = (MyFrame*)GetParent() ;
	frame->ControleurBouton(ID_TRIANGLE);
	wxMessageBox(wxT("clique trois fois pour avoir un triangle !")) ;
}

//------------------------------------------------------------------------
void MyControlPanel::OnRectangle(wxCommandEvent &event)
//------------------------------------------------------------------------
{
	MyFrame* frame = (MyFrame*)GetParent() ;
	frame->ControleurBouton(ID_RECTANGLE);
	
	wxMessageBox(wxT("clique quatre fois pour avoir un rectangle !")) ;
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

void MyControlPanel::OnComboBox(wxCommandEvent &event){
	
	MyFrame* frame = (MyFrame*)GetParent() ;

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