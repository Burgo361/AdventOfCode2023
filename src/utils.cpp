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
