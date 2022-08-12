#include <iostream>
using namespace std;

int main () {

    enum Color {
        red,
        blue,
        green
    } color;

    cout << color << endl;

    color = green;

    cout << color << endl;

    enum Books {
        chinese,
        english = 3,
        japanese,
    } book = japanese;

    // book = japanese;

    cout << book << endl;

    // typedef
    typedef int myInt;
    myInt a = 123;

    

    return 0;
}