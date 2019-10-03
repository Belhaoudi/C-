#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using std::ifstream;
using std::cout;
using std::vector;
using std::string;
using std::istringstream;

enum class State {kEmpty, kObstacle};

string CellString(State square){
    switch (square)
    {
    case State::kObstacle : return "/\\  ";
        break;
    default: return "0   ";
        break;
    }
}

void PrintBoard(vector<vector<State>> b){
    for(auto v : b){
        for(auto i : v){
            cout << CellString(i);
        }
        cout << "\n";
    }
}


vector<vector<State>> Parseline(string path){
    string a;
    ifstream my_file;
    my_file.open(path);
    vector <vector<State>> v;
    if (my_file)
    {
        string line;
        while (getline(my_file,line))
        {
            istringstream my_stream(line);
            int a;
            char c;
            vector <State> test;
            while (my_stream >> a >> c)
            { 
                if (a == 0)
                {
                    test.push_back(State::kEmpty);
                }else
                {
                    test.push_back(State::kObstacle);
                }  
            }
            v.push_back(test);
        }
    }
    return v;
}


int main(){
    vector<vector<State>> a {Parseline("./files/1.board")};
    PrintBoard(a);
}