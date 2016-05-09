#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include <windows.h>
#include <sstream>
#include <iomanip>

using namespace std;

vector<string> loader();               // Returns vector of strings from "words.txt".
int hangman(vector<string>&, int);    // Executes one round of hangman. Returns win/loss bool.
void print_man(int);                   // Prints hangman graphics.
void print_vector(vector<string>);     // Prints contents of string vector.
void scoreboard(int);
void print_scoreboard();
void sort(vector<int> &, vector<string> &);