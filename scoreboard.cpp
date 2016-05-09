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

	cout << "\nScoreboard: \n\n";

	string line;
	string name;
	int score;
	int size = 0;
	int counter = 0;

	ifstream in("scoreboard.txt");

	if (in.is_open()){
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

	sort(scores, scores_and_names);

	for (int i = 0; i < scores_and_names.size(); i++){

		string tmp;
		if (i >= 9){
			tmp = scores_and_names[i].substr(3, scores_and_names.size() - 1);
			cout << i + 1 << ". " << tmp << " " << setw(14 - tmp.size()) << scores[i] << "\n";
		}
		else{
			tmp = scores_and_names[i].substr(2, scores_and_names.size() - 1);
			cout << i + 1 << ". " << tmp << " " << setw(15 - tmp.size()) << scores[i] << "\n";
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