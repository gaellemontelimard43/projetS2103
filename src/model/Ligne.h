#ifndef __POINT_H__
#define __POINT_H__

#include <string>

#include "Forme.h"
#include "Point.h"

//-------------------------------------------
class Ligne : public Forme
//-------------------------------------------
{
public:                        // interface publique de la classe
    Ligne();
    Ligne(int m_x,int m_y, int a, int b);
    Ligne(const Point& p1,Point p2);

    

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

    // M�thode statique
    static int GetPointCount(); // retourne le nombre de point

private:   
    Point p1 ;                     // invisible � l?utilisateur de la classe
    int m_x;                    // les coordonn�es
    int m_y;                    // du point
};

#endif // __POINT_H__ : retour � la ligne obligatoire pour certains compilateurs