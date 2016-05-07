#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include <windows.h>

using namespace std;

vector<string> loader();               // Returns vector of strings from "words.txt".
bool hangman(vector<string>&, int);    // Executes one round of hangman. Returns win/loss bool.
void print_man(int);                   // Prints hangman graphics.
void print_vector(vector<string>);     // Prints contents of string vector.