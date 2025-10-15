// L. CHENEVAL - Oct. 2025 - License MIT
// Inverse une chaîne passé en argument du programme.

#include <iostream>
#include <cassert>

using namespace std;


// Inverse une chaîne de caractère passé en argument.
void inversement(string &chaine) {
	string n_chaine = "";
	for (int i = static_cast<int>(chaine.length()) - 1; i >= 0; i = i - 1) {
		n_chaine = n_chaine + chaine.at(i);
	}
	chaine = n_chaine;
}

// Affiche la chaîne inversé.
int main(int argc, char** argv) {
	(void) argc;
	string chaine = argv[1];

	inversement(chaine);
	cout << chaine << endl;
}

