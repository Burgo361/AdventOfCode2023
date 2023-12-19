#include "utils.hpp"

vector<string> load_input(string file_path){
    vector<string> input_lines;
    ifstream input_file(file_path);
    cout << "\nFile: "<< file_path << "\n";
    cout << "\nChecking file... \n";
    if(!input_file.is_open()){
        cout<< "\nError opening file :" << file_path;
    } else {
        cout << "\nFile Opened";
        static std::string line; 
        while(std::getline(input_file, line)){
            input_lines.push_back(line);

        }
       
        input_file.close();
    }

    return input_lines;
}


int char_is_number(char a){
    if(a >= '0' && a <= '9'){
        return 1;
    }
    return 0;
}
int find_char_in_string(string string_to_check, char char_key){
    for(int i = 0; i < string_to_check.length(); i++){
        if(string_to_check[i] == ' '){
            return i;
        }
    }
    return -1;
}

int extract_number_from_str(string string_src, int start_index){
    string temp = "";
    int i = start_index;
    while(true){
        if(char_is_number(string_src[i])){
            temp += string_src[i];
        } else {
            break;
        }
        i++;
    }
    return stoi(temp);
}
