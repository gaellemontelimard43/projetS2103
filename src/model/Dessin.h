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
#include "Forme.h"

using namespace std;

class Dessin 
{
    public:
        Dessin(); //constructeur et destructeur
       ~Dessin();
        void drawAll(wxPaintDC& dc);
        void ajouterforme(Forme* forme);
        vector<Forme*> getVector();

    private:
         vector<Forme*>dessin;
};

#endif


