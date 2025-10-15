/* C.Jermann 2018.01.17 - C. Enguehard 2021.09.12
   Affiche la moyenne de notes saisies par l'utilisateur.
*/

/* TESTS REALISE:
3 notes: 10.25, 11.5, 12.75 --> moyenne = 11.5 (ok)
1 note: 15 --> moyenne = 15 (ok)
*/

#include <iostream>
using namespace std;

//-----------------------------------------------
// programme principal
int main()
{
    // variables
    int cpt, nb_notes;
    float note, somme;
    // début
    somme = 0;
    // Saisie du nombre de notes par l'utilisateur
    cout << "Nombre de notes: ";
    cin >> nb_notes;

    // saisie des 5 notes par l'utilisateur et addition
    for (cpt = 1 ; cpt <= nb_notes ; cpt++)
    {
        cout << "Note numero " << cpt << " : ";
        cin >> note;
        somme = somme + note; // cumul des notes
        // cout << "DEBUG : cpt = " << cpt << " somme = " << somme << endl;
    }
    // affichage de la moyenne
    cout << "La moyenne est de " << somme/static_cast<float>(nb_notes) << "/20" << endl;
    // fin
}
