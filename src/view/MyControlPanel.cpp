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

#define WIDGET_PANEL_WIDTH	150
#define WIDGET_Y0			30
#define WIDGET_Y_STEP		50

enum
{
	ID_BUTTON1,
	ID_SLIDER1,
	ID_SLIDER2,
	ID_CHECKBOX1,
	ID_RADIO1,
	ID_RADIO2,
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
	m_button = new wxButton(this, ID_BUTTON1, wxT("Click me"), wxPoint(10, y)) ;
	Bind(wxEVT_BUTTON, &MyControlPanel::OnButton, this, ID_BUTTON1) ;
	
	y+= WIDGET_Y_STEP ;
	wxStaticText* text1 = new wxStaticText(this, wxID_ANY, wxT("Radius"), wxPoint(10, y)) ;
	
	y+= 15 ;
	m_slider = new wxSlider(this, ID_SLIDER1, 10, 2, 100, wxPoint(10, y), wxSize(100,20)) ;
	Bind(wxEVT_SCROLL_THUMBTRACK, &MyControlPanel::OnSlider, this, ID_SLIDER1) ;

	y+= WIDGET_Y_STEP ;
	wxStaticText* text2 = new wxStaticText(this, wxID_ANY, wxT("épaisseur trait"), wxPoint(10, y)) ;
	
	y+= 15 ;
	m_slider = new wxSlider(this, ID_SLIDER2, 10, 2, 100, wxPoint(10, y), wxSize(100,20)) ;
	Bind(wxEVT_SCROLL_THUMBTRACK, &MyControlPanel::OnSlider, this, ID_SLIDER2) ;
	
	y+= WIDGET_Y_STEP ;
	m_checkBox = new wxCheckBox(this, ID_CHECKBOX1, "Show (x,y)", wxPoint(10, y), wxSize(100,20)) ;
	Bind(wxEVT_CHECKBOX, &MyControlPanel::OnCheckBox, this, ID_CHECKBOX1) ;	

	y+= WIDGET_Y_STEP ;
	m_radioButton = new wxRadioButton(this, ID_RADIO1, "V1", wxPoint(10, y), wxSize(100,20),0,wxDefaultValidator) ;
	Bind(wxEVT_RADIOBUTTON, &MyControlPanel::OnRadioButton, this, ID_RADIO1) ;
	//y+= WIDGET_Y_STEP ;
	m_radioButton2 = new wxRadioButton(this, ID_RADIO2, "V2", wxPoint(60, y), wxSize(100,20),0,wxDefaultValidator) ;
	Bind(wxEVT_RADIOBUTTON, &MyControlPanel::OnRadioButton, this, ID_RADIO2) ;

	m_arrItems.Add( wxT("line") );
	m_arrItems.Add( wxT("rectangle") );
	m_arrItems.Add( wxT("triangle") );

	y+= WIDGET_Y_STEP ;
	m_comboBox = new wxComboBox(this, ID_COMBO1, "forme", wxPoint(10, y), wxSize(100,20),m_arrItems,0,wxDefaultValidator,_T("ID_COMBO1") );
	Bind(wxEVT_COMBOBOX, &MyControlPanel::OnComboBox, this, ID_COMBO1) ;
}

//------------------------------------------------------------------------
void MyControlPanel::OnButton(wxCommandEvent &event)
//------------------------------------------------------------------------
{
//	char* s = GetCString() ;
//	wxMessageBox(wxString::FromAscii(s)) ; // call a C function located in the sample.cp module
//	free(s) ;
	wxMessageBox(wxT("You just pressed the button!")) ;
}

void MyControlPanel::OnRadioButton(wxCommandEvent &event){
	
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
void MyControlPanel::OnCheckBox(wxCommandEvent &event)
//------------------------------------------------------------------------
{
	MyFrame* frame = (MyFrame*)GetParent() ;
	frame->RefreshDrawing() ;	// update the drawing panel
}
