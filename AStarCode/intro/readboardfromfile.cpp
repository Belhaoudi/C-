#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using std::ifstream;
using std::cout;
using std::vector;
using std::string;

void ReadBoardFile(string path){
    ifstream my_file (path);
    if (my_file)
    {
        cout << "Reading board from a file \n";
        string line;
        while (getline(my_file, line))
        {
            cout << line << "\n";
        }
    }
    
}


void PrintBoard(vector<vector<int>> b){
    cout << "printing board from a local vector \n";
    for(auto v : b){
        for(int i : v){
            cout << i;
        }
        cout << "\n";
    }
}

int main()
{
    vector<vector<int>> board = {{0, 1, 0, 0, 0, 0},
                                 {0, 1, 0, 0, 0, 0},
                                 {0, 1, 0, 0, 0, 0},
                                 {0, 1, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 1, 0}};

    PrintBoard(board);
    ReadBoardFile("./files/1.board");
}