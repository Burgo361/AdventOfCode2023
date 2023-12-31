#include "dayOne.hpp"

int day_one(string file_path){
    cout << "\nDay One Program Started";

    static int calib_sum = 0;
    static int calib_sum_p2 = 0;
    static int counter = 0;
    static vector<string> input_vector = load_input(file_path);
    if (input_vector.size() > 0){
        cout << "\nFile Loaded";
        cout << "\nSize: " << input_vector.size();
    } else {
        cout << "\nFile Empty";
        return 0;
    }
    cout << "\n";
    for(int i = 0; i < input_vector.size(); i++){
        vector<char> numbers_in_line = {};
        vector<int> index_of_number = {};
        for(int j = 0; j < input_vector[i].size(); j++){
            if(char_is_number(input_vector[i][j])){
                numbers_in_line.push_back((char)input_vector[i][j]); 
                index_of_number.push_back(j);
            }

        }

        sortNumbers(&numbers_in_line, &index_of_number);

        string temp = ""; 
        temp = temp + (char)numbers_in_line[0]; 
        temp = temp + (char)numbers_in_line[numbers_in_line.size()-1];
        calib_sum += stoi(temp);
        counter++;
    }
    
    cout << "\n";
    cout << "Part 1: ";
    cout << calib_sum;
    cout << "\n";
   
    for(int i = 0; i < input_vector.size(); i++){
        vector<char> numbers_in_line = {};
        vector<int> index_of_number = {};
        containsNumberWord(input_vector[i], &numbers_in_line, &index_of_number);
        for(int j = 0; j < input_vector[i].size(); j++){
            if(char_is_number(input_vector[i][j])){
                numbers_in_line.push_back((char)input_vector[i][j]); 
                index_of_number.push_back(j);
            }

        }

        sortNumbers(&numbers_in_line, &index_of_number);

        string temp = ""; 
        temp = temp + (char)numbers_in_line[0]; 
        temp = temp + (char)numbers_in_line[numbers_in_line.size()-1];
        calib_sum_p2 += stoi(temp);
        counter++;
    }
    
    cout << "\n";
    cout << "Part 2: ";
    cout << calib_sum_p2;
    cout << "\n";

    return 0;
}



void containsNumberWord(string line, vector<char> *numbers_in_line, vector<int> *index_of_number){
    static vector<string> numbers_string = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    static string numbers_char = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    for(int i = 0; i < 10; i++){
        static size_t found = line.find(numbers_string[i]);
        found = line.find(numbers_string[i]);
        if(found != string::npos){
            numbers_in_line->push_back(numbers_char[i]);
            index_of_number->push_back(line.find(numbers_string[i]));


            static size_t found2;
            found2 = line.rfind(numbers_string[i]);
            if(found2 != string::npos && found != found2){
                numbers_in_line->push_back(numbers_char[i]);
                index_of_number->push_back(found2);
            }
        }
        
        
    }

} 
void sortNumbers(vector<char> *numbers_in_line, vector<int> *index_of_number){
    quickSort(numbers_in_line, index_of_number, 0, numbers_in_line->size()-1); 
}
void quickSort(vector<char> *numbers_in_line, vector<int> *index_of_number, int left, int right){
    int pivot = partition(numbers_in_line, index_of_number, left, right);

    if(left < pivot -1){
        quickSort(numbers_in_line, index_of_number, left, pivot -1);
    }

    if(pivot + 1 < right){
        quickSort(numbers_in_line, index_of_number, pivot + 1, right);
    }
    return;
}

int partition(vector<char> *numbers_in_line, vector<int> *index_of_number, int left, int right){
    while(true){
        while(left < right && index_of_number[0][left]<index_of_number[0][right]){
            right--;
        }
        if(left<right){

            swapVectorChar(numbers_in_line, left, right);
            swapVectorInt(index_of_number, left, right);
            left++;
        }else{
            return left;
        }
        while(left < right && index_of_number[0][left]<index_of_number[0][right]){
            left++;
        }
        if(left < right){

            swapVectorChar(numbers_in_line, left, right);
            swapVectorInt(index_of_number, left, right);
            right--;
        }else{
            return right;
        }

    }
}

void swapVectorChar(vector<char> *vector_char, int a, int b){
    char temp = vector_char[0][a];
    vector_char[0][a] = vector_char[0][b];
    vector_char[0][b] = temp;
}
void swapVectorInt(vector<int> *vector_int, int a, int b){
    int temp = vector_int[0][a];
    vector_int[0][a] = vector_int[0][b];
    vector_int[0][b] = temp;
}
