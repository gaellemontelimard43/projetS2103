
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



//------------------------------------------------------------------------
class MyControlPanel: public wxPanel
//------------------------------------------------------------------------
{
public:
	MyControlPanel( wxWindow *parent ) ;
	int GetSliderValue() {return m_slider->GetValue() ;} ;
	bool GetCheckBoxValue() {return m_checkBox->GetValue() ;} ;

private:
	void OnButton(wxCommandEvent &event) ;
	void OnSlider(wxScrollEvent &event) ;
	void OnCheckBox(wxCommandEvent &event) ;
	void OnRadioButton(wxCommandEvent &event) ;
	wxButton* m_button ;
	wxSlider* m_slider ;
	wxCheckBox* m_checkBox ;
	wxRadioButton* m_radioButton;
	wxRadioButton* m_radioButton2;
};
#endif