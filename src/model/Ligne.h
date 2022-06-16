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