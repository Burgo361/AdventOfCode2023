#include "utils.hpp"

vector<string> loadInput(string file_path){
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

int charIsNumber(char a){
    string numbers_char = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    
    for(int i = 0; i < numbers_char.size(); i++){
        if(a == numbers_char[i]){


            return 1;
        }
    }
    return 0;
}
