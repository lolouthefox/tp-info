// Sept. 2025 - L. CHENEVAL - LICENSE MIT
// Permet d'obtenir des statistiques sur des courses à pieds par exemple.
// Il suffit de rentrer la veuleur pour chaques tour.

#include <iostream>
using namespace std;

int main() {
	float input;
	int lap_nb = 0;
	float total = 0;
	float min_time = -1;
	float max_time = -1;

	cout << "Ecrire le temps pour chaques tours un par un. Utiliser -1 pour indiquer que vous avez fini." << endl;

	while (input != -1) {
		lap_nb += 1;
		// Demander à l'utilisateur le temps fait au tour.
		cout << "Tour " << lap_nb << ":";
		cin >> input;

		// Ne pas continuer la boucle si input est -1
		if (input == -1) {
			break;
		}

		total += input;
		
		// Valeur max
		if (input > max_time) {
			max_time = input;
		}

		// Valeur min
		if (min_time == -1 or min_time > input) {
			min_time = input;
		}
	}

	// Affichage des valeurs
	cout << endl << "Temps total: " << total << endl;
	cout << "Temps moyen: " << total / static_cast<float>(lap_nb - 1) << endl; // Static cast car lap_nb est un entier et on a besoin d'un réel
	cout << "Temps minimum: " << min_time << endl;
	cout << "Temps maximum: " << max_time << endl;

	return 0;
}
