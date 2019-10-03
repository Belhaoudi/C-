// focus on istringstream
// uses <sstream> header file
#include <iostream>
#include <string>
#include <sstream>

using std::istringstream;
using std::string;
using std::cout;

int main(){
    string a{"1 2 3"};
    istringstream my_stream(a);

    int n;

    while (my_stream) {
        my_stream >> n;
        // Extraction operator >> writes the stream to the variable on the right of the operator and returns istringstream object
        if (my_stream) {
            cout << "That stream was successful: " << n << "\n";
        }
        else {
            cout << "That stream was NOT successful!" << "\n";            
        }
    }



    //If string has mixed types, more care is needed in extraction
    string b{"1,2,3"};

    istringstream my_stream2(b);

    char c;
    int m;

    while (my_stream2 >> n >> c)
    {
        cout << "Stream successful " << n << " " << c << "\n";
    }
    cout << "failure";
    //in this case, we stream to an int then a char
    //this will fail before printing the 3 because it has to have both parts of the stream to evaluate to true (and there is no char after final 3)
}