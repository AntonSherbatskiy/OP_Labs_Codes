#include <iostream>

using namespace std;

int main(){
    cout << "Enter the length: ";

    double a;

    cin >> a;

    cout << "Side surface of the cube: " << 4 * a * a << endl
    << "Cube capacity: " << a * a * a << endl;

    system("pause");

    return 0;

}

