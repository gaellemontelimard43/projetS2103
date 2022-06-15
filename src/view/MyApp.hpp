
#ifndef __MyApp_HPP__
#define __MyApp_HPP__

#include "wx/wxprec.h"

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include<wx/filedlg.h>
#include <wx/image.h>
#include <wx/file.h>
#include <wx/bitmap.h>

//------------------------------------------------------------------------


//------------------------------------------------------------------------
class MyApp: public wxApp
//------------------------------------------------------------------------
{
    virtual bool OnInit() ;
};


#endif
