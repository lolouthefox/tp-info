#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

struct Article {
	bool checked;
	string name;
};

const unsigned int MAX_ARTICLES = 100;
Article articles[MAX_ARTICLES];
unsigned int nb_articles = 0;


void check_all(Article list[]) {
	for (unsigned int i = 0; i < nb_articles; i++) {
		Article item = list[i];
		item.checked = true;
	}
}

void show_list(Article list[]) {
	for (unsigned int i = 0; i < nb_articles; i++) {
		Article item = list[i];

		string check_indicator = " ";

		if (item.checked) {
			check_indicator = "X";
		}

		cout << "[" << check_indicator << "] " << item.name << endl;
	}
}

string prompt_cmd() {
	string prompt = "";
	cout << "> ";
	cin >> prompt;
	return prompt;
}


int main() {
	nb_articles += 1;
	articles[0] = { false, "Cheese" };

	while (true) {
		show_list(articles);
		string prompt = prompt_cmd();
		if (prompt == "q") {
			break;
		}

		system("clear");
		cout << flush;
	}

	// cout << "Cheese on crackers" << endl;
	// system("clear");
	// cout << flush << "No cheese?! Blasphemy." << endl;
}

