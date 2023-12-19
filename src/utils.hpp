#pragma once
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
vector<string> load_input(string file_path);
int find_char_in_string(string string_to_check, char char_key);
int extract_number_from_str(string string_src, int start_index);
int char_is_number(char a);


