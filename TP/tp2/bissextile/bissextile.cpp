#include <iostream>
using namespace std;

int main() {
	int annee;
	cout << "Entrer année: ";
	cin >> annee;
	if ((annee % 4 == 0 and annee % 100 != 0) or annee % 400 == 0) {
		cout << "Année bissextile." << endl;
		return 1;
	}
	cout << "Année non bissextile." << endl;
	return 1;
}
