#include "wx/wxprec.h"

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include<wx/filedlg.h>
#include <wx/image.h>
#include <wx/file.h>
#include <wx/bitmap.h>
#include <iostream>
#include "Dessin.h"


using namespace std;



//------------------------------------------------------------------------
Dessin::Dessin(){
//------------------------------------------------------------------------


}

Dessin::~Dessin(){

}

void Dessin::ajouterforme(Forme* forme){
  this->dessin.push_back(forme);
}

vector<Forme*> Dessin::getVector(){
  return dessin; Dessin();
}

void Dessin::drawAll(wxPaintDC& dc)
{
      for (size_t i = 0 ; i < dessin.size(); i++) {
        dessin[i]->Draw(dc);
    }
}
//m_dessin.drawAll(wxPaintDC& dc); //boucle sur toutes les formes pour se dessiner