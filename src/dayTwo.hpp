#pragma once
#include <iostream>
#include "utils.hpp"

struct game_round {
    int blue_cube;
    int green_cube;
    int red_cube;
};
vector<game_round> split_game_into_rounds(string game);


