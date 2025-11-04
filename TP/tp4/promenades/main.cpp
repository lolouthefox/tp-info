// L. CHENEVAL - Oct. 2025 - promenades/main.cpp
// Faire le parcour d'un tableau de N élément en suivant la valeur de i.

#include <iostream>
#include <string>
#include <cassert>
using namespace std;

const unsigned int N = 100;

int main() {
    string reponse;
    unsigned int n;

    cout << "Taille tableau: ";
    cin >> n;

    assert(n < N);

    unsigned int t[N];
    
    for (unsigned int i = 1; i <= n; i++) {
        t[i] = i;
    }

    unsigned int i;
    cout << "Départ: ";
    cin >> i;

    unsigned int j;
    cout << "Arrivé: ";
    cin >> j;

    for (unsigned int i = i; i <= j; i++) {
        cout << i;
    }
}
