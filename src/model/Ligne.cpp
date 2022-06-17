#include "ligne.h"
#include <iostream>
using namespace std;

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
Ligne::Ligne(int m_x,int m_y, int m_a, int m_b)
//-------------------------------------------
m_x(m_x),m_y(m_y),m_a(m_a),m_b(m_b);
{   
}

Ligne::Ligne(){}

Ligne::Ligne(wxPoint p1, wxPoint p2){}

void Ligne::Draw(wxPaintDC& dc){
    dc.DrawLine((x.GetX(),x.GetY()),(y.Getx(), y.GetY()));
}


