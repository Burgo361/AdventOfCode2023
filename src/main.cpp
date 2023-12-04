#include <iostream>
using namespace std;
#include "main.hpp"
int main(int argc, char *argv[]){
    if(argc !=2 ){
        cout << "Usage: <filename>\n" << argv[0];
        return -1;
    }
    string file_name = argv [1];
    cout << "\nProgram Start\n";
    dayOne(file_name);
    dayTwo(file_name);




    cout << "\nProgram End\n";
    return 0;
}
