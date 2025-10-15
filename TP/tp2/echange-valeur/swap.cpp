/* L. CHENEVAL 25.09.2025
   Echange les valeurs de x et y.
*/

#include <iostream>
using namespace std;

int main() {
    // Valeurs initiales
    int x;
    int y;

    // Saisie de x et y par l'utilisateur
    cout << "Donner x: ";
    cin >> x;

    cout << "Donner y: ";
    cin >> y;

    // Echange les deux valeur
    x = y + x;
    y = x - y;
    x = x - y;

    // Affiche le résultat
    cout << "Valeur de x " << x << endl;
    cout << "Valeur de y " << y << endl;
}
