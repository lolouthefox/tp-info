// L. CHENEVAL - Oct. 2025 - License MIT
// Permet à un utilisateur de calculer la factorielle d'un nombre.

#include <iostream>
#include <cassert>
using namespace std;

// Calcule la factorielle d'un nombre x et retourne le résultat.
void fact(int &x) {
	assert(x > 0);
	if (x <= 1) {
		x = 1;
		return;
	}
	int y = x;
	x -= 1;
	fact(x);
	x = (x * y);
}

// Demande à l'utilisateur le nombre a mettre en factorielle.
int main() {
	int x = 0;
	cout << "Fact: ";
	cin >> x;
	fact(x);
	cout << "> " << x << endl;
}

