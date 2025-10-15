// des_chaines.cpp
// L. CHENEVAL - Oct. 2025
// Transcription de l'algoritmes des_chaines de l'exercice 6.1.

#include <iostream>
using namespace std;

// ---
// Définition de la taille de la liste de mots.
const size_t N = 10;

// ---
// Transcription du type Phrase.
struct Phrase {
	unsigned int nb_mots;
	string mots[N];
};

// ---
// Transcription de l'algorithme du TD. Affiche le texte "Bien le Bonjour".
int main() {
	Phrase msg;
	unsigned int pos;
	
	msg.nb_mots = 3;
	msg.mots[1] = "B";
	msg.mots[3] = msg.mots[1] + "onjour";
	msg.mots[2] = "le";
	msg.mots[4] = "madame";
	msg.mots[1] = msg.mots[1] + "ien";
	for (pos = 1; pos <= msg.nb_mots + 1; pos++) {
		cout << msg.mots[pos] << " ";
	}
	cout << endl;
}
