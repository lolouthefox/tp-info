// Sept. 2025 - L. CHENEVAL - License MIT
// Créer une matrice d'identité de taile n.

#include <iostream>
using namespace std;

int main() {
	int size;
	cout << "Entrer la taille de la matrice: ";
	cin >> size;

	for (int y = 0; y < size; y++) {
		for (int x = 0; x < size; x++) {
			if (x == y) {
				cout << " 1";
			} else {
				cout << " 0";
			}
		}
		cout << endl;
	}
}
