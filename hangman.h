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

// hangman.cpp
vector<string> loader();                      // Returns vector of strings from "words.txt".
int hangman(vector<string>&, int);            // Executes one round of hangman. Returns win/loss bool.
void print_man(int);                          // Prints hangman graphics.
void print_vector(vector<string>);            // Prints contents of string vector.

// scoreboard.cpp
void scoreboard(int);                         // Adds game record to "scoreboard.txt"
void print_scoreboard();                      // Prints sorted contents of "scoreboard.txt"
void sort(vector<int> &, vector<string> &);   // Bubble sorts vectors containing parsed values from "scoreboard.txt"