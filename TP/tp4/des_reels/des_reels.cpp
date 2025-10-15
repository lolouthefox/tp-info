/* des_reels.cpp
 * Rôle : transcription de l'algorithme des_reels de l'exercice 6.1 du sujet de TD
 */
#include <iostream> // pour cin, cout et endl
using namespace std;

//----------------------------------------------------------
// Définition du type T3Reels
const size_t CAPA = 3;
using T3Reels = double [CAPA]; // choix du type double pour éviter un warning

//----------------------------------------------------------
// procédure d'affichage d'un T3Reels, correspondant à la question 6.1.2
void afficher( const T3Reels & trois_reels, char sep )
{
    for ( double val : trois_reels )
    {
        cout << val << sep;
    }
    cout << endl;
}

//----------------------------------------------------------
// transcription de l'algorithme du sujet de TD
int main()
{
    // variables
    T3Reels t3r;
    size_t indi; // choix du type size_t approprié aux indices

    //début
    afficher(t3r,' '); // affichage avant toute opération
    t3r[1] = 9.9;
    t3r[2] = t3r[1] + 1.1;
    afficher(t3r,' '); // affichage après deux affectations
    indi = 2;
    t3r[indi-1] = 7.5;
    t3r[indi-2] = 5.6;
    afficher(t3r,' '); // affichage après deux autres affectations
    for( indi=2 ; indi<=3 ; indi++) {
        t3r[indi-1] = t3r[indi-2]*2;
    }
    afficher(t3r,' '); // affichage de l'état final
    //fin
}