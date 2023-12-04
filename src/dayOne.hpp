#pragma once
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int dayOne(string file_path);
vector<string> loadInput(string file_path);
int charIsNumber(char a);
void containsNumberWord(string line, vector<char> *numbers_in_line, vector<int> *index_of_number);
void sortNumbers(vector<char> *numbers_in_line, vector<int> *index_of_number);
void quickSort(vector<char> *numbers_in_line, vector<int> *index_of_number, int left, int right);
int partition(vector<char> *numbers_in_line, vector<int> *index_of_number, int left, int right);
void swapVectorChar(vector<char> *vector_char, int a, int b);
void swapVectorInt(vector<int> *vector_int, int a, int b);

