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
	cout << "\nWelcome. ";

	// Until player selects no
	while (repeat){
		// Check if first round or not
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

		// If player chooses yes, (1) run hangman (2) print score
		// and, if player wins, (3) run scoreboard
		if (answer == "y" || answer == "Y" || answer == "yes" || answer == "Yes"){
			game_count++;
			int score = hangman(dictionary, 6); // RUN
			cout << "Your score was: ";
			if (score == 0){
				SetConsoleTextAttribute(hConsole, 4); // COLOR::RED
				cout << score << endl;
				SetConsoleTextAttribute(hConsole, 6); // COLOR::YELLOW
			}
			else{
				SetConsoleTextAttribute(hConsole, 2); // COLOR::GREEN
				cout << score << endl;
				SetConsoleTextAttribute(hConsole, 6); // COLOR::YELLOW
			}
			// Check whether game was won
			if (score > 0){
				scoreboard(score);
			}
		}
		else if (answer == "n" || answer == "N" || answer == "no" || answer == "No"){
			repeat = false;
			string goodbye = "Goodbye!";

			for (int i = 0; i < 80; i++){
				SetConsoleTextAttribute(hConsole, i); // COLOR::i
				goodbye = goodbye.insert(0,"         ");
				cout << goodbye << endl;
			}
		}
		// If player enters p, print contents of "words.txt"
		else if (answer == "p"){
			print_vector(dictionary);
		}
		// If player enters scores, print scoreboard
		else if (answer == "scores"){
			print_scoreboard();
			cout << "\n";
		}

		else{
			cout << "Invalid command.\n";
		}
	}
	
	return 0;
}
