// L. CHENEVAL - Oct. 2025 - parite/main.cpp
// Tester la parité d'un tableau.

#include <iostream>
#include <string>
#include <cassert>
using namespace std;

// ---
// Indique si un nombre est paire.
bool est_paire(int nb) {
    return nb % 2 == 0;
}

// ---
// Indique si un tableau est paritaire (qu'il y a le même nombre d'éléments paire et impaire).
bool parite(int tab[], int size) {
    int paires = 0;
    int impaires = 0;
    
    for (int i = 0; i < size; i++) {
        if (est_paire(tab[i])) {
            paires++;
        } else {
            impaires++;
        }
    }

    return paires == impaires;
}

// ---
// Swaps two values together in a table.
void swap(int tab[], int a, int b) {
    int temp = tab[a];
    tab[a] = tab[b];
    tab[b] = temp;
}

// ---
// Réorganise un tableau paritaire pour que les valeurs paires soient sur des indices paires.
void reorganise(int tab[], int size) {
    for (int i = 0; i < size; i++) {
        bool indice_paire = est_paire(i);
        bool val_paire = est_paire(tab[i]);
        if (indice_paire != val_paire) {
            for (int j = i; j < size; j++) {
                if (est_paire(tab[j]) == indice_paire) {
                    swap(tab, i, j);
                    break;
                }
            }
        }
    }
}

// ---
// Programme principal, test deux tableau. 1 pour paritaire et 0 sinon.
int main() {
    int tab1[5] = {1, 2, 3, 4, 5};
    int tab2[6] = {1, 3, 4, 2, 5, 6};
    cout << parite(tab1, 5) << endl;
    cout << parite(tab2, 6) << endl;

    reorganise(tab2, 6);
    for (int i = 0; i < 6; i++) {
        cout << "- " << tab2[i] << endl;
    }
}
