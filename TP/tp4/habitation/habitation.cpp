/* habitation.cpp
 * transcription de l'algorithme A de l'exercice 5.2 du sujet de TD 3
 */

#include <iostream> // pour cout, cin, endl
#include <string> // pour le type string

using namespace std;

//----------------------------------------------------------
// transcription de l'enregistrement définissant une habitation
struct Habitation {
    unsigned int num; // numéros > 0
    string comp, rue;
};

//----------------------------------------------------------
// procédure d'affichage d'une habitation h passée en entrée
void aff_hab( Habitation h )
{
    cout << h.num << " " << h.comp << " " << h.rue << endl;
}

//----------------------------------------------------------
// transcription de l'algorithme du sujet de TD
int main()
{
    Habitation hab;
    aff_hab(hab);
    hab = { 3 , "" , "Orrion" };
    aff_hab(hab);
    hab.comp = "bis";
    aff_hab(hab);
    hab.rue = "Henry "+hab.rue;
    aff_hab(hab);
}
