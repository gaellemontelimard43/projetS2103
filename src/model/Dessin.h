#ifndef __DESSIN_H__
#define __DESSIN_H__


#include "wx/wxprec.h"
#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif
#include<wx/filedlg.h>
#include <wx/image.h>
#include <wx/file.h>
#include <wx/bitmap.h>
#include <iostream>
#include <vector>
#include <Forme.h>

using namespace std;

class Dessin 
{
    public:
        void drawAll(wxPaintDC& dc);

    private:
         vector<Forme*>m_dessin;
}

#endif


