#include "dayTwo.hpp"

int dayTwo(string file_path){
    static int max_red = 12;
    static int max_green = 13;
    static int max_blue =14;

    vector<string> input_vector = loadInput(file_path);
    if (input_vector.size() > 0){
        cout << "\nFile Loaded";
        cout << "\nSize: " << input_vector.size();
    } else {
        cout << "\nFile Empty";
        return 0;
    }
    
    int sum_of_game_ids = 0;
    int sum_of_game_minpowered = 0;
    for(int i = 0; i < input_vector.size(); i++){
        int first_whitespace_index = find_char_in_string(input_vector[i], ' ');
        if(charIsNumber(input_vector[i][first_whitespace_index+1])){
            int game_id = extract_number_from_str(input_vector[i], first_whitespace_index+1);
            if(input_vector[i].find(";")){
                vector<game_round> game_rounds = split_game_into_rounds(input_vector[i]);
                int highest_blue = 0;
                int highest_green = 0;
                int highest_red = 0;
                for(int j = 0; j < game_rounds.size(); j++){
                    if(game_rounds[j].red_cube > highest_red){
                        highest_red = game_rounds[j].red_cube;
                        game_rounds[j].red_cube = highest_red;
                    }
                    if(game_rounds[j].green_cube > highest_green){
                        highest_green = game_rounds[j].green_cube;
                        game_rounds[j].green_cube = highest_green;
                    }
                    if(game_rounds[j].blue_cube > highest_blue){
                        highest_blue = game_rounds[j].blue_cube;
                        game_rounds[j].blue_cube = highest_blue;
                    }
                }
                if(highest_blue <= max_blue && highest_green <= max_green && highest_red <= max_red){
                    sum_of_game_ids += game_id;
                }
                sum_of_game_minpowered += (highest_green * highest_red * highest_blue);
            }
        }
    }
    cout << sum_of_game_ids;
    cout << "\nPart 2: " << sum_of_game_minpowered;
    return 0;
}

vector<game_round> split_game_into_rounds(string game){
    vector<game_round> game_rounds;
    static string game_string;
    static game_round game_round;
    static string round_string;
    static bool last_round;

    if(game.find(":")) {
        last_round = 0;
        game_string = game.substr(game.find(":")+2, game.size());
        while(true){
            if(game_string.find(";")!= string::npos) {
                round_string = game_string.substr(0, game_string.find(";"));
                game_string = game_string.substr(game_string.find(";")+2, game_string.size());
            } else {
                round_string = game_string;
                last_round = true;
            }

            if(round_string.find("blue") != string::npos){
                int number_index = round_string.find("blue")-2;
                if(charIsNumber(round_string[number_index-1])){
                    string temp;
                    temp += round_string[number_index-1];
                    temp += round_string[number_index];
                    int number = stoi(temp);
                    game_round.blue_cube = number; 
                } else {
                    string temp;
                    temp += round_string[number_index];
                    int number = stoi(temp);
                    game_round.blue_cube = number;
                }
            } else {
                game_round.blue_cube = 0;
            }
            if(round_string.find("green") != string::npos){
                 int number_index = round_string.find("green")-2;
                if(charIsNumber(round_string[number_index-1])){
                    string temp;
                    temp += round_string[number_index-1];
                    temp += round_string[number_index];
                    int number = stoi(temp);
                    game_round.green_cube = number;
                } else {
                    string temp;
                    temp += round_string[number_index];
                    int number = stoi(temp);
                    game_round.green_cube = number;
                }           
            } else {
                game_round.green_cube = 0;
            }
            if(round_string.find("red") != string::npos){
                int number_index = round_string.find("red")-2;
                if(charIsNumber(round_string[number_index-1])){
                    string temp;
                    temp += round_string[number_index-1];
                    temp += round_string[number_index];
                    int number = stoi(temp);
                    game_round.red_cube = number;
                } else {
                    string temp;
                    temp += round_string[number_index];
                    int number = stoi(temp);
                    game_round.red_cube = number;
                }          
            } else {
                game_round.red_cube = 0;
            }
            game_rounds.push_back(game_round);
            if(last_round) {
                break;
            }
        }
    }


    return game_rounds;
}

