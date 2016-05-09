#include "hangman.h"

void scoreboard(int score){

	string line;
	string name;
	cout << "Enter your name: \n";
	cin >> name;

	fstream board("scoreboard.txt", std::ios_base::app);
	if (board.is_open()){
		board << "\n" << score << "_" << name;
		board.close();
	}
	else{
		cout << "ERROR: File I/O\n";
	}
}

void print_scoreboard(){

	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	cout << "\nScoreboard: \n\n";

	string line;
	string name;
	int score;
	int size = 0;
	int counter = 0;

	ifstream in("scoreboard.txt");
	if (in.is_open()){
		// Get size of vectors from scoreboard.txt
		while (getline(in, line)){
			size++;
		}
		in.close();
	}
	else{
		cout << "ERROR: File I/O\n";
	}

	in.open("scoreboard.txt");

	vector<string> scores_and_names(size);
	vector<int> scores(size);

	if (in.is_open()){
		// Get each line from scoreboard.txt
		while (getline(in, line)){
			scores_and_names[counter] = line;
			counter++;
		}
		in.close();
	}
	else{
		cout << "ERROR: File I/O\n";
	}

	in.open("scoreboard.txt");
	counter = 0;

	if (in.is_open()){
		// Get each score from scoreboard.txt
		while (getline(in, line)){

			stringstream ss;
			string tmp = line.substr(0, line.find("_"));

			ss << tmp;
			ss >> score;

			scores[counter] = score;
			counter++;
		}
		in.close();
	}
	else{
		cout << "ERROR: File I/O\n";
	}

	// Bubble sort the vectors
	sort(scores, scores_and_names);

	// Only print out first 20 entries
	int max_index;
	if (scores_and_names.size() <= 20){
		max_index = scores_and_names.size();
	}
	else{
		max_index = 20;
	}

	// Print scoreboard
	for (int i = 0; i < max_index; i++){

		string tmp;
		// Check if index has two digits
		if (i <= 8){
			// Check if score has two digits
			if (scores[i] <= 9){
				tmp = scores_and_names[i].substr(2, scores_and_names.size() - 1);
				cout << i + 1 << ". " << tmp << ":" << setw(25 - tmp.size());
				SetConsoleTextAttribute(hConsole, 2);
				cout << scores[i] << "\n";
				SetConsoleTextAttribute(hConsole, 6);
			}
			else{
				tmp = scores_and_names[i].substr(3, scores_and_names.size() - 1);
				cout << i + 1 << ". " << tmp << ":" << setw(25 - tmp.size()); 
				SetConsoleTextAttribute(hConsole, 2);
				cout << scores[i] << "\n";
				SetConsoleTextAttribute(hConsole, 6);
			}
		}
		else{
			tmp = scores_and_names[i].substr(2, scores_and_names.size() - 1);
			cout << i + 1 << ". " << tmp << ":" << setw(24 - tmp.size());
			SetConsoleTextAttribute(hConsole, 2);
			cout << score << endl;
			SetConsoleTextAttribute(hConsole, 6);
		}	
	}
}

void sort(vector<int> &scores, vector<string> &names)
{
	int n = scores.size();
	bool swap;
	int score_temp;
	string name_temp;

	do
	{
		swap = false;
		for (int i = 0; i < (n - 1); i++)
		{
			if (scores[i] < scores[i + 1])
			{
				score_temp = scores[i];
				scores[i] = scores[i + 1];
				scores[i + 1] = score_temp;

				name_temp = names[i];
				names[i] = names[i + 1];
				names[i + 1] = name_temp;

				swap = true;
			}
		}
	} while (swap);
}