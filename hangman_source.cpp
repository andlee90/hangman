#include "hangman.h"

int main(){

	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 6);

	int game_count = 0;
	bool repeat = true;
	string answer;
	string difficulty;
	string message = "\nWould you like to play a game of hangman? ";

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
	cout << "\nWelcome. ";

	// Until user selects no.
	while (repeat){
		// Check if first game or not.
		if (game_count > 0){
			message = "\nWould you like to play another game of hangman? ";
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
		cout << ") (enter 'scores' to view scoreboard)\n";
		cin >> answer;

		// If player chooses yes, run hangman. Print score. If player wins, run scoreboard.
		if (answer == "y" || answer == "Y" || answer == "yes" || answer == "Yes"){
			game_count++;
			int score = hangman(dictionary, 6);
			cout << "Your score was: ";
			if (score == 0){
				SetConsoleTextAttribute(hConsole, 4);
				cout << score << endl;
				SetConsoleTextAttribute(hConsole, 6);
			}
			else{
				SetConsoleTextAttribute(hConsole, 2);
				cout << score << endl;
				SetConsoleTextAttribute(hConsole, 6);
			}

			if (score > 0){
				scoreboard(score);
			}
		}
		// If player chooses no, exit game.
		else if (answer == "n" || answer == "N" || answer == "no" || answer == "No"){
			repeat = false;
			string goodbye = "Goodbye!";

			for (int i = 0; i < 80; i++){
				SetConsoleTextAttribute(hConsole, i);
				goodbye = goodbye.insert(0,"         ");
				cout << goodbye << endl;
			}
		}
		// If player chooses p, print contents of "words.txt"
		else if (answer == "p"){
			print_vector(dictionary);
		}
		// If player chooses scores, print out scoreboard.
		else if (answer == "scores"){
			print_scoreboard();
		}
		// Else show error.
		else{
			cout << "Invalid command.\n";
		}
	}
	
	return 0;
}
