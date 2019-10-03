#include <iostream>
#include <fstream>
#include <string>

using std::ifstream;
using std::cout;

int main(){
    // ifstream my_file ("/files/1.board");
    ifstream my_file;
    my_file.open("./files/1.board");
    
    // check if ifstream was successfully created
    // read line by line
    // print the lines to the screen
    if (my_file)
    {
        cout << "The file stream has been created !! \n";
        std::string line;
        while (getline(my_file, line))
        {
            cout << line << "\n";
        }
    }
    
}