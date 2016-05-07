#include "hangman.h"


void print_vector(vector<string> v){

	cout << "The current dictionary contains:\n";

	// Print each element.
	for (int i = 0; i < v.size(); i++){
		cout << v[i] << "\n";
	}

	cout << "\n";
}

vector<string> loader(){

	vector<string> v;
	string line;
	ifstream in ("words.txt");

	if (in.is_open()){
		while (getline(in, line)){
			// Check for string length
			if (line.size() > 5){
				v.push_back(line);
			}
		}

		in.close();
	}
	else{
		cout << "ERROR: File I/O\n";
	}

	return v;
}

bool hangman(vector<string> &v, int difficulty){

	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	char blue[] = { 0x1b, '[', '1', ';', '3', '4', 'm', 0 };
	char normal[] = { 0x1b, '[', '0', ';', '3', '9', 'm', 0 };

	int incorrect_count = 0;
	int correct_count = 0; 
	int random_number = rand() % v.size();

	string word = v[random_number];
	string word_so_far;

	char letter;
	vector<char> incorrect_guesses;

	// Create blank word.
	for (int i = 0; i < word.size(); i++){
		word_so_far.append("_");
	}

	cout << "Your word is ";
	SetConsoleTextAttribute(hConsole, 2);
	cout << word.size();
	SetConsoleTextAttribute(hConsole, 6);
	cout << " characters long.\n";
	
	// Until all letters have been correctly guessed.
	while (correct_count < word.size())
	{
		bool flag = false;
		bool has_guessed = false;

		cout << "Your word so far is ";
		SetConsoleTextAttribute(hConsole, 7);
		cout << word_so_far;
		SetConsoleTextAttribute(hConsole, 6);
		cout << ".\n";
		cout << "You have added ";
		SetConsoleTextAttribute(hConsole, 4);
		cout << incorrect_count;
		SetConsoleTextAttribute(hConsole, 6);
		cout << "/6 parts to your man.\n";
		SetConsoleTextAttribute(hConsole, 7);
		print_man(incorrect_count);
		SetConsoleTextAttribute(hConsole, 6);
		cout << "Guess a letter!\n";

		cin >> letter;

		// Check if correct letter has already been guessed.
		for (int i = 0; i < word.size(); i++){
			if (letter == word_so_far[i]){
				has_guessed = true;
			}
		}

		// Check if incorrect letter has already been guessed.
		for (int i = 0; i < incorrect_guesses.size(); i++){
			if (letter == incorrect_guesses[i]){
				has_guessed = true;
			}
		}
		
		// If letter hasn't previously been guessed.
		if (!has_guessed){
			for (int i = 0; i < word.size(); i++){
				// If letter is correct
				if (letter == word[i]){
					word_so_far[i] = letter;
					correct_count++;
					flag = true;
				}
				else {
					incorrect_guesses.push_back(letter);
				}
			}

			if (flag == true){
				cout << "Nice! You've found " << correct_count << " of " << word.size() << endl;

				if (correct_count == word.size()){
					cout << "Congrats! You saved the man! Your word was " << word << ".\n";
				}
			}
			else{
				incorrect_count++;
				cout << "Sorry, that letter is not in your word. You've found " << correct_count << " of " << word.size() << endl;
			}

			if (incorrect_count == difficulty){
				correct_count = word.size();
				print_man(incorrect_count);
				cout << "Sorry, you've been hanged! Your word was " << word << ".\n";
			}
		}
		else{
			cout << "You've already guessed the letter " << letter << "!\n";
			has_guessed = false;
		}
	}

	return true;
}

void print_man(int n){

	string a = "   __________\n";
	string b = "   |        |\n";
	string c = "   |\n";
	string d = "   |\n";
	string e = "   |\n";
	string f = "   |\n";
	string g = "________\n";

	switch (n){
		case 1: c = "   |       ()\n";
				break;
		case 2: c = "   |       ()\n",
			    d = "   |       ||\n";
				break;
		case 3: c = "   |       ()\n",
			    d = "   |      /||\n";
				break;
		case 4: c = "   |       ()\n",
			    d = "   |      /||\\\n";
				break;
		case 5: c = "   |       ()\n",
			    d = "   |      /||\\\n",
				e = "   |       /\n";
				break;
		case 6: c = "   |       ()\n",
				d = "   |      /||\\\n",
		        e = "   |       /\\\n";
			    break;
	}
	cout << a << b << c << d << e << f << g << endl;
}
