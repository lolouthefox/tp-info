// L. CHENEVAL - Oct. 2025 - License MIT
// Permet à un utilisateur de scinder des chaînes de caractère eb 3 parties à des positions choisis

#include <iostream>
#include <cassert>

using namespace std;

// Scinde une chaîne de caractères en 3 parties en utilisant g et d comme incide du caractère à découper.
void scinder(string chaine, int g, int d, string &ch_g, string &ch_c, string &ch_d) {
	// Récuperer les caractères de gauche
	for (int i = 0; i < g; i++) {
		ch_g = ch_g + chaine[i];
	}

	// Récuperer les caractères du centre
	for (int j = g; j <= d - 1; j++) {
		ch_c = ch_c + chaine[j];
	}

	// Récuperer les caractères de droite
	for (int k = d; k < static_cast<int>(chaine.length()) - 2; k++) {
		ch_d = ch_d + chaine[k];
	}
}

// Demande à l'utilisateur la chaîne à scinder et les positions des caractères.
int main() {
	// Init des variables
	string chaine, ch_g, ch_d, ch_c = "";
	int g, d = 0;

	// Demande la chaîne à découper à l'utilisateur
	cout << "Chaîne à modifier: ";
	getline(cin, chaine);
	assert(chaine != "");

	// Demander où découper la chaîne de caractère à gauche...
	cout << "Charactères à couper à gauche: ";
	cin >> g;
	assert(g > 0);

	/// ... puis à droite
	cout << "Charactères à couper à droite: ";
	cin >> d;
	assert(d > 0 && d > g);

	// Scinde la chaîne de caractères
	scinder(chaine, g, d, ch_g, ch_c, ch_d);

	// Afficher le résultat
	cout << "Résultat: " << endl << ch_g << endl << ch_c << endl << ch_d << endl;

	return 1;
}

