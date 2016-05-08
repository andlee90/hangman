#include "hangman.h"

int main(){

	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 6);

	int game_count = 0;
	bool repeat = true;
	string answer;
	string difficulty;
	string message = "Would you like to play a game of hangman? ";

	cout << "Loading word list...\n";
	// Set seed for random number generation
	srand(time(0));
	// Load up dictionary from "words.txt"
	vector<string> dictionary = loader();

	cout << "The list contains ";

	SetConsoleTextAttribute(hConsole, 2);
	cout << dictionary.size();
	SetConsoleTextAttribute(hConsole, 6);

	cout << " words.\n";
	cout << "Welcome. ";

	while (repeat){
		if (game_count > 0){
			message = "Would you like to play another game of hangman? ";
		}

		cout << message;    // COLOR:OFF
		cout << "(";
		SetConsoleTextAttribute(hConsole, 6);
		cout << "y";
		SetConsoleTextAttribute(hConsole, 6);
		cout << "/";
		SetConsoleTextAttribute(hConsole, 6);
		cout << "n";
		SetConsoleTextAttribute(hConsole, 6);
		cout << ")\n";
		cin >> answer;

		if (answer == "y" || answer == "Y"){
			game_count++;
			hangman(dictionary, 6);
			/*bool d_flag = false;
			while (!d_flag){

				cout << "Please select your difficulty:\n"
					<< "1. Easy\n2. Medium\n3. Hard\n";
				cin >> difficulty;

				if (difficulty == "1"){
					d_flag = true;
					hangman(dictionary, 6);
				}
				else if (difficulty == "2"){
					d_flag = true;
					hangman(dictionary, 6);
				}
				else if (difficulty == "3"){
					d_flag = true;
					hangman(dictionary, 6);
				}
				else {
					d_flag = false;
					cout << "Invalid selection.\n";
				}
			}*/
		}
		else if (answer == "n" || answer == "N"){
			repeat = false;
			string goodbye = "Goodbye!";

			for (int i = 0; i < 80; i++){
				SetConsoleTextAttribute(hConsole, i);
				goodbye = goodbye.insert(0,"         ");
				cout << goodbye << endl;
			}
		}
		else if (answer == "p"){
			print_vector(dictionary);
		}

		else{
			cout << "Invalid command.\n";
		}
	}
	
	return 0;
}
