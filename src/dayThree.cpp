#include "dayThree.hpp"
bool is_symbol(char character);

int day_three(string file_path){
    
    return 0;
}

bool is_symbol(char character){
    const string symbols = {'!', '@', '#', '$', '%', '^', '&', '*', '/'};
    if(symbols.find(character) != string::npos){
        return 1;
    }
    return 0;
}
