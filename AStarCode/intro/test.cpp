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

int main(){
    string a;
    ifstream my_file("./files/1.board");
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
    
    for (auto i : v)
    {
        for (int j : i)
        {
            cout << j ;
        }
        cout << "\n";
    }
    
}