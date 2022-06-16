#ifndef __LIGNE_H__
#define __LIGNE_H__

#include <string>

#include "Forme.h"
#include "Point.h"

#include <iostream>
#include <cstdlib>
#include <cmath> // pour sqrt

#include "Point.h"
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

using namespace std;

//-------------------------------------------
class Ligne : public Forme
//-------------------------------------------
{
public:                        // interface publique de la classe
    Ligne();
    Ligne(int m_x,int m_y, int m_a, int m_b);
    Ligne(wxPoint p1, wxPoint p2);
    ~Ligne();
    virtual void Draw() override;

private: 
    int m_x ; 
    int m_y ;
    int m_a ;
    int m_b ;
}

#endif 