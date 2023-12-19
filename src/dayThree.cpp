#include "dayThree.hpp"


bool is_symbol(char character);
struct number_set {
    int number_value = 0;
    int x = 0;
    int y = 0;
    int width = 1;
};

struct symbol {
    char symbol_value = ' ';
    int x = 0;
    int y = 0;
};

bool is_near_symbol(number_set number_set, vector<symbol> symbols);
int gear_check(symbol asterix, vector<number_set> numbers);

static vector<number_set> number_sets ={};
static vector<symbol> symbols= {};

int day_three(string file_path){
     vector<string> input_vector = load_input(file_path);
    if (input_vector.size() > 0){
        cout << "\nFile Loaded";
        cout << "\nSize: " << input_vector.size();
    } else {
        cout << "\nFile Empty";
        return 0;
    }   
    int number_of_symbols = 0;
    string current_line;
    int part1sum = 0;
    for(int i = 0; i < input_vector.size(); i++){
        current_line = input_vector[i];
        for(int j = 0; j < current_line.size(); j++){
            if(char_is_number(current_line[j])){
                number_set number;
                number.number_value = extract_number_from_str(current_line, j);
                number.x = j;
                number.y = i;
                while(char_is_number(current_line[j + 1])){
                    number.width++;
                    j++;
                }
                number_sets.push_back(number);
            }
            if(char_is_symbol(current_line[j])){
                symbol symbol;
                symbol.symbol_value = current_line[j];
                symbol.x = j;
                symbol.y = i;

                symbols.push_back(symbol);
            }
        }
    }
    cout << "\nNumber Sets: " << number_sets.size();
    cout << "\nSymbols: " << symbols.size();
    static int d3p1_total =0;
    for(int i = 0; i < number_sets.size(); i++){
        if(is_near_symbol(number_sets[i], symbols)){
            d3p1_total += number_sets[i].number_value;
        }
    }
    cout << "\n";
    cout << d3p1_total;
    cout << "\n";
    static int d3p2_total = 0;
    for(int i = 0; i < number_sets.size(); i ++){
        if(symbols[i].symbol_value == '*'){
            d3p2_total += gear_check(symbols[i], number_sets);
        }
    }
    cout << "\n";
    cout << d3p2_total;
    cout << "\n";
    return 0;
}

int gear_check(symbol asterix, vector<number_set> numbers){
    vector<int> valid_numbers = {};
    int asterix_left_x = asterix.x;
    int asteric_right_x = asterix.x + 1;
    for(int i = 0; i < numbers.size(); i++){
        if(asterix.y - 1 <= numbers[i].y && 
                asterix.y + 1 >= numbers[i].y){
            if(asterix_left_x <= numbers[i].x + numbers[i].width &&
                    asteric_right_x >= numbers[i].x){
                valid_numbers.push_back(numbers[i].number_value);
            }
        }
    }
    if(valid_numbers.size() > 1){
        return valid_numbers[0] * valid_numbers[1];
    }
    return 0; 
}

bool is_near_symbol(number_set number_set, vector<symbol> symbols){
    int num_left_bound = number_set.x - 1;
    int num_right_bound = number_set.x + number_set.width;
    for(int i = 0; i < symbols.size(); i++){
        if(number_set.y >= symbols[i].y - 1 && 
                number_set.y <= symbols[i].y + 1){
            if(num_right_bound >= symbols[i].x &&
                    num_left_bound <= symbols[i].x){
                return 1;
            }
        }
    }
    return 0;
}


bool char_is_symbol(char character){
    static string symbols = {
        '!', '@', '#', '$', '%', '^', '&', '*', '/', '-', '=', '+'
    };
    if(symbols.find(character) != string::npos){
        return 1;
    }
    return 0;
}
