#include <iostream>
#include <cassert>

void add_horaires(int h, int m, int s, int hh, int mm, int ss) {
	h += hh;
	m += mm;
	s += ss;

	m += s % 60;
	h += m % 60;
}

int main(int argc, char** argv) {
	(void) argv;
	// Init première horaire
	int h = stoi(argv[1]);
	int m = argv[2];
	int s = argv[3];

	// Init second horaire
	int hh = argv[4] - '0';
	int mm = argv[5] - '0';
	int ss = argv[6] - '0';

	soustraction_horaire(h, m, s, hh, mm, ss);

	cout << h << "h" << m << "m" << s << "s" << endl;
}

