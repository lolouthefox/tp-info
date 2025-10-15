#include <iostream>
#include <string>
using namespace std;

int main() {
    bool ilPleut;
    bool ilVente;
    string reponse;

    cout << "Est-ce qu'il pleut? (oui/NON): ";
    cin >> reponse;

    if (reponse == "oui") {
        ilPleut = true;
    } else {
        ilPleut = false;
    }


    cout << "Est-ce qu'il vente? (oui/NON): ";
    cin >> reponse;
    if (reponse == "oui") {
        ilVente = true;
    } else {
        ilVente = false;
    }

    if (ilVente and ilPleut) {
        cout << "Prendre un imperméable :)" << endl;
    } else if (ilVente and not ilPleut) {
        cout << "Prendre un parapluie :)" << endl;
    } else {
        cout << "Ne rien prendre !" << endl;
    }
}