#include <iostream>
#include <vector>

using std::cout;
using std::vector;

int main(){
    // Iterating over a container
    vector <int> a {1,2,19,4};
    for(int i : a){
        cout << i << "\n";
    }

    //Iterating over a 2d vector:
    vector <vector<int>> b {{1,2},
                            {3,4},
                            {5,6}};
    for(auto v : b){ //variable w/o a type
        for(int i : v){
            cout << i << "-";
        }
        cout << "\n";
    }
}