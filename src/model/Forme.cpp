#include <iostream>
#include "Forme.h"

using namespace std;

Forme::Forme()
{
    cout << "Forme (defaut)" << endl;
    // On alloue dynamiquement un label avec une chaine vide
    m_label = new string;
}

Forme::Forme(const std::string& label)
{
    cout << "Forme (avec un label)" << endl;
    // On alloue dynamiquement un label avec une chaine vide
    m_label = new string(label);
}

Forme::Forme(const Forme& other)
{
    cout << "Forme (avec un label)" << endl;
    // On alloue dynamiquement une copie du label de other
    m_label = new string(*(other.m_label));
}

// virtual
Forme::~Forme()
{
    cout << "~Forme" << endl;
    // Dans les derni�res versions de C++, il n'est plus obligatoire de tester si le pointeur
    // vaut nullptr (�quivalent � NULL depuis C++11) avant d'appeler delete. Si ce pointeur
    // est nullptr, alors il ne se passe rien. De plus, dans le code �crit ici, il n'y a
    // jamais de cas o� m_label vaut nullptr (le constructeur par d�faut alloue une string)
    delete m_label; 
}

Forme& Forme::operator=(const Forme& other)
{
    // La Forme ne contient qu'un attribut, le label, on peut utiliser SetLabel
    SetLabel(*(other.m_label));

    // On renvoit une r�f�rence sur l'objet courant
    return *(this);
}

// #define VERSION_ALTERNATIVE // Pour activer la version alternative du code, d�commenter cette ligne

void Forme::SetLabel(const std::string& label)
{
#ifdef VERSION_ALTERNATIVE
    // Version alternative
    // On r�alise une affectation des std::string (std::string.operator= de fait)
    // C'est plus simple que ce qui est demand� dans le TP et �a fonctionne car nous avons
    // *une seule* std::string. Si on g�rait un tableau de strings (new std::string[XXX]),
    // �� ne fonctionnerait pas
    *m_label = label;
#else
    // Version demand�e
    // On lib�re la pr�c�dente std::string
    delete m_label;
    // On alloue une nouvelle copie de la chaine
    m_label = new string(label);
#endif
}

std::string Forme::GetLabel() const
{
    // On renvoie une copie de la chaine
    return *(m_label);
}

Forme::virtual void Draw(){}

