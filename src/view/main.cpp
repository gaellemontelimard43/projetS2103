#include "wx/wxprec.h"

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include<wx/filedlg.h>
#include <wx/image.h>
#include <wx/file.h>
#include <wx/bitmap.h>

#include "MyApp.hpp"
#include "MyControlPanel.hpp"
#include "MyDrawingPanel.hpp"
#include "MyFrame.hpp"

#define APPLICATION_WIDTH	600
#define APPLICATION_HEIGHT	500 
#define APP_NAME "M1102 Skeleton 1.0"

IMPLEMENT_APP(MyApp) // macro that contains the main() function

//------------------------------------------------------------------------
bool MyApp::OnInit()
//------------------------------------------------------------------------
{
	MyFrame *frame = new MyFrame(wxT(APP_NAME), wxDefaultPosition, wxSize(APPLICATION_WIDTH,APPLICATION_HEIGHT)) ;
	frame->Show(true) ;
	SetTopWindow(frame) ;
	return true ;
}