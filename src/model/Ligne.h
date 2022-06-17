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
    Ligne(Point x, Point y);
    ~Ligne();
    void Draw(wxPaintDC& dc);

private: 
    Point x;
    Point y;
};

#endif 