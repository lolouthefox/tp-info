// N. DITTHAVONG & L. CHENEVAL - 21/10/2025 - tissu.cpp
// Découpe un patron d'un tissu.

#include <iostream>
#include <cassert>
#include <string>

using namespace std;

// ----
// Enregistrements représentant un tissu et un patron
struct Tissu {
    string matiere;
    unsigned int largeur, hauteur;
};

struct Patron {
    string nom;
    unsigned int largeur, hauteur;
};

// ----
// Procédure qui fait une rotation d'un patron en inversant la hauteur et la largeur.
void tourne(Patron &p) {
    unsigned int tmp = p.largeur;
    p.largeur = p.hauteur;
    p.hauteur = tmp;
}

// ----
// Fonction qui renvoie vrai si le patron est plus petit que le tissu et faux sinon.
bool plus_petit(Patron p, Tissu t) {
    return p.largeur <= t.largeur and p.hauteur <= t.hauteur;
}

// ----
// Fonction qui renvoie vrai si l'on peut découper un patron dans un morceau de tissu.
// Tourne le patron si nécessaire.
bool peut_decouper(Patron &p, Tissu t) {
    bool res = plus_petit(p, t);
    if (not res) {
        tourne(p);
        res = plus_petit(p, t);
    }
    return res;
}

// ----
// Procédure qui découpe un patron sur un tissu.
void decoupe(Patron p, Tissu &t) {
    assert(t.largeur >= p.largeur);
    assert(t.hauteur >= p.hauteur);

    t.largeur = t.largeur - p.largeur;
}

// ----
// Fonction qui renvoie la taille en cm2 d'un tissu.
unsigned int surface(Tissu t) {
    return t.hauteur * t.largeur;
}

// ----
// Fonction qui découpe un patron sur un tissu et renvoie la chute mais ne modifie pas le tissu.
Tissu decoupe2(Patron p, Tissu t) {
    assert(t.largeur >= p.largeur);
    assert(t.hauteur >= p.hauteur);
    
    return {t.matiere, t.largeur - (t.largeur - p.largeur), t.hauteur};
}

// ----
// PROGRAMME PRINCIPAL
// Découpe une manche de 4x3cm dans un morceau de cotton de 7x5cm et donne à l'utilisateur le nombre de découpes nécessaire.
int main() {
    unsigned int nb_decoupes = 0;
    Tissu tissu = {"Cotton", 7, 5};
    Patron piece = {"Manche", 4, 3};

    while (peut_decouper(piece, tissu)) {
        decoupe(piece, tissu);
        nb_decoupes++;
    }

    cout << "Patron : " << piece.nom << endl;
    cout << "Nombre de découpes : " << nb_decoupes << endl;
}

// ----
// JEUX DE TEST
//
// SORTIE PROGRAMME PRINCIPAL:
// Patron : Manche
// Nombre de découpes : 2
//
// TOURNE
// Patron manche <- ("Manche", 4, 3)
// tourne(manche) => manche = ("Manche", 3, 4)
//
// PLUS_PETIT
// plus_petit(("Manche", 4, 3), ("Cotton", 7, 5)) => true
//
// PEUT_DECOUPER
// Patron manche <- ("Manche", 4, 3)
// peut_decouper(manche, ("Cotton", 7, 5)) => renvoie: true; manche = ("Manche", 3, 4)
//
// DECOUPE
// Patron manche <- ("Manche", 4, 3)
// Tissu cotton <- ("Cotton", 7, 5)
// decoupe(manche, cotton) => tissu = ("Cotton", 3, 5)
//
// SURFACE
// Tissu cotton <- ("Cotton", 7, 5)
// surface(cotton) => 35
//
// DECOUPE2
// Patron manche <- ("Manche", 4, 3)
// Tissu cotton <- ("Cotton", 7, 5)
// decoupe2(manche, cotton) => tissu = ("Cotton", 4, 5)
// ----
