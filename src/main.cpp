#include <iostream>
using namespace std;
#include "main.hpp"
int main(int argc, char *argv[]){
    if(argc !=3 ){
        cout << "Usage: <filename> day <number>\n" << argv[0];
        return -1;
    }
    string file_name = argv[1];
    int day_select = stoi(argv[2]);
    cout << "\n";
    cout << "Day: ";
    cout << day_select;
    cout << "\nProgram Start\n";
    switch(day_select){
        case 1: 
            dayOne(file_name);
            break;
        case 2:
            dayTwo(file_name);
            break;
        case 3:
            dayThree(file_name);
            break;
        default:
            cout << "\nInvalid Day Selection\n";
            return 0;
    }




    cout << "\nProgram End\n";
    return 0;
}
