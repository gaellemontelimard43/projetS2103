#ifndef __LIGNE_H__
#define __LIGNE_H__

#include <string>

#include "Forme.h"
#include "Point.h"



//-------------------------------------------
class Ligne : public Forme
//-------------------------------------------
{
public:                        // interface publique de la classe
    Ligne();
    Ligne(int m_x,int m_y, int m_a, int m_b);
    Ligne(Point x, Point y);
    virtual ~Ligne();
    virtual void Draw(wxPaintDC& dc);

private: 
    Point x;
    Point y;
    int m_x;
    int m_y;
    int m_a;
    int m_b;
};

#endif 