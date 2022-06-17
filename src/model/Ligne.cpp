#include "Ligne.h"
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
Ligne::Ligne(int m_x,int m_y, int m_a, int m_b):
//-------------------------------------------
m_x(m_x),m_y(m_y),m_a(m_a),m_b(m_b)
{   

}

Ligne::~Ligne(){
    
}


Ligne::Ligne(){}

Ligne::Ligne(Point x, Point y) :
    x(x),
    y(y)

{

}



void Ligne::Draw(wxPaintDC& dc){
    dc.DrawLine(m_x,m_y,m_a, m_b);
}


