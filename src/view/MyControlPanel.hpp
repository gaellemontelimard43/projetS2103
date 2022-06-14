
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

private:
	void OnButton1(wxCommandEvent &event) ;
	void OnButton2(wxCommandEvent &event) ;
	void OnButton3(wxCommandEvent &event) ;
	void OnButton4(wxCommandEvent &event) ;
	void OnSlider(wxScrollEvent &event) ;
	void OnCheckBox(wxCommandEvent &event) ;
	void OnRadioButton(wxCommandEvent &event) ;
	void OnComboBox(wxCommandEvent &event) ;
	wxButton* m_button ;
	wxSlider* m_slider ;
	wxCheckBox* m_checkBox ;
	wxRadioButton* m_radioButton;
	wxRadioButton* m_radioButton2;
	//wxComboBox* m_comboBox ;
	//wxArrayString* m_arrItems ;

};
#endif