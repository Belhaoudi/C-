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

enum class State {kObstacle,kEmpty};

string CellString(State square){
    switch (square)
    {
    case State::kObstacle : return "⛰️";
        break;
    default: return "0";
        break;
    }
}

int main(){

}