
#ifndef __MyControlPanel_HPP__
#define __MyControlPanel_HPP__

#include "wx/wxprec.h"

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include<wx/filedlg.h>
#include <wx/image.h>
#include <wx/file.h>
#include <wx/bitmap.h>
#include <iostream>
#include <string>



//------------------------------------------------------------------------
class MyControlPanel: public wxPanel
//------------------------------------------------------------------------
{
public:
	MyControlPanel( wxWindow *parent ) ;
	int GetSliderValue() {return m_slider->GetValue() ;} ;
	bool GetCheckBoxValue() {return m_checkBox->GetValue() ;} ;
	const char* forme[4] = {"Ligne", "Rectangle", "Carré", "Cercle"};
	int Id_Bouton = 0 ;

private:
	void OnBoutonLigne(wxCommandEvent &event) ;
	void OnBoutonCercle(wxCommandEvent &event) ;
	void OnBoutonTriangle(wxCommandEvent &event) ;
	void OnBoutonRectangle(wxCommandEvent &event) ;
	void OnSlider(wxScrollEvent &event) ;
	void OnCoordonnees(wxCommandEvent &event) ;
	void OnCouleur(wxCommandEvent &event) ;
	void OnComboBox(wxCommandEvent &event) ;
	wxButton* m_button ;
	wxSlider* m_slider ;
	wxCheckBox* m_checkBox ;
	wxRadioButton* m_radioButton;
	wxRadioButton* m_radioButton2;
	wxComboBox* m_comboBox ;
	wxArrayString* m_arrItems ;

};
#endif