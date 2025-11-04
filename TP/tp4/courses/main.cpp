// L. CHENEVAL - Oct. 2025 - courses/main.cpp
// Permet de gerer une liste de courses

#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

struct Article {
	bool checked;
	string name;
};

const unsigned int MAX_ARTICLES = 100;
const unsigned int MAX_CMD_SIZE = 10;
Article articles[MAX_ARTICLES];
unsigned int nb_articles = 0;

// ---
// Checks all items
void check_all(Article list[]) {
	for (unsigned int i = 0; i < nb_articles; i++) {
		list[i].checked = true;
	}
}

// ---
// Unchecks all items
void uncheck_all(Article list[]) {
	for (unsigned int i = 0; i < nb_articles; i++) {
		list[i].checked = false;
	}
}

// ---
// Shows the list using the special formatting
void show_list(Article list[]) {
	for (unsigned int i = 0; i < nb_articles; i++) {
		Article item = list[i];

		string check_indicator = " ";

		if (item.checked) {
			check_indicator = "X";
		}

		cout << i << " - " << "[" << check_indicator << "] " << item.name << endl;
	}
}

// ---
// Prompts the user to input the data
string prompt_cmd() {
	string prompt;
	cout << "> ";
	getline(cin, prompt);
	return prompt;
}

// ---
// Parse the prompt and executes the commands.
// Returns true if program should be exited.
bool handle_prompt(const string &prompt) {
	string arguments[MAX_CMD_SIZE];
	int nb_arguments = 0;
	string word;
	
	for (int i = 0; i < prompt.length(); i++) {
		if (prompt[i] == ' ') {
			arguments[nb_arguments] = word;
			word = "";
			nb_arguments += 1;
			continue;
		}
		word += prompt[i];
	}
	arguments[nb_arguments] = word;
	nb_arguments += 1;

	// Check for command
	if (arguments[0] == "q" or arguments[0] == "quit") {
		return true;
	}

	// Check an itemor all items
	if (arguments[0] == "check") {
		if (arguments[1] == "all") {
			check_all(articles);
		} else {
			int index = stoi(arguments[1]);
			if (index >= 0 && index < nb_articles) {
				articles[index].checked = true;
			} else {
				cout << "Error: Invalid index" << endl;
			}
		}
	}

	// Unchecks one or all items
	if (arguments[0] == "uncheck") {
		if (arguments[1] == "all") {
			uncheck_all(articles);
		} else {
			int index = stoi(arguments[1]);
			if (index >= 0 && index < nb_articles) {
				articles[index].checked = false;
			} else {
				cout << "Error: Invalid index" << endl;
			}
		}
	}

	// Add an item
	if (arguments[0] == "add") {
		string name;
		for (int i = 1; i < nb_arguments; i++) {
			if (i == nb_arguments - 1) {
				name += arguments[i];
			} else {
				name += arguments[i] + " ";
			}
		}
		articles[nb_articles] = { false, name };
		nb_articles += 1;
	}

	// Remove an item
	if (arguments[0] == "remove") {
		int index = stoi(arguments[1]);
		if (index >= 0 && index < nb_articles) {
			for (int i = index; i < nb_articles - 1; i++) {
				articles[i] = articles[i + 1];
			}
			nb_articles -= 1;
		} else {
			cout << "Error: Invalid index" << endl;
		}
	}

	// Rename an item
	if (arguments[0] == "rename") {
		const int index = stoi(arguments[1]);
		if (index >= 0 && index < nb_articles) {
			string name;
			for (int i = 2; i < nb_arguments; i++) {
				if (i == nb_arguments - 1) {
					name += arguments[i];
				} else {
					name += arguments[i] + " ";
				}
			}
			articles[index].name = name;
		} else {
			cout << "Error: Invalid index" << endl;
		}
	}

	// Deletes all items
	if (arguments[0] == "DELETEALL") {
		nb_articles = 0;
	}
	
	return false;
}

// ---
// Allows a user to manage a groceries list
int main() {
	nb_articles += 1;
	articles[0] = { false, "Jambon/Jamon/Ham/Wurst" };

	while (true) {
		// Show the list and prompt the user
		show_list(articles);
		string prompt = prompt_cmd();

		// Handle prompt and quit if needed.
		bool should_quit = handle_prompt(prompt);
		if (should_quit) {
			break;
		}

		// Clear the terminal and flush the iostream
		system("clear");
		cout << flush;
	}
}
