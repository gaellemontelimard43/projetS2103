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
#include <Dessin.h>

using namespace std;

void Dessin::drawAll(wxPaintDC& dc){
      for (size_t i = 0 ; i < m_dessin.size(); i++) {
        m_dessin[i].Draw(dc);
    }
}

m_dessin.drawAll(wxPaintDC& dc); //boucle sur toutes les formes pour se dessiner