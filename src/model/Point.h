#ifndef __POINT_H__
#define __POINT_H__

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

//-------------------------------------------
class Point
//-------------------------------------------
{
public:                        // interface publique de la classe
    Point();                   // constructeur par d�faut
    Point(int x, int y);       // constructeur
    Point(int z);     
    Point(wxPoint);         // constructeur (x = y)
    ~Point();                  // destructeur
    void Move(int dX, int dY); // bouge le point

    // Setters
    void SetX(int x);
    void SetY(int y);

    // Getters
    int GetX() const;
    int GetY() const;

    // M�thodes const (qui ne modifie pas l'objet)
    void Display() const;      // affiche les coordonn�es du point
    bool XEgalY() const;
    float Distance(const Point &p) const;
    float Distance(const Point *p) const;
    void Draw(wxPaintDC& dc);

    // M�thode statique
    static int GetPointCount(); // retourne le nombre de point

private:                        // invisible � l?utilisateur de la classe
    int m_x;                    // les coordonn�es
    int m_y;                    // du point

    // Attribut statique
    static int m_pointCount;    // donn�e commune � tous les objets
};

#endif // __POINT_H__ : retour � la ligne obligatoire pour certains compilateurs
