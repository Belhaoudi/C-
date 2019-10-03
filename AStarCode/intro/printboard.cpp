#include <iostream>
#include <vector>

using std::cout;
using std::vector;

void PrintBoard(vector<vector<int>> b){
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
}