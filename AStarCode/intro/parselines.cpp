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


void PrintBoard(vector<vector<int>> b){
    for(auto v : b){
        for(int i : v){
            cout << i;
        }
        cout << "\n";
    }
}


vector<vector<int>> Parseline(string path){
    string a;
    ifstream my_file;
    my_file.open(path);
    vector <vector<int>> v;
    if (my_file)
    {
        string line;
        while (getline(my_file,line))
        {
            istringstream my_stream(line);
            int a;
            char c;
            vector <int> test;
            while (my_stream >> a >> c)
            { 
                test.push_back(a); 
            }
            v.push_back(test);
        }
    }
    return v;
}


int main(){
    vector<vector<int>> a {Parseline("./files/1.board")};
    PrintBoard(a);
}