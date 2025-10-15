// adresse.cpp
// Transcription de l'algorithme B de l'exercice 5.2 du TD 3.
// L. CHENEVAL - Oct. 2025
//
// Code habitation provenant du TP 3

#include <iostream>
#include <string>

using namespace std;

// ---
// Transcription de l'enregsitrement définissant une habitation.
struct Habitation {
	unsigned int num; // num > 0
	string comp, rue;
};

// ---
// Transcription de l'enregistrement définissant une adresse.
struct Adresse {
	Habitation lieu;
	unsigned int code;
	string ville;
};

// ---
// Procédure d'affichage d'une habitation hab passé en entrée.
void aff_hab(Habitation hab) {
	string comp = "";
	if (hab.comp != "") {
		comp = " " + hab.comp + " ";
	}

	cout << hab.num << comp << hab.rue << endl;
}

// ---
// Procédure d'affichage d'une adresse adr passé en entrée.
void aff_adr(Adresse adr) {
	string comp = " ";
	if (adr.lieu.comp != "") {
		comp = " " + adr.lieu.comp + " ";
	}

	cout << adr.lieu.num << comp << adr.lieu.rue << ", " << adr.code << " " << adr.ville << endl;
}

// ---
// Transcription procédure de l'exercice 5.2 du TD 3.
int main() {
	Adresse adr;
	aff_adr(adr);
	adr.lieu = {3, "", "Orion"};
	aff_adr(adr);
	adr.code = 44000 + 100 * adr.lieu.num;
	aff_adr(adr);
	adr.ville = "Nantes";
	aff_adr(adr);
}

