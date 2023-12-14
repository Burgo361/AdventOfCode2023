#pragma once
#include <iostream>
#include <vector>
using namespace std;
vector<string> loadInput(string file_path);
int charIsNumber(char a);
int find_char_in_string(string string_to_check, char char_key);
int extract_number_from_str(string string_src, int start_index);
struct game_round {
    int blue_cube;
    int green_cube;
    int red_cube;
};
vector<game_round> split_game_into_rounds(string game);


